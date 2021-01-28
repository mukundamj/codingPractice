#include "hashTable.h"

HashTable::HashTable(size_t size)
: m_numberOfBuckets(size),
  m_buckets(size)
{
}

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
