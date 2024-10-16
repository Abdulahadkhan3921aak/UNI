// #include <iostream>

// using namespace std;

// struct BookRecord
// {
//     int Sr;
//     float price;

//     void getdata()
//     {
//         cout << "Enter the Serial number of the book : ";
//         cin >> Sr;
//         cout << "Enter the price of the book : ";
//         cin >> price;
//     }

//     void DisplayPrice()
//     {
//         cout << "The price is : " << price << endl;
//     }

//     void DisplayData(int i)
//     {
//         cout << "The Book " << i + 1 << endl;
//         cout << "The serial number is : " << Sr << endl;
//         cout << "The price is : " << Sr << endl;
//     }
// };

// BookRecord br[3];
// bool recordAvailable[3] = {false, false, false};
// int bn, choice;

// void Display()
// {
//     cout << "\t\t\tMain Menu" << endl;
//     cout << "\nEnter 1 to enter a record";
//     cout << "\nEnter 2 to dsiplay the record";
//     cout << "\nEnter 3 to exit" << endl;
// }

// void GetRecord()
// {
//     int bn;
// getre:
//     cout << "Enter 1 to enter book 1 record" << endl;
//     cout << "Enter 2 to enter book 2 record" << endl;
//     cout << "Enter 3 to enter book 3 record" << endl;
//     cout << "Enter 4 to go back to Main Menu" << endl;
//     cout << "Enter 5 to exit" << endl;
//     cin >> bn;
//     if (!recordAvailable[bn])
//         switch (bn)
//         {
//         case 1:
//             br[0].getdata();
//             break;
//         case 2:
//             br[1].getdata();
//             break;
//         case 3:
//             br[2].getdata();
//             break;
//         case 4:
//             return;
//             break;
//         case 5:
//             exit(0);
//             break;

//         default:
//             break;
//         }
//     else
//     {
//         cout << "Record already contains a Book" << endl;
//         goto getre;
//     }
// }

// void DisplayRecord()
// {
//     int bn;
//     char choice;
//     char c;
//     do
//     {
//     get:
//         cout << "Enter a display the price of a particular book" << endl;
//         cout << "Enter b display the record of all books" << endl;
//         cin >> choice;

//         switch (choice)
//         {
//         case 'a':
//             cout << "Enter the book number : ";
//             cin >> bn;
//             cout << "The price is : " << br[bn - 1].price << endl;
//             break;
//         case 'b':
//             for (int i = 0; i < 3; i++)
//             {
//                 br[i].DisplayData(i + 1);
//             }
//             break;
//         default:
//             cout << "wrong input :(";
//             goto get;
//             break;
//         }

//         cout << "Would you like to go to the Main Menu (Y/N):";
//         cin >> c;
//     } while (c == 'Y' || c == 'y');
// }

// int main()
// {

//     do
//     {
//         system("cls");
//         Display();
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             GetRecord();
//             break;
//         case 2:
//             DisplayRecord();
//             break;
//         case 3:
//             exit(0);
//             break;
//         default:
//             cout << "Wrong input" << endl;
//             break;
//         }
//     } while (true);

//     return 0;
// }

#include <iostream>

using namespace std;

struct Draaz {
    int sales;
    float revenue;
};

struct Alibaba {
    int sales;
    float revenue;
    Draaz draaz;
};

struct AliExpress {
    int sales;
    float revenue;
    Alibaba alibaba;
};

void displayDraaz(Draaz d) {
    cout << "Draaz Sales: " << d.sales << endl;
    cout << "Draaz Revenue: $" << d.revenue << endl;
}

void displayAlibaba(Alibaba a) {
    cout << "Alibaba Sales: " << a.sales << endl;
    cout << "Alibaba Revenue: $" << a.revenue << endl;
    displayDraaz(a.draaz);
}

void displayAliExpress(AliExpress ae) {
    cout << "AliExpress Sales: " << ae.sales << endl;
    cout << "AliExpress Revenue: $" << ae.revenue << endl;
    displayAlibaba(ae.alibaba);
}

void displayAll(AliExpress ae) {
    cout << "Sales Data:\n";
    displayAliExpress(ae);
}

int main() {
    AliExpress ae;
    int choice;

    cout << "Enter AliExpress sales: ";
    cin >> ae.sales;
    cout << "Enter AliExpress revenue: ";
    cin >> ae.revenue;
    cout << "Enter Alibaba sales: ";
    cin >> ae.alibaba.sales;
    cout << "Enter Alibaba revenue: ";
    cin >> ae.alibaba.revenue;
    cout << "Enter Draaz sales: ";
    cin >> ae.alibaba.draaz.sales;
    cout << "Enter Draaz revenue: ";
    cin >> ae.alibaba.draaz.revenue;

    do {
        cout << "\nMenu\n";
        cout << "1. Display Draaz data\n";
        cout << "2. Display Alibaba data\n";
        cout << "3. Display AliExpress data\n";
        cout << "4. Display all sales data\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayDraaz(ae.alibaba.draaz);
                break;
            case 2:
                displayAlibaba(ae.alibaba);
                break;
            case 3:
                displayAliExpress(ae);
                break;
            case 4:
                displayAll(ae);
                break;
            case 5:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}