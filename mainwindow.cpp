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
    arma::mat x_data(3,0);
    arma::mat y_data(1,0);
    for (int i=0; i<100; i++)
    {
        x_data.resize(3,i+1);
        y_data.resize(1,i+1);
        x_data(0,i)=i*0.2;
        x_data(1,i)=i*0.3;
        x_data(2,i)=-i*0.1;
        y_data(0,i)=exp(x_data(0,i))/(1+x_data(0,i));

    }
    MLP.Construct_NetWork(3,layers,types);
    //ANN_Regress();
}

MainWindow::~MainWindow()
{
    delete ui;
}

