#include <iostream>
#include <list>
#include <vector>

#pragma once

template<typename V>
class HashTable
{
public:
    HashTable(const size_t size = 0);
    void Insert(const std::pair<int, V>& keyValuePair);
    void Delete(const int key);
    bool Search(const int key) const;
    void Print() const;

private:
    size_t HashFunction(const int key) const;
    typename std::list<std::pair<int, V>>::const_iterator SearchListOfPairs(const int key) const;
    std::vector<std::list<std::pair<int, V>>> m_buckets;
};
