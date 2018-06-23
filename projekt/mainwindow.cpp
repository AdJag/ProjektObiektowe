#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDebug>
#include "match.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->time = new QTime();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeOutSlot()
{

    if(this->state)
    {

        QTime time = ui->clock->time();
        int sec = time.second();
        int min = time.minute();
        sec = this->decrement(sec);
        if(sec == 0 && min == 0)
        {
            min = 0;
            sec = 0;
        }
        if(sec == 59)
            min = decrement(min);

        QTime returned = QTime(0,min,sec,0);
        ui->clock->setTime(returned);

        QString n1 = ui->name1->toPlainText();
        QString n2 = ui->name2->toPlainText();
        QString r1 = ui->result1->text();
        QString r2 = ui->result2->text();
        QString q = ui->quart->text();
        QString t = ui->clock->time().toString("mm:ss");

        match tmp = match(n1,n2,r1,r2,q,t);

        ui->score->setText(tmp.build());

    }

    qDebug() << this->state;


}

int MainWindow::decrement(int a)
{
    if(a == 0)
        return 59;
    else
        return --a;
}

void MainWindow::on_start_clicked()
{
    this->state = true;
}

void MainWindow::on_stop_clicked()
{
    this->state = false;
}
