#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList table_list;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("myfirstdb");
    db.setUserName("testuser");
    db.setPassword("testuser1213");
    if (db.open())
    {
        qDebug() << "Connected!";
        table_list =db.tables();
        qDebug()<<"Tables :  "<<table_list.at(0) +"   "+table_list.at(1);
    }
    else
    {
        qDebug() << "Failed to connect.!";

        return 0;

    }
    QString command ="SELECT username FROM hulusi";
    QSqlQuery query(db);
    if(query.exec(command))
    {
        while (query.next()) {

            QString name =query.value("username").toString();
            qDebug()<< name;
        }
    }
    else
    {
        qDebug()<< "Olmadı";
    }



    return a.exec();
}
