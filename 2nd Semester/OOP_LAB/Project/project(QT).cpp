#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QMap>

struct Entry
{
    QString name;
    QString number;
};

class PhoneBook : public QWidget
{
    Q_OBJECT

private:
    QMap<QString, QString> phonebook;
    QLineEdit *nameLineEdit;
    QLineEdit *numberLineEdit;
    QTextEdit *displayTextEdit;

public:
    PhoneBook(QWidget *parent = nullptr) : QWidget(parent)
    {
        QVBoxLayout *mainLayout = new QVBoxLayout;
        setLayout(mainLayout);

        QLabel *nameLabel = new QLabel("Name:");
        nameLineEdit = new QLineEdit;
        QHBoxLayout *nameLayout = new QHBoxLayout;
        nameLayout->addWidget(nameLabel);
        nameLayout->addWidget(nameLineEdit);

        QLabel *numberLabel = new QLabel("Number:");
        numberLineEdit = new QLineEdit;
        QHBoxLayout *numberLayout = new QHBoxLayout;
        numberLayout->addWidget(numberLabel);
        numberLayout->addWidget(numberLineEdit);

        QPushButton *addButton = new QPushButton("Add");
        QPushButton *searchButton = new QPushButton("Search");
        QPushButton *showAllButton = new QPushButton("Show All");
        QPushButton *updateButton = new QPushButton("Update");
        QPushButton *deleteButton = new QPushButton("Delete");

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(addButton);
        buttonLayout->addWidget(searchButton);
        buttonLayout->addWidget(showAllButton);
        buttonLayout->addWidget(updateButton);
        buttonLayout->addWidget(deleteButton);

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
    }

private slots:
    void addEntry()
    {
        QString name = nameLineEdit->text();
        QString number = numberLineEdit->text();

        if (name.isEmpty() || number.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Please enter a name and number.");
            return;
        }

        if (phonebook.contains(name))
        {
            int result = QMessageBox::question(this, "Contact already exists",
                                               "Contact already exists. Do you want to update the number?",
                                               QMessageBox::Yes | QMessageBox::No);

            if (result == QMessageBox::Yes)
            {
                phonebook[name] = number;
                displayMessage("Contact updated.");
            }
            else
            {
                displayMessage("Returning back to Menu.");
            }
        }
        else
        {
            phonebook[name] = number;
            displayMessage("Entry added.");
        }

        nameLineEdit->clear();
        numberLineEdit->clear();
    }

    void searchEntry()
    {
        QString name = nameLineEdit->text();

        if (name.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Please enter a name to search.");
            return;
        }

        if (phonebook.contains(name))
        {
            QString number = phonebook[name];
            displayMessage(QString("%1's number is %2").arg(name).arg(number));

        }
        else
        {
            displayMessage("Contact not found.");
        }

        nameLineEdit->clear();
    }

    void showAllEntries()
    {
        if (phonebook.isEmpty())
        {
            displayMessage("Phonebook is empty.");
        }
        else
        {
            QString entries;
            for (const QString &name : phonebook.keys())
            {
                QString number = phonebook[name];
                displayMessage(QString("%1's number is %2").arg(name).arg(number));

            }
            displayMessage(entries);
        }
    }

    void updateEntry()
    {
        QString name = nameLineEdit->text();

        if (name.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Please enter a name to update.");
            return;
        }

        if (phonebook.contains(name))
        {
            QString number = numberLineEdit->text();
            phonebook[name] = number;
            displayMessage("Contact updated.");
        }
        else
        {
            displayMessage("Contact not found.");
        }

        nameLineEdit->clear();
        numberLineEdit->clear();
    }

    void deleteEntry()
    {
        QString name = nameLineEdit->text();

        if (name.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Please enter a name to delete.");
            return;
        }

        if (phonebook.contains(name))
        {
            phonebook.remove(name);
            displayMessage("Contact deleted.");
        }
        else
        {
            displayMessage("Contact not found.");
        }

        nameLineEdit->clear();
    }

private:
    void displayMessage(const QString &message)
    {
        displayTextEdit->append(message);
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PhoneBook phoneBook;
    phoneBook.show();

    return app.exec();
}
