#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

class PhoneBook : public QWidget
{
    Q_OBJECT

private:
    QLineEdit* nameLineEdit;
    QLineEdit* numberLineEdit;
    QTextEdit* displayTextEdit;

public:
    PhoneBook(QWidget* parent = nullptr);
private slots:
    void addEntry();
    void searchEntry();
    void showAllEntries();
    void updateEntry();
    void deleteEntry();
    void clearEntries();

private:
    void displayMessage(const QString& message);
};

#endif // PHONEBOOK_H
