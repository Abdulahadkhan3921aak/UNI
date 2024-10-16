#include <iostream>
#include <string>
#include <map>
#include "sqlite3.h"
#include <algorithm>
#include <iomanip>

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
    sqlite3* db;

    void InitializeDatabase()
    {
        int rc = sqlite3_open("PhoneBook.db", &db);
        if (rc != SQLITE_OK)
        {
            cout << "Error: Could not open database: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            exit(1);
        }

        const char* createTableQuery = "CREATE TABLE IF NOT EXISTS phonebook (name TEXT PRIMARY KEY, number TEXT);";
        rc = sqlite3_exec(db, createTableQuery, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK)
        {
            cout << "Error: Could not create table: " << sqlite3_errmsg(db) << endl;
            sqlite3_close(db);
            exit(1);
        }
    }

    void CloseDatabase()
    {
        sqlite3_close(db);
    }

public:
    PhoneBook()
    {
        InitializeDatabase();
    }

    ~PhoneBook()
    {
        CloseDatabase();
    }

    void AddEntry()
    {
        cout << "Name: ";
        getline(cin, e.name);
        cout << "Number: ";
        getline(cin, e.number);

        string query = "INSERT INTO phonebook (name, number) VALUES ('" + e.name + "', '" + e.number + "');";
        int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK)
        {
            cout << "Error: Could not add entry to the phonebook: " << sqlite3_errmsg(db) << endl;
        }
        else
        {
            cout << "Entry added." << endl;
        }
    }

    void SearchData()
    {
        cout << "Name: ";
        getline(cin, e.name);

        string query = "SELECT number FROM phonebook WHERE name = '" + e.name + "';";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
        if (rc == SQLITE_OK)
        {
            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW)
            {
                string number(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                cout << e.name << "'s number is " << number << endl;
            }
            else
            {
                cout << e.name << " was not found in the phonebook." << endl;
            }
        }
        else
        {
            cout << "Error: Could not search for data: " << sqlite3_errmsg(db) << endl;
        }

        sqlite3_finalize(stmt);
    }

    void ShowAll()
    {
        string query = "SELECT * FROM phonebook;";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
        if (rc == SQLITE_OK)
        {
            while (sqlite3_step(stmt) == SQLITE_ROW)
            {
                string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                string number(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
                cout << "Name: " << setw(10) << left << name << " Number: " << number << endl;
            }
        }
        else
        {
            cout << "Error: Could not fetch data from the phonebook: " << sqlite3_errmsg(db) << endl;
        }

        sqlite3_finalize(stmt);
    }

    void Update(const string& contactName)
    {
        string query = "SELECT number FROM phonebook WHERE name = '" + contactName + "';";
        sqlite3_stmt* stmt;
        int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
        if (rc == SQLITE_OK)
        {
            rc = sqlite3_step(stmt);
            if (rc == SQLITE_ROW)
            {
                string number(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                cout << "Old Number: " << number << endl;
                cout << "New Number: ";
                getline(cin, e.number);

                string updateQuery = "UPDATE phonebook SET number = '" + e.number + "' WHERE name = '" + contactName + "';";
                rc = sqlite3_exec(db, updateQuery.c_str(), nullptr, nullptr, nullptr);
                if (rc != SQLITE_OK)
                {
                    cout << "Error: Could not update contact's number: " << sqlite3_errmsg(db) << endl;
                }
                else
                {
                    cout << "Contact's number updated." << endl;
                }
            }
            else
            {
                cout << contactName << " was not found in the phonebook." << endl;
            }
        }
        else
        {
            cout << "Error: Could not search for data: " << sqlite3_errmsg(db) << endl;
        }

        sqlite3_finalize(stmt);
    }

    void Delete()
    {
        cout << "Name: ";
        getline(cin, e.name);

        string query = "DELETE FROM phonebook WHERE name = '" + e.name + "';";
        int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK)
        {
            cout << "Error: Could not delete entry from the phonebook: " << sqlite3_errmsg(db) << endl;
        }
        else
        {
            cout << e.name << " deleted from the phonebook." << endl;
        }
    }
};

int main()
{
    PhoneBook pb;

    while (true)
    {
        cout << "\nPhoneBook Application\n";
        cout << "1. Add Entry\n";
        cout << "2. Search Data\n";
        cout << "3. Show All\n";
        cout << "4. Update\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        string choice;
        getline(cin, choice);

        if (choice == "1")
        {
            pb.AddEntry();
        }
        else if (choice == "2")
        {
            pb.SearchData();
        }
        else if (choice == "3")
        {
            pb.ShowAll();
        }
        else if (choice == "4")
        {
            cout << "Contact Name: ";
            getline(cin, choice);
            pb.Update(choice);
        }
        else if (choice == "5")
        {
            pb.Delete();
        }
        else if (choice == "6")
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
