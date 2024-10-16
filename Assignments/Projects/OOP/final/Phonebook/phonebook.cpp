#include "phonebook.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QInputDialog>


PhoneBook::PhoneBook(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    QLabel* nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit;
    QHBoxLayout* nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit);

    QLabel* numberLabel = new QLabel("Number:");
    numberLineEdit = new QLineEdit;
    QHBoxLayout* numberLayout = new QHBoxLayout;
    numberLayout->addWidget(numberLabel);
    numberLayout->addWidget(numberLineEdit);

    QPushButton* addButton = new QPushButton("Add");
    QPushButton* searchButton = new QPushButton("Search");
    QPushButton* showAllButton = new QPushButton("Show All");
    QPushButton* updateButton = new QPushButton("Update");
    QPushButton* deleteButton = new QPushButton("Delete");
    QPushButton* clearButton = new QPushButton("Clear All");

    QHBoxLayout* buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(searchButton);
    buttonLayout->addWidget(showAllButton);
    buttonLayout->addWidget(updateButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(clearButton);

    displayTextEdit = new QTextEdit;
    displayTextEdit->setReadOnly(true);

    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(numberLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(displayTextEdit);

    connect(addButton, &QPushButton::clicked, this, &PhoneBook::addEntry);
    connect(searchButton, &QPushButton::clicked, this, &PhoneBook::searchEntry);
    connect(showAllButton, &QPushButton::clicked, this, &PhoneBook::showAllEntries);
    connect(updateButton, &QPushButton::clicked, this, &PhoneBook::updateEntry);
    connect(deleteButton, &QPushButton::clicked, this, &PhoneBook::deleteEntry);
    connect(clearButton, &QPushButton::clicked , this , &PhoneBook::clearEntries);
}

void PhoneBook::addEntry()
{
    QString name = nameLineEdit->text().trimmed();
    QString number = numberLineEdit->text().trimmed();

    if (name.isEmpty() || number.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name and number.");
        return;
    }

    // Validate phone number format
    static QRegularExpression regex("^[0-9]{11}$");
    if (!regex.match(number).hasMatch())
    {
        QMessageBox::warning(this, "Error", "Please enter a valid 11-digit phone number.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM phonebook WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();

    if (query.next())
    {
        int result = QMessageBox::question(this, "Contact already exists",
                                           "Contact already exists. Do you want to update the number?",
                                           QMessageBox::Yes | QMessageBox::No);

        if (result == QMessageBox::Yes)
        {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE phonebook SET number = :number WHERE name = :name");
            updateQuery.bindValue(":number", number);
            updateQuery.bindValue(":name", name);
            updateQuery.exec();
            displayMessage("Entry updated.");
        }
        else
        {
            displayMessage("Returning back to Menu.");
        }
    }
    else
    {
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO phonebook (name, number) VALUES (:name, :number)");
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":number", number);
        insertQuery.exec();
        displayMessage("Entry added.");
    }

    nameLineEdit->clear();
    numberLineEdit->clear();
}




void PhoneBook::searchEntry()
{
    QString name = nameLineEdit->text();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name to search.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT number FROM phonebook WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();

    if (query.next())
    {
        QString number = query.value(0).toString();
        QString result = QString("%1 : %2").arg(name, number);
        displayMessage(result);
    }
    else
    {
        displayMessage("Contact not found.");
    }

    nameLineEdit->clear();
}


void PhoneBook::showAllEntries()
{
    // Prompt the user to choose the sorting criteria
    QStringList sortOptions;
    sortOptions << "Name" << "Number";
    bool ok;
    QString sortCriteria = QInputDialog::getItem(this, "Sort Entries", "Sort by:", sortOptions, 0, false, &ok);

    if (!ok)
        return;  // User cancelled the operation

    // Construct the SQL query with the chosen sorting criteria
    QString sqlQuery = "SELECT name, number FROM phonebook ORDER BY ";
    if (sortCriteria == "Name")
        sqlQuery += "name";
    else if (sortCriteria == "Number")
        sqlQuery += "number";

    QSqlQuery query(sqlQuery);
    QString entries;

    while (query.next())
    {
        QString name = query.value(0).toString();
        QString number = query.value(1).toString();
        entries.append(QString("%1: %2\n").arg(name, number));
    }

    if (entries.isEmpty())
    {
        displayMessage("No entries found.");
    }
    else
    {
        displayMessage(entries);
    }
}



void PhoneBook::updateEntry()
{
    QString name = nameLineEdit->text();
    QString number = numberLineEdit->text();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name to update.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM phonebook WHERE name = :name");
    query.bindValue(":name", name);
    query.exec();

    if (query.next())
    {
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE phonebook SET number = :number WHERE name = :name");
        updateQuery.bindValue(":number", number);
        updateQuery.bindValue(":name", name);
        updateQuery.exec();
        displayMessage("Contact updated.");
    }
    else
    {
        displayMessage("Contact not found.");
    }

    nameLineEdit->clear();
    numberLineEdit->clear();
}



void PhoneBook::deleteEntry()
{
    QString name = nameLineEdit->text();

    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name to delete.");
        return;
    }

    int result = QMessageBox::question(this, "Delete Entry", "Are you sure you want to delete this entry?", QMessageBox::Yes | QMessageBox::No);
    if (result == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM phonebook WHERE name = :name");
        query.bindValue(":name", name);
        query.exec();

        if (query.numRowsAffected() > 0)
        {
            displayMessage("Entry deleted.");
        }
        else
        {
            displayMessage("Entry not found.");
        }
    }

    nameLineEdit->clear();
}

void PhoneBook::clearEntries()
{
    QMessageBox::StandardButton confirmButton = QMessageBox::question(this, "Clear Entries", "Are you sure you want to clear all entries?", QMessageBox::Yes | QMessageBox::No);
    if (confirmButton == QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("DELETE FROM phonebook");

        displayMessage("All entries cleared.");
    }
}


void PhoneBook::displayMessage(const QString& message)
{
    displayTextEdit->clear();
    displayTextEdit->setText(message);
}
