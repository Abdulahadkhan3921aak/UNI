#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Element enqueued: " << value << std::endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        int value = temp->data;

        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;

        std::cout << "Element dequeued: " << value << std::endl;
    }
};

int main() {
    Queue queue;

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Dequeue elements
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
