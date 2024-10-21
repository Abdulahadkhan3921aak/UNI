#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib2(int n, int *arr)
{
    if (arr[n] != -1)
        return arr[n];
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    arr[n] = fib2(n - 1, arr) + fib2(n - 2, arr);
    return arr[n];
}

int main()
{
    int c = 7;
    // cout << fib(c) << endl;
    int *arr = new int[c + 1];
    for (int i = 0; i <= c; i++)
        arr[i] = -1;
    // arr[0] = 0;
    // arr[1] = 1;
    cout << fib2(c, arr) << endl;
    return 0;
}