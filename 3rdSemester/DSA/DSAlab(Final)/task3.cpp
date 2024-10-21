#include <iostream>
#include <vector>
#include <algorithm>

// AVL Tree implementation
struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
};

int getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    newRoot->height = std::max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

AVLNode* insert(AVLNode* root, int data) {
    if (root == nullptr) {
        AVLNode* newNode = new AVLNode;
        newNode->data = data;
        newNode->height = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root; // Duplicate keys not allowed
    }
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (data < root->left->data) {
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balanceFactor < -1) {
        if (data > root->right->data) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}

void inorderTraversal(AVLNode* root, std::vector<int>& elements) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}

// Merge Sort implementation
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort implementation
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // AVL Guardians' Scroll
    AVLNode* avlRoot = nullptr;
    std::vector<int> avlElements = {21, 13, 32, 7, 18, 26, 38, 4, 15, 28, 35, 42};
    for (int element : avlElements) {
        avlRoot = insert(avlRoot, element);
    }

    // Merge Sages' Scroll
    std::vector<int> mergeElements = {24, 10, 31, 5, 17, 29, 39, 2, 14, 22, 33, 40};
    mergeSort(mergeElements, 0, mergeElements.size() - 1);

    // Quick Sorcerers' Scroll
    std::vector<int> quickElements = {19, 11, 27, 8, 23, 36, 45, 1, 16, 30, 37, 41};
    quickSort(quickElements, 0, quickElements.size() - 1);

    // Combine the three structures into the Sorting Medallion
    std::vector<int> sortingMedallion;
    inorderTraversal(avlRoot, sortingMedallion);
    sortingMedallion.insert(sortingMedallion.end(), mergeElements.begin(), mergeElements.end());
    sortingMedallion.insert(sortingMedallion.end(), quickElements.begin(), quickElements.end());

    // Sort the enchanted elements of the Sorting Medallion
    std::sort(sortingMedallion.begin(), sortingMedallion.end());

    // Display the enchanted elements in sorted order
    for (int element : sortingMedallion) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
