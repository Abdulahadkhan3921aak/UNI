#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_RETURN 13

using namespace std;

struct Entry
{
    string name;
    string number;
};

class PhoneBook
{

private:
    Entry e;
    map<string, string> phonebook;

    void Save()
    {

        fstream Myfile("PhoneBook.txt", ios::out);
        for (map<string, string>::iterator i = phonebook.begin(); i != phonebook.end(); i++)
        {
            e.name = i->first;
            e.number = i->second;
            replace(e.name.begin(), e.name.end(), ' ', '_');
            replace(e.number.begin(), e.number.end(), ' ', '_');
            Myfile << e.name << " " << e.number << endl;
        }
        Myfile.close();
    }

    void Load()
    {
        fstream Myfile("PhoneBook.txt", ios::in);
        if (Myfile.is_open())
        {
            while (Myfile >> e.name >> e.number)
            {
                replace(e.name.begin(), e.name.end(), '_', ' ');
                replace(e.number.begin(), e.number.end(), '_', ' ');
                phonebook[e.name] = e.number;
            }
            Myfile.close();
        }
    }

public:
    void AddEntery()
    {
        system("cls");
        cout << "Name: ";
        getline(cin, e.name);
        cout << "Number: ";
        getline(cin, e.number);
        if (phonebook.find(e.name) != phonebook.end())
        {
            string choice;
            cout << "Contact already available.\nWould you like to update the number (yes / no ):" << endl;
            cin >> choice;
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
            if (choice == "yes")
            {
                Update(e.name);
            }
            else
            {
                cout << "Returnig back to Menu\n";
            }
        }
        else
        {
            phonebook[e.name] = e.number;
            cout << "Entry added." << endl;
        }

        cin.ignore();

        e.name.clear();
        e.number.clear();
        Save();
    }

    void SearchData()
    {
        unsigned long _count = phonebook.size();
        if (_count == 0)
        {
            cout << "No contacts available";
            cin.ignore();
            return;
        }
        system("cls");
        // search for an entry in the phonebook
        cout << "Name: ";
        getline(cin, e.name);
        if (phonebook.find(e.name) != phonebook.end())
        {
            // found the entry
            cout << e.name << "'s number is " << phonebook[e.name] << endl;
        }
        else
        {
            // didn't find the entry
            cout << e.name << " was not found in the phonebook" << endl;
        }

        e.name.clear();
        e.number.clear();
        cin.ignore();
    }

    void showAll()
    {
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    UPDATE_:
        unsigned long count = phonebook.size();
        string **Data = new string *[count];
        if (count == 0)
        {
            cout << "No contacts available";
            cin.ignore();
            return;
        }
        for (int _I = 0; _I < count; _I++)
        {
            Data[_I] = new string[2];
        }
        unsigned long index = 0;

        system("cls");

        for (map<string, string>::iterator i = phonebook.begin(); i != phonebook.end(); i++)
        {
            Data[index][0] = i->first;
            Data[index][1] = i->second;
            index++;
        }
        char c;
        int CI = 0;
        while (c != KEY_ESC)
        {
            system("cls");
            cout << "Use \"UP\" and \"DOWN\" Arrow key to highligth \"Return\" Key to submit and Press \"ESC\" to go Back" << endl;
            for (int i = 0; i < count; i++)
            {
                if (i == CI - 1)
                {
                    SetConsoleTextAttribute(console_color, 240);
                    cout << "\t" << Data[i][0] << setw(50 - Data[i][0].length() + Data[i][1].length()) << Data[i][1] << endl;
                }
                else
                {
                    SetConsoleTextAttribute(console_color, 7);
                    cout << "\t" << Data[i][0] << setw(50 - Data[i][0].length() + Data[i][1].length()) << Data[i][1] << endl;
                }
                SetConsoleTextAttribute(console_color, 7);
            }
            c = getch();
            if (c == KEY_UP && CI > 1)
            {
                CI--;
            }
            else if (c == KEY_DOWN && CI != count)
            {
                CI++;
            }
            else if (c == KEY_RETURN)
            {
                int HI = 0;
                bool LIST = true;
                while (LIST)
                {
                LIST_:
                    system("cls");

                    for (int i = 0; i < count; i++)
                    {
                        if (i == CI - 1)
                        {
                            SetConsoleTextAttribute(console_color, 240);
                            cout << "\t" << Data[i][0] << setw(50 - Data[i][0].length() + Data[i][1].length()) << Data[i][1] << endl;
                        }
                        else
                        {
                            SetConsoleTextAttribute(console_color, 7);
                            cout << "\t" << Data[i][0] << setw(50 - Data[i][0].length() + Data[i][1].length()) << Data[i][1] << endl;
                        }
                        SetConsoleTextAttribute(console_color, 7);
                    }

                    string choice[] = {"Delete", "Update", "Back"};
                    cout << "Use \"LEFT\" and \"RIGHT\" Arrow key to highligth and The \"Return\" Key to submit" << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        if (i == HI - 1)
                        {
                            SetConsoleTextAttribute(console_color, 240);
                            cout << "\t" << choice[i];
                        }
                        else
                        {
                            SetConsoleTextAttribute(console_color, 7);
                            cout << "\t" << choice[i];
                        }
                        SetConsoleTextAttribute(console_color, 7);
                    }

                    cout << endl;

                    char _c = getch();

                    if (_c == KEY_LEFT && HI > 1)
                    {
                        HI--;
                    }
                    else if (_c == KEY_RIGHT && HI != 3)
                    {
                        HI++;
                    }
                    else if (_c == KEY_RETURN)
                    {
                        switch (HI)
                        {
                        case 1:
                            Delete(Data[CI - 1][0]);
                            goto UPDATE_;

                        case 2:
                            Update(Data[CI - 1][0]);
                            goto UPDATE_;

                        case 3:
                            LIST = false;
                            break;
                        }
                    }
                }
            }
        }
        delete[] Data;
    }

    PhoneBook()
    {
        Load();
    }

    ~PhoneBook()
    {
        Save();
    }

    void Update(string _NAME = "")
    {
        unsigned long _count = phonebook.size();
        if (_count == 0)
        {
            cout << "No contacts available";
            cin.ignore();
            return;
        }
        if (_NAME == "")
        {
            cout << "Enter contact Name : ";

            getline(cin, e.name);
            if (phonebook.find(e.name) != phonebook.end())
            {
                // found the entry
                cout << "Enter The Number : " << endl;
                cin >> e.number;
                phonebook[e.name] = e.number;
                cout << "Contact Updated";
                Save();
            }
            else
            {
                // didn't find the entry
                cout << e.name << " was not found in the phonebook" << endl;
            }
        }
        else
        {
            cout << "Contact Name : " << _NAME << endl;
            cout << "Enter The Number : ";
            getline(cin, e.number);
            phonebook[_NAME] = e.number;
            cout << "Contact Updated";
            Save();
        }
        cin.ignore();
    }

    void Delete(string _NAME = "")
    {
        unsigned long _count = phonebook.size();
        if (_count == 0)
        {
            cout << "No contacts available";
            cin.ignore();
            return;
        }
        if (_NAME == "")
        {
            cout << "Enter contact Name : ";
            getline(cin, e.name);
            if (phonebook.find(e.name) != phonebook.end())
            {
                phonebook.erase(e.name);
                cout << "Contact Deleted" << endl;
                Save();
            }
            else
            {
                // didn't find the entry
                cout << e.name << " was not found in the phonebook" << endl;
            }
        }
        else
        {
            cout << "Name : " << _NAME << endl;
            if (phonebook.find(_NAME) != phonebook.end())
            {
                phonebook.erase(_NAME);
                cout << "Contact Deleted" << endl;
                Save();
            }
            else
            {
                // didn't find the entry
                cout << _NAME << " was not found in the phonebook" << endl;
            }
        }
        cin.ignore();
    }
};

int main()
{
    system("cls");
    bool RUN = true;
    PhoneBook PB;
    cout << "Welcome to your phonebook ( Press Enter to continue )" << endl;
    string actions[6] = {"Add", "Search", "Show All", "Update", "Delete", "Quit"};
    cin.ignore();
    int INDEX = 0;
    char _KEY;
    while (RUN)
    {
        while (true)
        {

            system("cls");
            HANDLE _console_color;
            _console_color = GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(_console_color, 7);

            cout << "Use \"Up\" and \"Down\" Arrow key to highligth and The \"Return\" Key to submit" << endl;
            for (int i = 0; i < 6; i++)
            {
                if (i == INDEX - 1)
                {

                    SetConsoleTextAttribute(_console_color, 240);

                    cout << "\t" << actions[i] << endl;
                }
                else
                {
                    SetConsoleTextAttribute(_console_color, 7);

                    cout << "\t" << actions[i] << endl;
                }
            }
            _KEY = getch();
            if (_KEY == KEY_UP && INDEX > 1)
            {
                INDEX--;
            }
            else if (_KEY == KEY_DOWN && INDEX < 6)
            {
                INDEX++;
            }
            else if (_KEY == KEY_RETURN)
            {
                SetConsoleTextAttribute(_console_color, 7);

                break;
            }

            SetConsoleTextAttribute(_console_color, 7);
        }
        switch (INDEX)
        {
        case 1:
            PB.AddEntery();
            break;

        case 2:
            PB.SearchData();
            break;

        case 3:
            PB.showAll();
            break;
        case 4:
            PB.Update();
            break;

        case 5:
            PB.Delete();
            break;

        case 6:
            system("cls");
            RUN = false;
            break;
        }
    }
    cout << "Thank You for using our service" << endl;

    return 0;
}
