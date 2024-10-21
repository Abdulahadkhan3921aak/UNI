#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void init(Stack& s) {
    s.top = -1;
}

bool isEmpty(Stack& s) {
    return s.top == -1;
}

bool isFull(Stack& s) {
    return s.top == MAX_SIZE - 1;
}

void push(Stack& s, int x) {
    if (isFull(s)) {
        cout << "Error: Stack is full\n";
        return;
    }
    s.top++;
    s.arr[s.top] = x;
}

int pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack is empty\n";
        return -1;
    }
    int x = s.arr[s.top];
    s.top--;
    return x;
}

int peek(Stack& s) {
    if (isEmpty(s)) {
        cout << "Error: Stack is empty\n";
        return -1;
    }
    return s.arr[s.top];
}

int main() {
    Stack s;
    init(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);

    cout << pop(s) << endl; // Output: 3
    cout << pop(s) << endl; // Output: 2

    push(s, 4);

    cout << peek(s) << endl; // Output: 4

    return 0;
}
