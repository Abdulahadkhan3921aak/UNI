// #include <iostream>
// #include <string>

// using namespace std;

// struct Alibaba
// {
//     string name;
//     int products;
//     float revenue;

//     void displayData()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Number of products: " << products << endl;
//         cout << "Revenue: " << revenue << endl;
//     }

//     void getdata()
//     {
//         cout << "Enter Alibaba name: ";
//         cin.ignore();
//         getline(cin, name);
//         cout << "Enter number of products: ";
//         cin >> products;
//         cout << "Enter revenue: ";
//         cin >> revenue;
//     }
// };

// struct AliExpress
// {
//     string name;
//     int products;
//     float revenue;

//     void displayData()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Number of products: " << products << endl;
//         cout << "Revenue: " << revenue << endl;
//     }

//     void getdata()
//     {
//         cout << "Enter AliExpress name: ";
//         cin.ignore();
//         getline(cin, name);
//         cout << "Enter number of products: ";
//         cin >> products;
//         cout << "Enter revenue: ";
//         cin >> revenue;
//     }
// };

// struct Draaz
// {
//     string name;
//     int products;
//     float revenue;

//     void displayData()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Number of products: " << products << endl;
//         cout << "Revenue: " << revenue << endl;
//     }

//     void getdata()
//     {
//         cout << "Enter Draaz name: ";
//         cin.ignore();
//         getline(cin, name);
//         cout << "Enter number of products: ";
//         cin >> products;
//         cout << "Enter revenue: ";
//         cin >> revenue;
//     }
// };

// void displayMenu()
// {
//     cout << "Press 1 for Draaz data" << endl;
//     cout << "Press 2 for Alibaba data" << endl;
//     cout << "Press 3 for AliExpress data" << endl;
//     cout << "Press 4 to exit" << endl;
// }

// int main()
// {
//     // Declare variables for Alibaba, AliExpress, and Draaz
//     Alibaba alibaba;
//     AliExpress aliexpress;
//     Draaz draaz;

//     int choice;

//     do
//     {
//         displayMenu();
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             draaz.getdata();
//             draaz.displayData();
//             break;
//         case 2:
//             alibaba.getdata();
//             alibaba.displayData();
//             break;
//         case 3:
//             aliexpress.getdata();
//             aliexpress.displayData();
//             break;
//         case 4:
//             cout << "Exiting program..." << endl;
//             break;
//         default:
//             cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
//             break;
//         }
//     } while (choice != 4);

//     return 0;
// }


#include <iostream>

using namespace std;

struct BookRecord {
    int SrNo;
    float Price;
};

int main() {
    BookRecord books[3];
    int choice, i = 0;

    do {
        cout << "\nMain Menu\n";
        cout << "1. Add a book record\n";
        cout << "2. Display all book records\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (i < 3) {
                    cout << "\nEnter serial number of book " << i+1 << ": ";
                    cin >> books[i].SrNo;
                    cout << "Enter price of book " << i+1 << ": ";
                    cin >> books[i].Price;
                    i++;
                } else {
                    cout << "\nSorry, you can only add up to 3 book records.\n";
                }
                break;
            case 2:
                if (i == 0) {
                    cout << "\nNo book records found.\n";
                } else {
                    cout << "\nBook Records:\n";
                    for (int j = 0; j < i; j++) {
                        cout << "Book " << j+1 << " - Serial Number: " << books[j].SrNo << ", Price: $" << books[j].Price << endl;
                    }
                }
                break;
            case 3:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 3.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}