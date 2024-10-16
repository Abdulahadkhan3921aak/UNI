#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Error: Stack is full\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl; // Output: 3
    cout << s.peek() << endl; // Output: 2
    cout << s.pop() << endl; // Output: 2
    cout << s.pop() << endl; // Output: 1
    cout << s.pop() << endl; // Output: Error: Stack is empty
    return 0;
}
