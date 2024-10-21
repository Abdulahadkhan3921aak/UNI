#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

void swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node *start)
{
    int swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    if (start == nullptr)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head = new Node(64);
    head->next = new Node(34);
    head->next->prev = head;
    head->next->next = new Node(25);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(12);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(22);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(90);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    std::cout << "Unsorted list: ";
    printList(head);

    bubbleSort(head);

    std::cout << "Sorted list: ";
    printList(head);

    return 0;
}
