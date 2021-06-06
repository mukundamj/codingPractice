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

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
explicit Heap<T,Sequence,Compare>::Heap(const Sequence& sequence, const Compare& compare)
    : m_sequence(sequence), m_compare(compare) 
{
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
explicit Heap<T,Sequence,Compare>::Heap(Sequence&& sequence, const Compare& compare)
    : m_sequence(std::move(sequence)), m_compare(compare)
{
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
template<typename InputIterator>
Heap<T,Sequence,Compare>::Heap(InputIterator first, InputIterator last, const Sequence& sequence, const Compare& compare)
    : m_sequence(sequence), m_compare(compare)
{
    m_sequence.insert(m_sequence.end(), first, last);
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
template<typename InputIterator>
Heap<T,Sequence,Compare>::Heap(InputIterator first, InputIterator last, Sequence&& sequence, const Compare& compare)
    : m_sequence(std::move(sequence)), m_compare(compare)
{
    m_sequence.insert(m_sequence.end(), first, last);
    HeapUtils::makeHeap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
bool Heap<T,Sequence,Compare>::empty() const
{
    return m_sequence.empty();
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
sizeType Heap<T,Sequence,Compare>::size() const
{
    return m_sequence.size();
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
constReference Heap<T,Sequence,Compare>::top() const
{
    assert(!empty());
    return m_sequence.front();
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
void Heap<T,Sequence,Compare>::pop()
{
    if(empty()) return;
    m_sequence.front() = m_sequence.back();
    m_sequence.pop_back();

    typedef typename std::iterator_traits<Sequence::iterator>::difference_type DistanceType;
    HeapUtils::adjustHeap(m_sequence.begin(), DistanceType(0), DistanceType(size()), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
void Heap<T,Sequence,Compare>::push(const valueType& v)
{
    m_sequence.push_back(v);
    HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
void Heap<T,Sequence,Compare>::push(valueType&& v);
{
    m_sequence.push_back(std::move(v));
    HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
template<typename... Args>
void Heap<T,Sequence,Compare>::emplace(Args&&... args)
{
    m_sequence.emplace_back(std::forward<Args>(args)...);
    HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
void Heap<T,Sequence,Compare>::swap(Heap& rhs);
{
    std::swap(m_sequence, rhs.m_sequence);
    std::swap(m_compare, rhs.m_compare);
}

// Explicit template instantiation
template class Heap<int>;
