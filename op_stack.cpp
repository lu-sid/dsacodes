#include <iostream>
using namespace std;

#define MAX 5  // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

    public:
        Stack() { top = -1; }

        // Push operation
        void push(int x) {
            if (top == MAX - 1) {
                cout << "Stack Overflow! Cannot push " << x << endl;
            } else {
                arr[++top] = x;
                cout << x << " pushed into stack." << endl;
            }
        }

        // Pop operation
        void pop() {
            if (top == -1) {
                cout << "Stack Underflow! Cannot pop." << endl;
            } else {
                cout << arr[top--] << " popped from stack." << endl;
            }
        }

        // Display stack elements
        void display() {
            if (top == -1) {
                cout << "Stack is empty!" << endl;
            } else {
                cout << "Stack elements: ";
                for (int i = top; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        // Check if stack is empty
        bool empty() {
            return (top == -1);
        }

        // Return top element of stack
        void stacktop() {
            if (top == -1) {
                cout << "Stack is empty!" << endl;
            } 
            else {
                cout << "Top element is: " << arr[top] << endl;
            }
        }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Check Empty\n5. Stack Top\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                if (s.empty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 5:
                s.stacktop();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}