#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void insertAtStart(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }
    if (tail == nullptr)
        tail = head;
    head = newNode;
}

void printList()
{
    Node *temp = head;

    if (temp == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void reversePrintList()
{
    Node *temp = tail;

    if (temp == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "--------- Main Menu ---------" << endl;
        cout << "1. Insert at the start" << endl;
        cout << "2. Print the List" << endl;
        cout << "3. Reverse Print the List" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            int data;
            cin >> data;
            insertAtStart(data);
            break;

        case 2:
            printList();
            break;

        case 3:
            reversePrintList();
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
