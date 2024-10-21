#include <iostream>

// Linked list node structure
struct Node {
    int data;
    Node* next;
};

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    // Base cases
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    Node* result = nullptr;

    // Recursively merge the two lists
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to split the linked list into two halves
void split(Node* head, Node** left, Node** right) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

// Merge Sort function for linked list
Node* merge_sort_linked_list(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* left;
    Node* right;

    // Split the list into two halves
    split(head, &left, &right);

    // Recursively sort the two halves
    left = merge_sort_linked_list(left);
    right = merge_sort_linked_list(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to print the linked list
void print_linked_list(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    Node* head = new Node{5, nullptr};
    head->next = new Node{3, nullptr};
    head->next->next = new Node{8, nullptr};
    head->next->next->next = new Node{1, nullptr};
    head->next->next->next->next = new Node{6, nullptr};

    std::cout << "Original Linked List: ";
    print_linked_list(head);

    // Sort the linked list using Merge Sort
    head = merge_sort_linked_list(head);

    std::cout << "Sorted Linked List: ";
    print_linked_list(head);

    // Clean up the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
