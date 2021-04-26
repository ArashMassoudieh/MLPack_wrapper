#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ANN_Regress.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ANN_Regress();
}

MainWindow::~MainWindow()
{
    delete ui;
}

