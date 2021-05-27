#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    calculator = new Calculator(this);
    setCentralWidget(calculator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

