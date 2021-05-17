#define pragma 
#include <iostream>

namespace HeapUtils {
    void make_heap(...)
    void heap_sort(...)
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::less<T>>
class Heap {
public:
    using size_type = Sequence::size_type;
    using value_type = Sequence::value_type;
    using const_reference = Sequence::const_reference;

    explicit Heap(const Compare& compare, const Sequence& sequence);
    explicit Heap(const Compare& compare, Sequence&& sequence);
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, const Compare& compare, const Sequence& sequence); 
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, const Compare& compare, Sequence&& sequence); 

    bool empty() const;
    size_type size() const;
    const_reference top() const;
    void push(const value_type& v);
    void push(value_type&& v);
    template<typename... Args>
    void emplace(Args&&... args);
    void pop();
    void swap(heap& rhs);
    //This operation will increase the value of the index to
    //the new value. The assumption is that the value is greater
    //than the current value of the index
    void increaseKey(const int index, const int value);

protected:
    Sequence m_sequence;
    Compare m_compare;
};
