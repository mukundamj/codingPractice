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

    template<typename Distance>
    Distance parent(const Distance child)
    {
        return (child - 1)/2;
    }

    template<typename RandomAccessIterator, typename Compare = std::greater<typename std::iterator_traits<RandomAccessIterator>::value_type>>
    void adjustLastKey(RandomAccessIterator first, RandomAccessIterator last, const Compare comp = Compare{})
    {
        typedef typename std::iterator_traits<RandomAccessIterator>::difference_type DistanceType;

        DistanceType keyIndex = last - first - 1;

        while(keyIndex > 0 && comp(*(first + keyIndex), *(first + parent(keyIndex))))
        {
            std::swap(*(first + parent(keyIndex)), *(first + keyIndex));
            keyIndex = parent(keyIndex); 
        }
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
        typedef typename std::iterator_traits<RandomAccessIterator>::difference_type DistanceType;

        DistanceType len = last - first;

        if(len < 2) return;

        for(DistanceType parent = len/2; parent >= 0; parent--)
        {
            adjustHeap(first, parent, len, comp);
        }
    }

    template<typename RandomAccessIterator>
    void heapSort(RandomAccessIterator first, RandomAccessIterator last)
    {
        makeHeap(first, last);

        typedef typename std::iterator_traits<RandomAccessIterator>::difference_type DistanceType;
        DistanceType len = last - first;
          
        while(len > 1)
        {
            std::swap(*first, *(first + len--));
            adjustHeap(first, DistanceType(0), len);
        }
    }
}

template<typename T, typename Sequence = std::vector<T>, typename Compare = std::greater<T>>
class Heap {
public:
    using sizeType = Sequence::size_type;
    using valueType = Sequence::value_type;
    using constReference = Sequence::const_reference;

    explicit Heap(const Sequence& sequence, const Compare& compare);
    explicit Heap(Sequence&& sequence, const Compare& compare);
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, const Sequence& sequence, const Compare& compare); 
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, const Sequence&& sequence, const Compare& compare); 

    bool empty() const;
    sizeType size() const;
    constReference top() const;
    void pop();
    void push(const valueType& v);
    void push(valueType&& v);
    template<typename... Args>
    void emplace(Args&&... args);
    void swap(heap& rhs);

protected:
    Sequence m_sequence;
    Compare m_compare;
};
