#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class mainwindow :  public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
