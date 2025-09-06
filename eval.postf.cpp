#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool empty() {
        return (top == -1);
    }
};

// Function to evaluate postfix expression
int evaluatePostfix(char expr[]) {
    Stack s;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == ' ') continue;   // skip spaces

        if (c >= '0' && c <= '9') {
            s.push(c - '0');   // convert char to int
        } else {
            int op2 = s.pop();
            int op1 = s.pop();
            int result;

            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    char expr[100];
    cout << "Enter postfix expression (single digits, space separated): ";
    cin.getline(expr, 100);

    int result = evaluatePostfix(expr);
    cout << "Result = " << result << endl;

    return 0;
}