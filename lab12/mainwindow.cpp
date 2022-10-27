#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}


void MainWindow::on_pb2_clicked()
{
    ui->lbl2->setNum(ui->lineEdit1->text().toDouble() + ui->lineEdit2->text().toDouble());
}


void MainWindow::on_pbExit_clicked()
{
    QApplication::exit();
}

