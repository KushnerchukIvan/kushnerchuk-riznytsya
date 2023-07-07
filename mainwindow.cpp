#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDate date1 = QDate::currentDate();
    QDate date2 = QDate::currentDate();
    ui->dateEdit->setDate(date1);
    ui->dateEdit_2->setDate(date2);
    ui->dateEdit->setDateRange(QDate(1000, 01, 01), QDate(3000, 1, 1));
    ui->dateEdit_2->setDateRange(QDate(1000, 01, 01), QDate(3000, 1, 1));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    QDate newdate = ui->dateEdit->date();
    if (newdate > ui->dateEdit_2->date())
    {ui->dateEdit_2->setDate(newdate);}
}


void MainWindow::on_dateEdit_2_userDateChanged(const QDate &date)
{
    QDate newdate = ui->dateEdit_2->date();
    if (newdate > ui->dateEdit->date())
    {ui->dateEdit->setDate(newdate);}
}


void MainWindow::on_pushButton_clicked()
{
    int days = ui->dateEdit->date().daysTo(ui->dateEdit_2->date());
    ui->label->setText("Кількфсть днів між датами: "+QString::number(days));
}

