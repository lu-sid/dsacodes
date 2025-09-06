#include <iostream>
using namespace std;

class MinPriorityQueue {
    int arr[100], size;

public:
    MinPriorityQueue() {
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

    // Find index of min element
    int getMinIndex() {
        int minIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
        }
        return minIdx;
    }

    // Get min element
    int getMin() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[getMinIndex()];
    }

    // Remove min element
    void removeMin() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        int minIdx = getMinIndex();
        for (int i = minIdx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Display queue in ascending order
    void display() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        // Copy elements into temp array
        int temp[100];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        // Sort temp array in ascending order
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (temp[i] > temp[j]) {
                    swap(temp[i], temp[j]);
                }
            }
        }

        // Print sorted elements
        for (int i = 0; i < size; i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;
    int choice, val;

    do {
        cout << "1. Insert\n2. Get Min\n3. Remove Min\n4. Display (Min→Max)\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                pq.insert(val);
                break;
            case 2:
                cout << "Min element: " << pq.getMin() << endl;
                break;
            case 3:
                pq.removeMin();
                cout << "Min element removed.\n";
                break;
            case 4:
                cout << "Queue elements (Min→Max): ";
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
