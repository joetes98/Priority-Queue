#include "PriorityQueue.h"
#include <exception>
#include <iostream>
using namespace std;

// constructor
template <class Comparable>
PriorityQueue<Comparable>::PriorityQueue(int capacity)
: theSize(0)
{
    array.resize(capacity);
}

// returns the # of elements in the queue
template <class Comparable>
int PriorityQueue<Comparable>::getSize() {
    return theSize;
}

// prints out the contents of the queue
template <class Comparable>
void PriorityQueue<Comparable>::displayQueue() {
    for (int i = 1; i <= theSize; i++) {
        cout << array.at(i) << " ";
    }
    cout << endl;
}

// internal method to percolate down in the heap
// hole is the index at which the percolate beings
template <class Comparable>
void PriorityQueue<Comparable>::percolateDown( int hole ) {
    int child;
    Comparable tmp = array[ hole ];
    for( ; hole * 2 <= theSize; hole = child ) {
        child = hole * 2;
        if( child != theSize && array[child + 1] < array[child])
            child++;
        if( array[ child ] < tmp )
            array[ hole ] = array[ child ];
        else
            break;
    }
    array[ hole ] = tmp;
}

// Establish heap-order property from an arbitrary
// arrange of items. Runs in linear time.
template <class Comparable>
void PriorityQueue<Comparable>::buildHeap() {
    for (int i = theSize / 2; i > 0; i--) {
        percolateDown(i);
    }
}

//checks if the Binary Heap contains any elements
template <class Comparable>
bool PriorityQueue<Comparable>::isEmpty() const {
    if (theSize == 0) {
        return true;
    }
    return false;
}

// insert item x into the priority queue, maintaining heap order.
// Duplicates are allowed.
template <class Comparable>
void PriorityQueue<Comparable>::insert( const Comparable & x ) {
    array[ 0 ] = x; // initialize sentinel
    if( theSize + 1 == array.size( ) )
        array.resize( array.size( ) * 2 + 1 );
    // Percolate up
    int hole = ++theSize;
    for( ; x < array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

// remove the smallest item fron the priority queue
// throw exception
template <class Comparable>
Comparable PriorityQueue<Comparable>::deleteMin() {
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
void PriorityQueue<Comparable>::makeEmpty() {
    while (!isEmpty()) {
        deleteMin();
    }
}