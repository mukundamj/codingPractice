#include "hashTable.h"

HashTable::HashTable(size_t size)
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

void HashTable::Insert(const Node<std::string>& n)
{
    if (Search(n.Key())) return;
    m_buckets[HashFunction(n.Key())].push_back(n);
}

void HashTable::Delete(const int key)
{
    auto it = SearchListOfNodes(key);
    if(it != m_buckets[HashFunction(key)].cend()) {
        m_buckets[HashFunction(key)].erase(it);
    }
}

bool HashTable::Search(const int key) const
{
    if (SearchListOfNodes(key) != m_buckets[HashFunction(key)].cend()) return true;
    return false;
}

void HashTable::Print() const
{
    for (int i = 0; i < m_numberOfBuckets; i++)
    {
        std::cout << i;

        for (auto it = m_buckets[i].cbegin(); it != m_buckets[i].cend(); it++)
        {
            std::cout << "->" << it->Value();
        }

        std::cout << std::endl;
    }
}

// In the STL implementation HashFunction is more sophisticated. The HashFunction
// can take an int or string or any other key and could generate a hash value of type
// size_t. The modulus of this hash value w.r.t the bucket size of the hash table is
// calculated and returned.
size_t HashTable::HashFunction(const int key) const
{
    return key % m_numberOfBuckets;
}

std::list<Node<std::string>>::const_iterator HashTable::SearchListOfNodes(const int key) const
{
    for (auto it = m_buckets[HashFunction(key)].cbegin(); it != m_buckets[HashFunction(key)].cend(); it++)
    {
        if (key == it->Key()) return it;
    }

    return m_buckets[HashFunction(key)].cend();
}

int main()
{
    size_t hashTableSize = 5;
    HashTable hashTable(hashTableSize);
    hashTable.Insert(Node<std::string>(0, "zero"));
    hashTable.Insert(Node<std::string>(1, "one"));
    hashTable.Insert(Node<std::string>(2, "two"));
    hashTable.Insert(Node<std::string>(3, "three"));
    hashTable.Insert(Node<std::string>(4, "four"));
    hashTable.Insert(Node<std::string>(5, "five"));
    hashTable.Insert(Node<std::string>(6, "six"));
    hashTable.Insert(Node<std::string>(7, "seven"));
    hashTable.Insert(Node<std::string>(8, "eight"));
    hashTable.Insert(Node<std::string>(9, "nine"));
    hashTable.Insert(Node<std::string>(10, "ten"));
    hashTable.Insert(Node<std::string>(12, "twelve"));
    hashTable.Insert(Node<std::string>(14, "fourteen"));

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "This is how the hash table looks before any changes" << std::endl; 
    hashTable.Print();

    hashTable.Delete(10);
    hashTable.Delete(0);

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "After deleting 10 and 0" << std::endl; 
    hashTable.Print();

    hashTable.Insert(Node<std::string>(10, "ten"));
    hashTable.Insert(Node<std::string>(2, "two"));
    hashTable.Insert(Node<std::string>(15, "fifteen"));

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "After adding 10, 2 and 15" << std::endl;
    hashTable.Print();

    std::cout << "\n===================================================\n" << std::endl; 
    std::cout << "Is the node with 15 as the key present in the map? : " << hashTable.Search(15) << std::endl; 
    std::cout << "Is the node with 16 as the key present in the map? : " << hashTable.Search(16) << std::endl; 
}
