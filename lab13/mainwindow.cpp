#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->pbClicked = false;
    ui->setupUi(this);
    connect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
    connect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenModalDialog(){
//    QDialog *modalWid = new QDialog(this);
//    modalWid->setModal(true);
//    QLabel *lb = new QLabel(modalWid);
//    lb->setText("Critical error");
//    lb->show();
//    modalWid->show();
    QMessageBox *modalWid = new QMessageBox(this);
    modalWid->setModal(true);
    modalWid->setText("Critical error");
    modalWid->show();
}

void MainWindow::OpenNotModalDialog(){
    QDialog *modalNotWid = new QDialog(this);
    QLabel *lb = new QLabel(modalNotWid);
    lb->setText(QFileDialog::getOpenFileName());
    lb->show();
    modalNotWid->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(this->pbClicked){
        ui->pushButton->setText("Disconnect");
        connect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
        connect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
        this->pbClicked = false;
        ui->pushButton->show();
    }
    else{
        ui->pushButton->setText("Disconnect");
        ui->pushButton->setText("Connect");
        disconnect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
        disconnect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
        this->pbClicked = true;
        ui->pushButton->show();
    }
}

