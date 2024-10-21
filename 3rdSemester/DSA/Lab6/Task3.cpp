#include <iostream>

using namespace std;

struct Employee
{
    int id;
    string name;
    string department;
    float salary;
};

struct Node
{
    Employee employee;
    Node *next;
};

class Stack
{
public:
    Stack() { top = NULL; }

    void push(Employee employee)
    {
        Node *newNode = new Node();
        newNode->employee = employee;
        newNode->next = top;
        top = newNode;
    }

    Employee pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            exit(1);
        }

        Node *temp = top;
        Employee employee = top->employee;
        top = top->next;
        delete temp;
        return employee;
    }

    bool isEmpty() { return top == NULL; }

    void display()
    {
        Node *curr = top;
        while (curr != NULL)
        {
            cout << curr->employee.id << " " << curr->employee.name << " " << curr->employee.department << " " << curr->employee.salary << endl;
            curr = curr->next;
        }
    }

private:
    Node *top;
};

int main()
{
    Stack stack;

    // Push some employee records into the stack
    Employee employee1 = {1, "Alice", "Engineering", 100000};
    Employee employee2 = {2, "Bob", "Sales", 90000};
    Employee employee3 = {3, "Carol", "Marketing", 80000};
    stack.push(employee1);
    stack.push(employee2);
    stack.push(employee3);

    // Display the employee records in the stack
    stack.display();

    // Pop an employee record from the stack
    Employee employee = stack.pop();

    // Display the popped employee record
    cout << "Popped employee record: " << endl;
    cout << employee.id << " " << employee.name << " " << employee.department << " " << employee.salary << endl;

    return 0;
}
