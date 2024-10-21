#include <iostream>
#include <vector>
#include <conio.h> // For _getch() on Windows

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "../includes/Library.h"
#include "../includes/Member.h"
#include "../includes/Book.h"

using namespace std;

void displayMenu(const vector<string>& menuItems, int selectedItem);
int navigateMenu(const vector<string>& menuItems);
void clearScreen();
void delay(int milliseconds);

int main() {
    Library library("books.csv", "members.csv");
    vector<string> menuItems = {
        "Add Book",
        "Add Member",
        "Borrow Book",
        "Return Book",
        "Search Book",
        "Reserve Book",
        "Exit"
    };

    int selectedItem = 0;
    while (true) {
        clearScreen();
        displayMenu(menuItems, selectedItem);

        int choice = navigateMenu(menuItems);
        clearScreen();

        switch (choice) {
            case 0: {
                Book newBook;
                newBook.inputDetails();
                library.addBook(newBook);
                break;
            }
            case 1: {
                Member newMember;
                newMember.inputDetails();
                library.addMember(newMember);
                break;
            }
            case 2: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.borrowBook(memberId, bookId);
                break;
            }
            case 3: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.returnBook(memberId, bookId);
                break;
            }
            case 4: {
                string searchTerm;
                cout << "Enter search term (title/author/ISBN/category): ";
                cin.ignore();
                getline(cin, searchTerm);
                library.searchBook(searchTerm);
                break;
            }
            case 5: {
                int memberId, bookId;
                cout << "Enter Member ID: ";
                cin >> memberId;
                cout << "Enter Book ID: ";
                cin >> bookId;
                library.reserveBook(memberId, bookId);
                break;
            }
            case 6:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }

        cout << "Press any key to return to the menu..." << endl;
        _getch(); // Wait for a key press before returning to the menu
    }

    return 0;
}

void displayMenu(const vector<string>& menuItems, int selectedItem) {
    cout << "Library Management System Menu" << endl;
    for (size_t i = 0; i < menuItems.size(); ++i) {
        if (i == selectedItem) {
            cout << "> " << menuItems[i] << " <" << endl;
        } else {
            cout << "  " << menuItems[i] << endl;
        }
    }
}

int navigateMenu(const vector<string>& menuItems) {
    int selectedItem = 0;
    while (true) {
        int key = _getch();
        switch (key) {
            case 72: // Up arrow
                selectedItem = (selectedItem > 0) ? selectedItem - 1 : menuItems.size() - 1;
                break;
            case 80: // Down arrow
                selectedItem = (selectedItem < menuItems.size() - 1) ? selectedItem + 1 : 0;
                break;
            case 13: // Enter key
                return selectedItem;
        }
        clearScreen();
        displayMenu(menuItems, selectedItem);
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
