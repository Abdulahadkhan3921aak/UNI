#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        arr[rear] = data;
        cout << "Enqueued: " << data << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        int data = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Dequeued: " << data << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int count()
    {
        return (rear - front + 1);
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }
        cout << "Peeked element: " << arr[front] << endl;
        return arr[front];
    }
};

int main()
{
    Queue queue;
    int choice, data;

    while (true)
    {
        cout << "---------------------- MAIN MENU FOR QUEUE ----------------------" << endl;
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. Peek" << endl;
        cout << "7. QUIT" << endl;
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
            queue.display();
            break;
        case 4:
            cout << "Queue size: " << queue.count() << endl;
            break;
        case 5:
            if (queue.isEmpty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 6:
            queue.peek();
            break;
        case 7:
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
