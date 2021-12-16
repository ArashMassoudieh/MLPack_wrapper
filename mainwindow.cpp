#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mlpack_wrapper.h"
#include "plotter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MLPack_Wrapper MLP;
    vector<int> layers;
    layers.push_back(8);
    layers.push_back(8);
    layers.push_back(8);
    vector<activation_function> types;
    types.push_back(activation_function::LeakyReLU);
    types.push_back(activation_function::LeakyReLU);
    types.push_back(activation_function::Linear);
    arma::mat x_data(3,0);
    arma::mat y_data(1,0);
    MLP.SetDataSet(&x_data,&y_data);
    MLP.Construct_NetWork(3,layers,types);
    MLP.Initiate_Optimizer();
    for (int k=0; k<10; k++)
    {   cout<<"k="<<k<<endl;
        for (int i=0; i<100; i++)
        {

            arma::mat x = arma::mat(3,1, arma::fill::randu);
            x_data.resize(3,(i+1)+k*100);
            y_data.resize(1,(i+1)+k*100);
            x_data(0,i+k*100)=(x(0,0)*0.1+double(k)/100-0.5)*3;
            x_data(1,i+k*100)=(x(1,0)-0.5)*3;
            x_data(2,i+k*100)=(x(2,0)-0.5)*3;
            y_data(0,i+k*100)=(exp(x_data(0,i+k*100))/(1+exp(x_data(0,i+k*100))) + exp(x_data(1,i+k*100))/(1+exp(x_data(1,i+k*100))) + exp(x_data(2,i+k*100))/(1+exp(x_data(2,i+k*100))))/3.0;

        }

        for (unsigned int i=0; i<1; i++)
        {   MLP.Train_Single_Epoch();

            arma::mat predOut = MLP.Predict(&x_data);

            bool saved = data::Save("data.csv", y_data, true);
            saved = data::Save("results.csv", predOut, true);
            data::Save("model.xml", "model", MLP.Model(), false);
            CTimeSeries<double> modelvspred(y_data,predOut);

            Plotter *plt = new Plotter(this);
            plt->AddData(modelvspred, QCPScatterStyle::ScatterShape::ssCircle);
            plt->AddAgreementLine();
            plt->show();
            cout<<"MSE="<<MSE(y_data,predOut)<<endl;

        }
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

