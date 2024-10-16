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
        cout << "Enter the book title : ";
        cin.ignore();
        getline(cin, this->title);
        cout << "Enter the price : ";
        cin >> this->price;
        cout << "Enter the number of pages : ";
        cin >> this->page_count;
    }

    void putdata() override
    {
        cout << "\n\nBook title : " << this->title << endl;
        cout << "Price : " << this->price << endl;
        cout << "Number of pages : " << this->page_count << endl;
        cout << "\n\n";
    }
};

class tape : public publication
{
private:
    float TimeInMinutes;

    void getdata() override
    {
        cout << "Enter the book title : ";
        cin.ignore();
        getline(cin, this->title);
        cout << "Enter the price : ";
        cin >> this->price;
        cout << "Enter the time in minutes : ";
        cin >> this->TimeInMinutes;
    }

    void putdata() override
    {
        cout << "\n\nBook title : " << this->title << endl;
        cout << "Price : " << this->price << endl;
        cout << "Time in minutes : " << this->TimeInMinutes << endl;
        cout << "\n\n";
    }
};

int main()
{
    publication *p;

    cout << "\n\n\t\tChoose The menu for desired Task : \n";
    cout << "\t\t\tPress 1 to Select a Book\n";
    cout << "\t\t\tPress 2 to Select a Tape\n";
    cout << "\t\t\tPress 0 to exit\n";

choiceP:
    int choice = -1;
    cin >> choice;

    cout << "\n\n";

    switch (choice)
    {

    case 0:
        cout << "Thank you for your time..\nExitnig...\nQUIT\n\n";
        exit(0);
        break;
    case 1:
        p = new book();
        break;

    case 2:
        p = new tape();
        break;

    default:
        cout << "wrong input\n";
        goto choiceP;
    }

    p->getdata();

    p->putdata();

    return 0;
}
