
#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include <algorithm>

class Member {
private:
    int id;
    std::string name;
    std::string contactDetails;
    std::vector<int> borrowingHistory;
    std::vector<int> reservedBooks; // New member for reservations

public:
    Member();
    void inputDetails();
    int getID() const;
    void displayDetails() const;
    void borrowBook(int bookId); // New method
    void returnBook(int bookId); // New method
    void reserveBook(int bookId); // New method
};

#endif // MEMBER_H
