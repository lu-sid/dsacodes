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
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to remove." << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;
        front++;
    }

    // Display elements of queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Peek (front element)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Rear element
    void rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Rear element: " << arr[rear] << endl;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == SIZE - 1);
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
        cout << "3. Display Queue" << endl;
        cout << "4. Peek (Front Element)" << endl;
        cout << "5. Rear Element" << endl;
        cout << "6. Check if Queue is Empty" << endl;
        cout << "7. Check if Queue is Full" << endl;
        cout << "8. Exit" << endl;
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
                q.peek();
                break;
            case 5:
                q.rearElement();
                break;
            case 6:
                if (q.isEmpty()) cout << "Queue is empty." << endl;
                else cout << "Queue is not empty." << endl;
                break;
            case 7:
                if (q.isFull()) cout << "Queue is full." << endl;
                else cout << "Queue is not full." << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
