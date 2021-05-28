#include "hashTable.h"

template<typename V>
HashTable<V>::HashTable(std::size_t size)
: m_numberOfBuckets(size),
  m_buckets(size)
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
void HashTable<V>::Insert(const std::pair<int, V>& n)
{
    auto key = n.first;
    if (Search(key)) return;
    m_buckets[HashFunction(key)].push_back(n);
}

template<typename V>
bool HashTable<V>::Search(const int key) const
{
    if (SearchListOfNodes(key) != m_buckets[HashFunction(key)].cend()) return true;
    return false;
}

template<typename V>
typename std::list<std::pair<int, V>>::const_iterator HashTable<V>::SearchListOfNodes(const int key) const
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
    auto it = SearchListOfNodes(key);
    if(it != m_buckets[HashFunction(key)].cend()) {
        m_buckets[HashFunction(key)].erase(it);
    }
}

template<typename V>
void HashTable<V>::Print() const
{
    for (int i = 0; i < m_numberOfBuckets; i++)
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
    return key % m_numberOfBuckets;
}

int main()
{
    size_t hashTableSize = 5;
    HashTable<std::string> hashTable(hashTableSize);
    hashTable.Insert(std::make_pair(0, "zero"));
    hashTable.Insert(std::make_pair(1, "one"));
    hashTable.Insert(std::make_pair(2, "two"));
    hashTable.Insert(std::make_pair(3, "three"));
    hashTable.Insert(std::make_pair(4, "four"));
    hashTable.Insert(std::make_pair(5, "five"));
    hashTable.Insert(std::make_pair(6, "six"));
    hashTable.Insert(std::make_pair(7, "seven"));
    hashTable.Insert(std::make_pair(8, "eight"));
    hashTable.Insert(std::make_pair(9, "nine"));
    hashTable.Insert(std::make_pair(10, "ten"));
    hashTable.Insert(std::make_pair(12, "twelve"));
    hashTable.Insert(std::make_pair(14, "fourteen"));

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "This is how the hash table looks before any changes" << std::endl; 
    hashTable.Print();

    hashTable.Delete(10);
    hashTable.Delete(0);

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "After deleting 10 and 0" << std::endl; 
    hashTable.Print();

    hashTable.Insert(std::make_pair(10, "ten"));
    hashTable.Insert(std::make_pair(2, "two"));
    hashTable.Insert(std::make_pair(15, "fifteen"));

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "After adding 10, 2 and 15" << std::endl;
    hashTable.Print();

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "Is the node with 15 as the key present in the map? : " << hashTable.Search(15) << std::endl; 
    std::cout << "Is the node with 16 as the key present in the map? : " << hashTable.Search(16) << std::endl; 
}
