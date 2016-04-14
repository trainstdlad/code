#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("My first programm!");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_swap_clicked()
{
    QString str=ui->lineEdit->text();
    ui->lineEdit->setText(ui->lineEdit_2->text());
    ui->lineEdit_2->setText(str);
}


void MainWindow::on_copyLeftRight_clicked()
{
    ui->lineEdit_2->setText(ui->lineEdit->text());
}


void MainWindow::on_copyRightLeft_clicked()
{
    ui->lineEdit->setText((ui->lineEdit_2->text()));
}

void MainWindow::on_clearStrLeft_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_clearStrRight_clicked()
{
    ui->lineEdit_2->clear();
}


void MainWindow::on_clearAll_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

