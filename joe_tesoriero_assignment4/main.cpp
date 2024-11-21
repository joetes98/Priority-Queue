using namespace std;
#include "PriorityQueue.h"
#include <iostream>

int main() {
    // initialize an empty binary heap
    PriorityQueue<int> pQ(100);

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
             << "4: Remove all items for the queue" << endl
             << "5: Check if the queue is empty" << endl
             << "6: Exit" << endl;

            int menu;
            cin >> menu;
            if (menu == 6) {
                break;
            }
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
                case 3:
                    pQ.displayQueue();
                    break;
                case 4:
                    pQ.makeEmpty();
                    cout << "Queue has been emptied" << endl;
                    break;
                case 5:
                    if (pQ.isEmpty()) {
                        cout << "The queue is empty" << endl;
                    }
                    else {
                        cout << "The queue is not empty" << endl;
                    }
                    break;
            }
    }
    return 0;
}