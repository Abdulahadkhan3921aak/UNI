#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s, temps;
    int choice;

    cout << "MAIN MENU FOR STACK" << endl;
    cout << "1. PUSH" << endl;
    cout << "2. POP" << endl;
    cout << "3. Display" << endl;
    cout << "4. Count" << endl;
    cout << "5. isEmpty" << endl;
    cout << "6. PEEK" << endl;
    cout << "7. QUIT" << endl;

    int element;

    while (true)
    {
        system("cls");

        cout << "MAIN MENU FOR STACK" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. PEEK" << endl;
        cout << "7. QUIT" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            element;
            cout << "Enter element to push: ";
            cin >> element;
            s.push(element);
            break;
        case 2:
            cout << "Popped element: " << s.top() << endl;
            s.pop();
            break;
        case 3:
            // display the stack
            while (!s.empty())
            {
                temps.push(s.top());
                cout << s.top() << " ";
                s.pop();
            }
            while (!temps.empty())
            {
                s.push(temps.top());
                temps.pop();
            }
            cout << endl;
            break;
        case 4:

            cout << "Number of elements in the stack: " << s.size() << endl;
            break;
        case 5:

            if (s.empty())
                cout << "The stack is empty." << endl;
            else
                cout << "The stack is not empty." << endl;
            break;
        case 6:;
            cout << "Top element in the stack: " << s.top() << endl;
            break;
        case 7:
            exit(0);
            break;
        }

        cout << "\n\nPress Enter to continue";
        cin.ignore();
        cin.ignore();
    }
}
