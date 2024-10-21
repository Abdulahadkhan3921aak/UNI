#include <iostream>
#include <string>
using namespace std;

class publication
{
protected:
    string title;
    float price;

public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class book : public publication
{
private:
    int page_count;

public:
    void getdata() override
    {
        cout << "Enter the book title: ";
        cin.ignore();
        getline(cin, this->title);
        cout << "Enter the price: ";
        cin >> this->price;
        cout << "Enter the number of pages: ";
        cin >> this->page_count;
    }

    void putdata() override
    {
        cout << "\nBook title: " << this->title << endl;
        cout << "Price: " << this->price << endl;
        cout << "Number of pages: " << this->page_count << endl;
        cout << "\n";
    }
};

class tape : public publication
{
private:
    float TimeInMinutes;

public:
    void getdata() override
    {
        cout << "Enter the tape title: ";
        cin.ignore();
        getline(cin, this->title);
        cout << "Enter the price: ";
        cin >> this->price;
        cout << "Enter the time in minutes: ";
        cin >> this->TimeInMinutes;
    }

    void putdata() override
    {
        cout << "\nTape title: " << this->title << endl;
        cout << "Price: " << this->price << endl;
        cout << "Time in minutes: " << this->TimeInMinutes << endl;
        cout << "\n";
    }
};

int main()
{
    const int MAX_PUBLICATIONS = 10;
    publication *pubArray[MAX_PUBLICATIONS]; // Array of pointers to publication

    cout << "\n\t\tChoose the menu for the desired task:\n";
    cout << "\t\t1. Enter a Book\n";
    cout << "\t\t2. Enter a Tape\n";
    cout << "\t\t0. Exit\n";

    int choice;
    int numPublications = 0; // Keep track of the number of publications

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting...\n";
            break; // Exit the loop if the user chooses 0
        }
        else if (choice == 1 || choice == 2)
        {
            if (numPublications < MAX_PUBLICATIONS)
            {
                if (choice == 1)
                {
                    pubArray[numPublications] = new book();
                }
                else if (choice == 2)
                {
                    pubArray[numPublications] = new tape();
                }

                pubArray[numPublications]->getdata();
                numPublications++;
            }
            else
            {
                cout << "Maximum publications reached.\n";
            }
        }
        else
        {
            cout << "Invalid choice. Please enter 0, 1, or 2.\n";
        }
    }

    // Display the data for all the publications
    for (int i = 0; i < numPublications; i++)
    {
        pubArray[i]->putdata();
        delete pubArray[i]; // Delete the dynamically allocated objects
    }

    return 0;
}
