#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Insert element into queue
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) front = 0; // First element insertion
        arr[++rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    // Remove element from queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No elements to remove." << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
    }

    // Display elements of queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Operations ---" << endl;
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
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
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
