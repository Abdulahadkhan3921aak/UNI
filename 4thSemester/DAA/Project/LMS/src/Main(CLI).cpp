#include <iostream>
#include "../includes/Library.h"

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
    Library library("books.csv", "members.csv");
    int choice;

    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                Book newBook;
                newBook.inputDetails();
                library.addBook(newBook);
                break;
            }
            case 2: {
                Member newMember;
                newMember.inputDetails();
                library.addMember(newMember);
                break;
            }
            case 3: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.borrowBook(memberId, bookId);
                break;
            }
            case 4: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.returnBook(memberId, bookId);
                break;
            }
            case 5: {
                string searchTerm;
                cout << "Enter search term (title/author/ISBN/category): ";
                cin.ignore();
                getline(cin, searchTerm);
                library.searchBook(searchTerm);
                break;
            }
            case 6: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.reserveBook(memberId, bookId);
                break;
            }
            case 7:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
