#include <iostream>

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to reverse the doubly linked list using the swap algorithm
void reverseList(Node** head) {
    Node* temp = *head;
    while (temp != nullptr) {
        std::swap(temp->prev, temp->next);
        *head = temp;
        temp = temp->prev;
    }
}

int main() {
    Node* head = nullptr;

    // Inserting nodes into the doubly linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    std::cout << "Original Doubly Linked List: ";
    displayList(head);

    // Reversing the doubly linked list
    reverseList(&head);

    std::cout << "Reversed Doubly Linked List: ";
    displayList(head);

    return 0;
}
