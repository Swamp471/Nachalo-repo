#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QApplication>

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


void MainWindow::on_pushButtonOpen_clicked()
{
    ui->plainTextEdit->setReadOnly(false);
    QString fileName = QFileDialog::getOpenFileName(this, "Откуда взять файл");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Куда сохранить файл");
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QString s = ui->plainTextEdit->toPlainText();
        QByteArray ba = s.toUtf8();
        file.write(ba, ba.size());
    }
}


void MainWindow::on_pushButtonReadOnly_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Откуда взять файл");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QByteArray ba = file.readAll();
        ui->plainTextEdit->setPlainText(ba.data());
        ui->plainTextEdit->setReadOnly(true);
    }
}
