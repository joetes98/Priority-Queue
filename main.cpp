using namespace std;
#include "BinaryHeap.h"
#include <iostream>

int main() {
    // initialize an empty binary heap
    BinaryHeap<int> pQ(100);

    cout << "Enter positive integers (Enter -1 to exit): ";
    int i = 0;
    while (true) {
        cin >> i;
        if (i == -1) {
            break;
        }
        pQ.insert(i);
    }

    while (true) {
        cout << "Please enter a choice" << endl
             << "1: Insert an item into the queue" << endl
             << "2: Dequeue the highest priority item" << endl
             << "3: Print the items in the queue" << endl
             << "4: Exit" << endl;

             int menu;

             switch(menu) {
                case 1:
                    int i;
                    cout << "Please enter an item to insert: ";
                    cin >> i;
                    pQ.insert(i);
                    break;
                case 2:
                    try {
                        int min = pQ.deleteMin();
                        cout << min << " has been removed from the queue" << endl;
                    }
                    catch (const char* e) {
                        cout << e << endl;
                    }
                    break;
             }
    }
    return 0;
}