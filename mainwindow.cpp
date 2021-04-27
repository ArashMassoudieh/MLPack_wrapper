#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mlpack_wrapper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MLPack_Wrapper MLP;
    vector<int> layers;
    layers.push_back(4);
    layers.push_back(4);
    vector<activation_function> types;
    types.push_back(activation_function::LeakyReLU);
    types.push_back(activation_function::LeakyReLU);
    MLP.Construct_NetWork(layers,types);
    //ANN_Regress();
}

MainWindow::~MainWindow()
{
    delete ui;
}

