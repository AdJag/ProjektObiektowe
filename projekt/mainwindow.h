#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTime *time;
    int decrement(int a);
    bool state = false;


private slots:
//     void showTime();
    void timeOutSlot();

    void on_start_clicked();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
