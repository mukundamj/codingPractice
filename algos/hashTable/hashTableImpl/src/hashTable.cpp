#include "hashTable.h"

template<typename V>
HashTable<V>::HashTable(const std::size_t size)
    : m_buckets(size)
{
}

// In the STL implementation a rehashing is done if the load factor crosses a threshold.
// The following notes were copied from https://www.cplusplus.com
// The load factor is the ratio between the number of elements in the container (its size)
// and the number of buckets (bucket_count):
// load_factor = size / bucket_count
// 
// The load factor influences the probability of collision in the hash table
// (i.e., the probability of two elements being located in the same bucket).
// The container automatically increases the number of buckets to keep the load factor below
// a specific threshold (its max_load_factor), causing a rehash each time an expansion is needed.

template<typename V>
void HashTable<V>::Insert(const std::pair<int, V>& keyValuePair)
{
    auto key = keyValuePair.first;
    if (Search(key)) return;
    m_buckets[HashFunction(key)].push_back(keyValuePair);
}

template<typename V>
bool HashTable<V>::Search(const int key) const
{
    if (SearchListOfPairs(key) != m_buckets[HashFunction(key)].cend()) return true;
    return false;
}

template<typename V>
typename std::list<std::pair<int, V>>::const_iterator HashTable<V>::SearchListOfPairs(const int key) const
{
    for (auto it = m_buckets[HashFunction(key)].cbegin(); it != m_buckets[HashFunction(key)].cend(); it++)
    {
        if (key == it->first) return it;
    }

    return m_buckets[HashFunction(key)].cend();
}

template<typename V>
void HashTable<V>::Delete(const int key)
{
    auto it = SearchListOfPairs(key);
    if(it != m_buckets[HashFunction(key)].cend()) {
        m_buckets[HashFunction(key)].erase(it);
    }
}

template<typename V>
void HashTable<V>::Print() const
{
    for (int i = 0; i < m_buckets.size(); i++)
    {
        std::cout << i;

        for (auto it = m_buckets[i].cbegin(); it != m_buckets[i].cend(); it++)
        {
            std::cout << "->" << it->second;
        }

        std::cout << std::endl;
    }
}

// In the STL implementation HashFunction is more sophisticated. The HashFunction
// can take an int or string or any other key and could generate a hash value of type
// size_t. The modulus of this hash value w.r.t the bucket size of the hash table is
// calculated and returned.
template<typename V>
size_t HashTable<V>::HashFunction(const int key) const
{
    return key % m_buckets.size();
}

// Explicit instantiation of HashTable<std::string> to prevent linker errors
template class HashTable<std::string>;
