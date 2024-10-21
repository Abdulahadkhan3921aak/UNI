#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks
{
private:
    stack<int> enqueueStack;
    stack<int> dequeueStack;

public:
    void enqueue(int data)
    {
        enqueueStack.push(data);
    }

    void transferToDequeueStack()
    {
        while (!enqueueStack.empty())
        {
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
    }

    void dequeue()
    {
        if (dequeueStack.empty())
        {
            if (enqueueStack.empty())
            {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return;
            }
            transferToDequeueStack();
        }
        int data = dequeueStack.top();
        dequeueStack.pop();
        cout << "Dequeued: " << data << endl;
    }

    void view()
    {
        if (dequeueStack.empty() && enqueueStack.empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        transferToDequeueStack();
        stack<int> tempStack = dequeueStack;
        cout << "Queue elements: ";
        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main()
{
    QueueUsingStacks queue;
    int choice, data;

    while (true)
    {
        cout << "---------------------- MAIN MENU FOR QUEUE ----------------------" << endl;
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. VIEW" << endl;
        cout << "4. QUIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            queue.enqueue(data);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.view();
            break;
        case 4:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
