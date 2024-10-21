#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class TwoStacks {
private:
    int arr[MAX_SIZE];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = MAX_SIZE;
    }

    void push1(int data) {
        if (top1 < top2 - 1) {
            arr[++top1] = data;
            cout << "Element " << data << " pushed to Stack 1." << endl;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void push2(int data) {
        if (top1 < top2 - 1) {
            arr[--top2] = data;
            cout << "Element " << data << " pushed to Stack 2." << endl;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop1() {
        if (top1 >= 0) {
            int data = arr[top1--];
            cout << "Element " << data << " popped from Stack 1." << endl;
        } else {
            cout << "Stack 1 is empty!" << endl;
        }
    }

    void pop2() {
        if (top2 < MAX_SIZE) {
            int data = arr[top2++];
            cout << "Element " << data << " popped from Stack 2." << endl;
        } else {
            cout << "Stack 2 is empty!" << endl;
        }
    }

    void display1() {
        cout << "Stack 1: ";
        for (int i = top1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void display2() {
        cout << "Stack 2: ";
        for (int i = top2; i < MAX_SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void merge() {
        cout << "Merged Stack: ";
        for (int i = top1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        for (int i = top2; i < MAX_SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks stacks;

    stacks.push1(10);
    stacks.push2(20);
    stacks.push1(30);
    stacks.push2(40);

    stacks.display1();
    stacks.display2();

    stacks.pop1();
    stacks.pop2();

    stacks.display1();
    stacks.display2();

    stacks.merge();

    return 0;
}
