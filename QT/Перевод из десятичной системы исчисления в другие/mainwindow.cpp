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
    int value = ui->inputLineEdit->text().toInt();
    int base = 2;
    if (ui->radioButton_2->isChecked()) base = 8;
    else if (ui->radioButton_3->isChecked()) base = 16;
    ui->answerLabel->setText(QString::number(value, base));
}
