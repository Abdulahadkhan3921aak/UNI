#include <iostream>

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int search(int value)
    {
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.insert(50);

    int element = 30;
    int index = dll.search(element);
    if (index != -1)
    {
        std::cout << "Element " << element << " found at index " << index << std::endl;
    }
    else
    {
        std::cout << "Element " << element << " not found" << std::endl;
    }

    return 0;
}
