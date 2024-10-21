
#include <iostream>
#include <unordered_map>
#include "../include/Library.h"
#include "../include/Member.h"
#include "../include/Book.h"

using namespace std;

void displayMenu() {
    cout << "Library Management System Menu" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add Member" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Search Book" << endl;
    cout << "6. Reserve Book" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addMember();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                library.searchBook();
                break;
            case 6:
                library.reserveBook();
                break;
            case 7:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
