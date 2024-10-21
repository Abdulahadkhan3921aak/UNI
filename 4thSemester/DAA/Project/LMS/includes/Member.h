#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <algorithm>

class Member
{
private:
    int id;
    std::string name;
    std::string contactDetails;
    std::vector<int> borrowingHistory;
    std::vector<int> reservedBooks;

public:
    Member();
    std::string getName() const;
    std::string getContactDetails() const;
    std::string getBorrowingHistoryString() const;
    std::string getReservedBooksString() const;
    void setID(int id);
    void setName(std::string name);
    void setContactDetails(std::string contactDetails);
    void inputDetails();
    int getID() const;
    void displayDetails() const;
    void borrowBook(int bookId);
    void returnBook(int bookId);
    void reserveBook(int bookId);
    void setBorrowingHistoryFromString(const std::string &history);
    void setReservedBooksFromString(const std::string &reserved);
};

#endif // MEMBER_H
