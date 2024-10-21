#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int decimal_number;
    cout << "Enter a decimal number: ";
    cin >> decimal_number;

    stack<int> s;

    while (decimal_number > 0)
    {
        int remainder = decimal_number % 2;
        s.push(remainder);
        decimal_number /= 2;
    }

    cout << "The binary equivalent of the decimal number is: ";
    while (!s.empty())
    {
        if ((s.size() + 1) % 5 == 0)
        {
            cout << " ";
        }
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}
