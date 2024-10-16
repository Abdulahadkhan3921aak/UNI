#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
public:
    Stack() { top = NULL; }

    void push(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            exit(1);
        }

        Node *temp = top;
        int data = top->data;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() { return top == NULL; }

    int getMax()
    {
        int max = INT_MIN;
        Node *curr = top;
        while (curr != NULL)
        {
            if (curr->data > max)
            {
                max = curr->data;
            }
            curr = curr->next;
        }
        return max;
    }

    int getMin()
    {
        int min = INT_MAX;
        Node *curr = top;
        while (curr != NULL)
        {
            if (curr->data < min)
            {
                min = curr->data;
            }
            curr = curr->next;
        }
        return min;
    }

private:
    Node *top;
};

int main()
{
    Stack stack;

    // Push some elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Print the maximum and minimum values in the stack
    cout << "Maximum value in the stack: " << stack.getMax() << endl;
    cout << "Minimum value in the stack: " << stack.getMin() << endl;

    return 0;
}
