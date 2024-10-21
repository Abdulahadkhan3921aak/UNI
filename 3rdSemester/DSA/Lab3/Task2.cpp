#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < str.length(); i--)
    {
        if (str[i] != s.top())
        {
            return false;
        }
        s.pop();
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
