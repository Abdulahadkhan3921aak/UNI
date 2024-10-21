#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Define structures for book and member records
struct Book
{
    std::string title;
    std::string author;
    std::string ISBN;
    std::string category;
    bool availability;
    std::string location;
};

struct Member
{
    std::string name;
    std::string contactDetails;
    std::string membershipID;
    std::vector<Book *> borrowingHistory;
};

// Define a custom hashing function for book ISBN
struct ISBNHash
{
    std::size_t operator()(const std::string &isbn) const
    {
        // Custom hashing algorithm, you can replace it with your own
        // For simplicity, let's assume a basic hash function for demonstration
        std::size_t hash = 0;
        for (char c : isbn)
        {
            hash += c;
        }
        return hash;
    }
};

// Define the Library Management System class
class LibraryManagementSystem
{
private:
    std::unordered_map<std::string, Book *> books;     // Using ISBN as key
    std::unordered_map<std::string, Member *> members; // Using membershipID as key

public:
    // Functions for book management
    void addBook(const Book &book)
    {
        books[book.ISBN] = new Book(book);
    }

    void removeBook(const std::string &ISBN)
    {
        auto it = books.find(ISBN);
        if (it != books.end())
        {
            delete it->second;
            books.erase(it);
        }
    }

    // Functions for member management
    void addMember(const Member &member)
    {
        members[member.membershipID] = new Member(member);
    }

    void removeMember(const std::string &membershipID)
    {
        auto it = members.find(membershipID);
        if (it != members.end())
        {
            delete it->second;
            members.erase(it);
        }
    }
    // Function to display all books
    void displayAllBooks()
    {
        std::cout << "All Books in Library:\n";
        for (const auto &pair : books)
        {
            const Book &book = *pair.second;
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << ", Category: " << book.category << ", Availability: " 
            << (book.availability ? "Available" : "Not Available") << ", Location: " << book.location << std::endl;
        }
    }

    // Function to borrow a book
    bool borrowBook(const std::string &ISBN, const std::string &membershipID)
    {
        auto bookIt = books.find(ISBN);
        auto memberIt = members.find(membershipID);
        if (bookIt != books.end() && memberIt != members.end())
        {
            if (bookIt->second->availability)
            {
                bookIt->second->availability = false;
                memberIt->second->borrowingHistory.push_back(bookIt->second);
                return true;
            }
            else
            {
                std::cout << "Book is not available for borrowing." << std::endl;
            }
        }
        else
        {
            std::cout << "Book or member not found." << std::endl;
        }
        return false;
    }

    // Function to return a book
    bool returnBook(const std::string &ISBN, const std::string &membershipID)
    {
        auto bookIt = books.find(ISBN);
        auto memberIt = members.find(membershipID);
        if (bookIt != books.end() && memberIt != members.end())
        {
            auto &history = memberIt->second->borrowingHistory;
            auto it = std::find_if(history.begin(), history.end(), [&](Book *book)
                                   { return book->ISBN == ISBN; });
            if (it != history.end())
            {
                bookIt->second->availability = true;
                history.erase(it);
                return true;
            }
            else
            {
                std::cout << "Book not found in member's borrowing history." << std::endl;
            }
        }
        else
        {
            std::cout << "Book or member not found." << std::endl;
        }
        return false;
    }

    // Function to display menu
    void displayMenu()
    {
        std::cout << "\nLibrary Management System Menu\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. Add Member\n";
        std::cout << "4. Remove Member\n";
        std::cout << "5. Borrow Book\n";
        std::cout << "6. Return Book\n";
        std::cout << "7. Display All Books\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
    }

    // Function to handle menu options
    void processChoice(int choice)
    {
        switch (choice)
        {
        case 1:
        {
            // Add Book
            Book newBook;
            std::cout << "Enter Book details:\n";
            std::cout << "Title: ";
            getline(std::cin, newBook.title);
            std::cout << "Author: ";
            getline(std::cin, newBook.author);
            std::cout << "ISBN: ";
            std::cin >> newBook.ISBN;
            std::cout << "Category: ";
            std::cin >> newBook.category;
            newBook.availability = true;
            std::cout << "Location: ";
            getline(std::cin, newBook.location);
            addBook(newBook);
            std::cout << "Book added successfully.\n";
            break;
        }
        case 2:
        {
            // Remove Book
            std::string ISBN;
            std::cout << "Enter ISBN of the book to remove: ";
            std::cin >> ISBN;
            removeBook(ISBN);
            std::cout << "Book removed successfully.\n";
            break;
        }
        case 3:
        {
            // Add Member
            Member newMember;
            std::cout << "Enter Member details:\n";
            std::cout << "Name: ";
            getline(std::cin, newMember.name);
            std::cout << "Contact Details: ";
            std::cin >> newMember.contactDetails;
            std::cout << "Membership ID: ";
            std::cin >> newMember.membershipID;
            addMember(newMember);
            std::cout << "Member added successfully.\n";
            break;
        }
        case 4:
        {
            // Remove Member
            std::string membershipID;
            std::cout << "Enter Membership ID of the member to remove: ";
            std::cin >> membershipID;
            removeMember(membershipID);
            std::cout << "Member removed successfully.\n";
            break;
        }
        case 5:
        {
            // Borrow Book
            std::string ISBN, membershipID;
            std::cout << "Enter ISBN of the book to borrow: ";
            std::cin >> ISBN;
            std::cout << "Enter Membership ID of the member: ";
            std::cin >> membershipID;
            if (borrowBook(ISBN, membershipID))
            {
                std::cout << "Book borrowed successfully.\n";
            }
            break;
        }
        case 6:
        {
            // Return Book
            std::string ISBN, membershipID;
            std::cout << "Enter ISBN of the book to return: ";
            std::cin >> ISBN;
            std::cout << "Enter Membership ID of the member: ";
            std::cin >> membershipID;
            if (returnBook(ISBN, membershipID))
            {
                std::cout << "Book returned successfully.\n";
            }
            break;
        }
        case 7:
        {
            displayAllBooks();
            break;
        }
        case 8:
        {
            std::cout << "Exiting...\n";
            exit(0);
        }
        default:
            std::cout << "Wrong input" << std::endl;
        }
    }
};

int main()
{
    LibraryManagementSystem library;
    int choice;

    do
    {
        library.displayMenu();
        std::cin >> choice;
        library.processChoice(choice);
    } while (choice != 8);

    return 0;
}