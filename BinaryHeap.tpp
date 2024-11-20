#include "BinaryHeap.h"
#include <exception>
using namespace std;

// constructor
template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
: theSize(0)
{
    array.resize(capacity);
}


// internal method to percolate down in the heap
// hole is the index at which the percolate beings
template <class Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole) {
    int child;
    Comparable tmp = array[hole];

    for( ; hole*2 <= theSize; hole = child) {
        child = hole*2;
        if(child != theSize && array[child + 1] < array[child]) {
            child++;
        }
        if (array[child] < tmp) {
            array[hole] = array[child];
        }
        else {
            break;
        }
        array[hole] = tmp;
    }
}

// Establish heap-order property from an arbitrary
// arrange of items. Runs in linear time.
template <class Comparable>
void BinaryHeap<Comparable>::buildHeap() {
    for (int i = theSize / 2; i > 0; i--) {
        percolateDown(i);
    }
}

//checks if the Binary Heap contains any elements
template <class Comparable>
bool BinaryHeap<Comparable>::isEmpty() const {
    if (theSize == 0) {
        return true;
    }
    return false;
}

// insert item x into the priority queue, maintaining heap order.
// Duplicates are allowed.
template <class Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x) {
    array[0] = x; //initialize sentinel
    if (theSize + 1 == array.size()) {
        array.resize(array.size()*2 + 1);
    }

    // percolate up
    int hole = ++theSize;
    for ( ; x < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }
    array[hole] = x;
}

// remove the smallest item fron the priority queue
// throw exception
template <class Comparable>
Comparable BinaryHeap<Comparable>::deleteMin() {
    if (isEmpty()) {
        throw ("Queue is empty");
    }
    Comparable min = array[1];
    array[1] = array[theSize--];
    percolateDown(1);
    return min;
}

// deletes the min value in the heap
// until the heap is no longer empty
template <class Comparable>
void BinaryHeap<Comparable>::makeEmpty() {
    while (!isEmpty()) {
        deleteMin();
    }
}