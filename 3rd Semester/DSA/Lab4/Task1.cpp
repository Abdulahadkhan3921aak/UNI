#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *queue;
    int front;
    int rear;
    int maxSize;

public:
    CircularQueue(int size)
    {
        maxSize = size;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue()
    {
        delete[] queue;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == maxSize - 1) || (front == rear + 1);
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear = (rear + 1) % maxSize;
            }
            queue[rear] = data;
            cout << "Enqueued: " << data << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
        else
        {
            int data = queue[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % maxSize;
            }
            cout << "Dequeued: " << data << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue elements: ";
            int i = front;
            while (true)
            {
                cout << queue[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % maxSize;
            }
            cout << endl;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }
        else
        {
            cout << "Peeked element: " << queue[front] << endl;
            return queue[front];
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    int choice, data;
    while (true)
    {
        cout << "\nCircular Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> data;
            cq.enqueue(data);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cq.peek();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
