#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "phonebook.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PhoneBook* phoneBook;
    QSqlDatabase m_database;


};
#endif // MAINWINDOW_H
