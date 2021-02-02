#include <iostream>
#include <list>
#include <vector>

template<typename ValueType>
class Node
{
public:
    Node(int key, ValueType value) : m_pair(key, value) {}
    int Key() const { return m_pair.first; }
    ValueType Value() const { return m_pair.second; }
 
private:
    std::pair<int, ValueType> m_pair;
};

class HashTable
{
public:
    HashTable(size_t size);
    void Insert(const Node<std::string>& n);
    void Delete(const int key);
    bool Search(const int key) const;
    void Print() const;

private:
    size_t HashFunction(const int key) const;
    std::list<Node<std::string>>::const_iterator SearchListOfNodes(const int key) const;
    size_t m_numberOfBuckets;
    std::vector<std::list<Node<std::string>>> m_buckets;
};
