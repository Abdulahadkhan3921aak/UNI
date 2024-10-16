#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget::setWindowTitle("Phonebook");
    QWidget::setWindowIcon(QIcon(":/icon1.png"));

    phoneBook = new PhoneBook(this);  // Create an instance of PhoneBook

    // Add phoneBook to the main layout of the window
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(phoneBook);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Establish a connection to the SQLite database
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("phonebook.db");

    // Open the database
    if (!m_database.open()) {
        qDebug() << "Error: Failed to open database";
    }

    // Create the phonebook table if it doesn't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS phonebook (id INTEGER AUTOINCREMENT, name TEXT PRIMARY KEY, number TEXT)");

}


MainWindow::~MainWindow()
{
}

