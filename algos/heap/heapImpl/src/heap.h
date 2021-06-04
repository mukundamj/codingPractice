#define pragma
#include <iterator>

namespace HeapUtils {

    template<typename Distance>
    Distance leftChild(const Distance parent)
    {
        return 2*parent + 1;
    }

    template<typename Distance>
    Distance rightChild(const Distance parent)
    {
        return 2*parent + 2;
    }

    /*
      Since the declarations for the functions leftChild and rightChild are not included via  
      any header file it is important that are already defined before adjustHeap.
    */
    template<typename RandomAccessIterator, typename Distance, typename Compare = std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>>
    void adjustHeap(RandomAccessIterator first, const Distance parent, const Distance len, const Compare comp = Compare{})
    {
        Distance left = leftChild(parent);
        Distance right = rightChild(parent);
        Distance largest = parent;

        if(left < len && comp(*(first + left), *(first + parent)))
            largest = left;

        if(right < len && comp(*(first + right), *(first + largest)))
            largest = right;

        if(largest != parent)
        {
            std::swap(*(first + parent), *(first + largest));
            adjustHeap(first, largest, len, comp);
        }
    }

    /*
      Since the declaration for the function adjustHeap is not included via  
      any header file it is important it is already defined before makeHeap.
    */
    template<typename RandomAccessIterator, typename Compare = std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>>
    void makeHeap(RandomAccessIterator first, RandomAccessIterator last, const Compare comp = Compare{})
    {
        typedef typename std::iterator_traits<RandomAccessIterator>::value_type ValueType;
        typedef typename std::iterator_traits<RandomAccessIterator>::difference_type DistanceType;

        DistanceType len = last - first;

        if(len < 2) return;

        for(DistanceType parent = len/2; parent >= 0; parent--)
        {
            adjustHeap(first, parent, len, comp);
        }
    }
}

/*
If the declaration and definition of HeapUtils namespace is split into different files
then explicit instantiation for HeapUtils functions should be done as below.

template void HeapUtils::makeHeap<std::vector<int>::iterator, std::greater<std::vector<int>::value_type>>
    (std::vector<int>::iterator, std::vector<int>::iterator, std::greater<std::vector<int>::value_type>);

This becomes very cumbersome to manage if the client code uses many types of iterators. To avoid management of
explicit template instantiation of namespace functions it is better to do declaration and definition in the same file.
*/


/*
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
*/
