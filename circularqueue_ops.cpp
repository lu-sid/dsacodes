#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of Circular Queue

class CircularQueue {
    int arr[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Insert element into circular queue
    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) {  // First element insertion
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << value << " inserted into Circular Queue." << endl;
    }

    // Remove element from circular queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! No elements to remove." << endl;
            return;
        }
        cout << arr[front] << " removed from Circular Queue." << endl;
        if (front == rear) {  // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display elements of circular queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function
int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "1. Insert (Enqueue)" << endl;
        cout << "2. Remove (Dequeue)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
