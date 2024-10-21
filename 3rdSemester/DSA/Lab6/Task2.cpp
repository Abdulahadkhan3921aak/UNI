#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
public:
    Stack() { top = NULL; }

    void push(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            exit(1);
        }

        Node *temp = top;
        int data = top->data;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() { return top == NULL; }

    int bestScore()
    {
        int bestScore = INT_MIN;
        Node *curr = top;
        while (curr != NULL)
        {
            if (curr->data > bestScore)
            {
                bestScore = curr->data;
            }
            curr = curr->next;
        }
        return bestScore;
    }

    float averageScore()
    {
        float sum = 0;
        int count = 0;
        Node *curr = top;
        while (curr != NULL)
        {
            sum += curr->data;
            count++;
            curr = curr->next;
        }
        return sum / count;
    }

    int worstScore()
    {
        int worstScore = INT_MAX;
        Node *curr = top;
        while (curr != NULL)
        {
            if (curr->data < worstScore)
            {
                worstScore = curr->data;
            }
            curr = curr->next;
        }
        return worstScore;
    }

private:
    Node *top;
};

int main()
{
    Stack stack;

    // Push the test scores into the stack
    cout << "Enter the test scores: ";
    int score;
    while (cin >> score)
    {
        stack.push(score);
    }

    // Find the best, average, and worst scores
    int bestScore = stack.bestScore();
    float averageScore = stack.averageScore();
    int worstScore = stack.worstScore();

    // Print the results
    cout << "Best score: " << bestScore << endl;
    cout << "Average score: " << averageScore << endl;
    cout << "Worst score: " << worstScore << endl;

    return 0;
}
