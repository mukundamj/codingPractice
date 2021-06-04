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
template<typename T, typename Sequence = std::vector<T>, typename Compare = std::less<T>>
explicit Heap::Heap(const Compare& compare, const Sequence& sequence)
    : m_compare(compare), m_sequence(sequence)
{
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

explicit Heap::Heap(const Compare& compare, Sequence&& sequence)
    : m_compare(compare), m_sequence(std::move(sequence))
{
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename InputIterator>
Heap::Heap(InputIterator first, InputIterator last, const Compare& compare, const Sequence& sequence)
    : m_compare(compare), m_sequence(sequence)
{
    m_sequence.insert(m_sequence.end(), first, last);
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename InputIterator>
Heap::Heap(InputIterator first, InputIterator last, const Compare& compare, Sequence&& sequence)
    : m_compare(compare), m_sequence(std::move(sequence))
{
    m_sequence.insert(m_sequence.end(), first, last);
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

bool Heap::empty() const
{
    return m_sequence.empty();
}

size_type Heap::size() const
{
    return m_sequence.size();
}

const_reference Heap::top() const
{
    return m_sequence.first();
}

void Heap::push(const value_type& v)
{
    m_sequence.push_back(v);
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

void Heap::push(value_type&& v);
{
    m_sequence.push_back(std::move(v));
    std::make_heap(m_sequence.begin(), m_sequence.end(), m_compare);
}

template<typename... Args>
void Heap::emplace(Args&&... args)
{

}
    void pop();
    void swap(Heap& rhs);

*/
