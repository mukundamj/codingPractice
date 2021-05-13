#define pragma 
#include <iostream>

namespace heapUtils {
    void make_heap(...)
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::less<T>>
class heap {
public:
    using size_type = Sequence::size_type;
    using value_type = Sequence::value_type;
    using const_reference = Sequence::const_reference;

    explicit heap(const Compare& compare, const Sequence& sequence);
    explicit heap(const Compare& compare, Sequence&& sequence);
    template<typename InputIterator>
    heap(InputIterator begin, InputIterator end, const Compare& compare, const Sequence& sequence); 
    template<typename InputIterator>
    heap(InputIterator begin, InputIterator end, const Compare& compare, Sequence&& sequence); 

    bool empty() const;
    size_type size() const;
    const_reference top() const;
    void push(const value_type& v);
    void push(value_type&& v);
    template<typename... Args>
    void emplace(Args&&... args);
    void pop();
    void swap(heap& rhs);

protected:
    Sequence m_sequence;
    Compare m_compare;
};
