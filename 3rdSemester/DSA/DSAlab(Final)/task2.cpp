#include <iostream>

using namespace std;

int main() {
    int englishNewspapers = 100;
    int urduNewspapers = 100;

    while (true) {
        cout << "Newspaper Delivery Service" << endl;
        cout << "1. English Newspaper" << endl;
        cout << "2. Urdu Newspaper" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (englishNewspapers > 0) {
                    cout << "English newspaper provided." << endl;
                    englishNewspapers--;
                } else {
                    cout << "Sorry, no English newspapers available." << endl;
                }
                break;
            case 2:
                if (urduNewspapers > 0) {
                    cout << "Urdu newspaper provided." << endl;
                    urduNewspapers--;
                } else {
                    cout << "Sorry, no Urdu newspapers available." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
