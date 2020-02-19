#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("myfirstdb");
    db.setUserName("testuser");
    db.setPassword("testuser1213");

    if (db.open())
    {
        qDebug() << "Connected!";
    }
    else
    {
        qDebug() << "Failed to connect.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();
    QString password = ui->passwordInput->text();

    qDebug() << username << password;

    QString command = "SELECT * FROM hulusi WHERE username = '" + username + "' AND pasword = '" + password+"'";

    QSqlQuery query(db);
    if (query.exec(command))
    {

        if (query.size() > 0)
        {
            QMessageBox::information(this, "Login success.", "You have successfully logged in!");

        }
        else
        {
            QMessageBox::information(this, "Login failed.", "ID or Password must be wrong.\n Please try again...");
            ui->userInput->clear();
            ui->passwordInput->clear();
        }
    }
    else
    {
        qDebug()<< " Query not allowed " << query.lastError();

    }
}
