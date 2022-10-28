#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "train.h"

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


void MainWindow::on_pbTrain_clicked()
{
    Train *train = new Train(ui->leDestination->text().toStdString(), ui->leTrainId->text().toInt(),
                             ui->dteDepartureTime->text().toStdString(), ui->lePlaces->text().toInt());
    ui->lbTrain->setText(QString::fromStdString(train->toString()));
    delete train;
}

