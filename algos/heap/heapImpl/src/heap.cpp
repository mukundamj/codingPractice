#include <cassert>
#include <iostream>
#include <deque>
#include "heap.h"

/*
 If the declarations and definitions of HeapUtils namespace are split into different files (heap.h & heap.cpp)
 then the explicit instantiation for HeapUtils functions should be done as below after the definition of
 HeapUtils functions.

 template void HeapUtils::makeHeap<std::vector<int>::iterator, std::greater<std::vector<int>::value_type>>
 (std::vector<int>::iterator, std::vector<int>::iterator, std::greater<std::vector<int>::value_type>);

 This becomes very cumbersome to manage if the client code uses many types of iterators. To avoid management of
 explicit template instantiation of namespace functions it is better to do declaration and definition in the
 same file, in this case heap.h.
 */


/*
 Note that the default template parameters and defalut function parameters
 should not be specified in the definition, it should only be done at the
 declaration.
*/
template<typename T, typename Sequence, typename Compare>
Heap<T,Sequence,Compare>::Heap(const Sequence& sequence, const Compare& compare)
    : m_sequence(sequence), m_compare(compare) 
{
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence, typename Compare>
Heap<T,Sequence,Compare>::Heap(Sequence&& sequence, const Compare& compare)
    : m_sequence(std::move(sequence)), m_compare(compare)
{
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence, typename Compare>
bool Heap<T,Sequence,Compare>::empty() const
{
    return m_sequence.empty();
}

/*
 The definition of the the alias, SizeType, is done in the declarationf file. Hence it
 has to be accessed as a typename inside the Heap class while using it in the definition
 file. The same logic applies for ValueType and ConstReference. This is a side effect
 of splitting the declaration and definition. 
*/
template<typename T, typename Sequence, typename Compare>
typename Heap<T,Sequence,Compare>::SizeType Heap<T,Sequence,Compare>::size() const
{
    return m_sequence.size();
}

template<typename T, typename Sequence, typename Compare>
typename Heap<T,Sequence,Compare>::ConstReference Heap<T,Sequence,Compare>::top() const
{
    assert(!empty());
    return m_sequence.front();
}

template<typename T, typename Sequence, typename Compare>
void Heap<T,Sequence,Compare>::pop()
{
    if(empty()) return;
    m_sequence.front() = m_sequence.back();
    m_sequence.pop_back();

    typedef typename std::iterator_traits<typename Sequence::iterator>::difference_type DistanceType;
    HeapUtils::adjustHeap(m_sequence.begin(), DistanceType(0), DistanceType(size()), m_compare);
}

template<typename T, typename Sequence, typename Compare>
void Heap<T,Sequence,Compare>::push(const typename Heap<T,Sequence,Compare>::ValueType& v)
{
    m_sequence.push_back(v);
    HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence, typename Compare>
void Heap<T,Sequence,Compare>::push(typename Heap<T,Sequence,Compare>::ValueType&& v)
{
    m_sequence.push_back(std::move(v));
    HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence, typename Compare>
void Heap<T,Sequence,Compare>::swap(Heap<T,Sequence,Compare>& rhs)
{
    /*
     Eventhough rhs.m_sequence and rhs.m_compare are private members of rhs object,
     they can be accessed here because Heap<T,Sequence,Compare>::swap(...)
     is a member function of Heap class. 
    */
    std::swap(m_sequence, rhs.m_sequence);
    std::swap(m_compare, rhs.m_compare);
}

template<typename T, typename Sequence, typename Compare>
void Heap<T,Sequence,Compare>::print() const
{
    for(auto n : m_sequence)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// Explicit template instantiation
template class Heap<int>;
template class Heap<int, std::deque<int>>;
