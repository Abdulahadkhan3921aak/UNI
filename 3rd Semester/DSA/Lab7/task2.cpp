#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers = {5, 2, 9, 1, 7, 3};

    int max = numbers[0];
    int min = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    cout << "\n\n";

    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;

    cout << "\n\n";

    return 0;
}
