#ifndef BINARYHEAP_H
#define BINARYHEAP_H

using namespace std;
#include <vector>

template <class Comparable>
class BinaryHeap {
    private:
        int theSize; // number of elements
        vector<Comparable> array;
        void buildHeap();
        void percolateDown(int hole);

    public:
        BinaryHeap(int capacity = 100);
        bool isEmpty() const;

        void insert(const Comparable& x);
        Comparable deleteMin();
        void makeEmpty();
};
#include "BinaryHeap.tpp"
#endif // BINARY_H