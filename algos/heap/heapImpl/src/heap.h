#define pragma
#include <iterator>
#include <vector>

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
    void adjustLastKey(RandomAccessIterator first, RandomAccessIterator last, const Compare comp = Compare())
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
    void adjustHeap(RandomAccessIterator first, const Distance parent, const Distance len, const Compare comp = Compare())
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
    void makeHeap(RandomAccessIterator first, RandomAccessIterator last, const Compare comp = Compare())
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
    using SizeType = typename Sequence::size_type;
    using ValueType = typename Sequence::value_type;
    using ConstReference = typename Sequence::const_reference;

    explicit Heap(const Sequence& sequence, const Compare& compare = Compare());
    explicit Heap(Sequence&& sequence, const Compare& compare = Compare());
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, const Sequence& sequence, const Compare& compare = Compare());
    template<typename InputIterator>
    Heap(InputIterator first, InputIterator last, Sequence&& sequence, const Compare& compare = Compare());

    bool empty() const;
    SizeType size() const;
    ConstReference top() const;
    void pop();
    void push(const ValueType& v);
    void push(ValueType&& v);

    /*
     A drawback of splitting this emplace function into declaration and definition
     is that the explicit template instantiation needs to be done in the implementation
     file. The presence of generic arguments "Args" makes it a bit tricky.
    */
    template<typename... Args>
    void emplace(Args&&... args)
    {
        m_sequence.emplace_back(std::forward<Args>(args)...);
        HeapUtils::adjustLastKey(m_sequence.begin(), m_sequence.end(), m_compare);
    }

    void swap(Heap<T, Sequence, Compare>& rhs);
    void print() const;

protected:
    Sequence m_sequence;
    Compare m_compare;
};
