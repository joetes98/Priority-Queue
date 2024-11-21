#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

using namespace std;
#include <vector>

template <class Comparable>
class PriorityQueue {
    private:
        int theSize; // number of elements
        vector<Comparable> array;
        void buildHeap();
        void percolateDown(int hole);

    public:
        PriorityQueue(int capacity = 100);
        int getSize();
        void displayQueue();
        bool isEmpty() const;
        void insert(const Comparable& x);
        Comparable deleteMin();
        void makeEmpty();
};
#include "PriorityQueue.tpp"
#endif // PRIORITYQUEUE_H