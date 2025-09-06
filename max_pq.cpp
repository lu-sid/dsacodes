#include <iostream>
using namespace std;

class MaxPriorityQueue {
    int arr[100];   // fixed size array
    int size;

public:
    MaxPriorityQueue() {
        size = 0;
    }

    // Insert element
    void insert(int x) {
        if (size == 100) {
            cout << "Queue overflow!\n";
            return;
        }
        arr[size++] = x;
    }

    // Find index of max element
    int getMaxIndex() {
        int maxIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    // Get max element
    int getMax() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[getMaxIndex()];
    }

    // Remove max element
    void removeMax() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        int maxIdx = getMaxIndex();
        for (int i = maxIdx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Display queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
       int temp[100];
       for(int i = 0; i < size; i++){
        temp[i] = arr[i] ;
       }
       for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(temp[i] < temp[j]){
                swap(temp[i], temp[j]) ;
            }
        }
       }
       for(int i = 0; i <size; i++){
        cout << temp[i] << " " ;
       }
       cout << endl ;
    }
};

int main() {
    MaxPriorityQueue pq;
    int choice, val;

    do {
        cout << "1. Insert\n2. Get Max\n3. Remove Max\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                pq.insert(val);
                break;
            case 2:
                cout << "Max element: " << pq.getMax() << endl;
                break;
            case 3:
                pq.removeMax();
                cout << "Max element removed.\n";
                break;
            case 4:
                cout << "Queue elements: ";
                pq.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}