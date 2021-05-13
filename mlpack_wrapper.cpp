#include "mlpack_wrapper.h"

MLPack_Wrapper::MLPack_Wrapper()
{

}

bool MLPack_Wrapper::SetDataSet(arma::mat *data_x, arma::mat *data_y)
{
    x_data = data_x;
    y_data = data_y;
    return true;
}
bool MLPack_Wrapper::Train_Single_Epoch()
{
    //model.Train(*x_data,
    //            *y_data,
    //            optimizer,
    //            ens::PrintLoss(),
    //            ens::ProgressBar(),
    //            ens::EarlyStopAtMinLoss(20));
    model.Train(*x_data, *y_data);
    return true;
}
bool MLPack_Wrapper::Construct_NetWork(vector<int> layer, vector<activation_function> types)
{
    if (x_data == nullptr || y_data == nullptr) return false;
    if (x_data->n_cols != y_data->n_cols) return false;
    FFN<MeanSquaredError<>, HeInitialization> model;
    model.Add<Linear<>>(x_data->n_rows, layer[0]);
    for (unsigned int i=0; i<layer.size(); i++)
    {
        if (types[i] == activation_function::LeakyReLU)
        {
            model.Add<LeakyReLU<>>();
        }
        if (i<layer.size()-1)
            model.Add<Linear<>>(layer[i], layer[i+1]);
        else
            model.Add<Linear<>>(layer[i], 1);

    }
    return true;
}

bool MLPack_Wrapper::Construct_NetWork(int n_inputs, vector<int> layer, vector<activation_function> types)
{

    model.Add<Linear<>>(n_inputs, layer[0]);
    for (unsigned int i=0; i<layer.size(); i++)
    {
        if (types[i] == activation_function::LeakyReLU)
        {
            model.Add<LeakyReLU<>>();
        }
        if (i<layer.size()-1)
            model.Add<Linear<>>(layer[i], layer[i+1]);
        else
            model.Add<Linear<>>(layer[i], 1);

    }
    return true;
}

arma::mat MLPack_Wrapper::Predict(arma::mat *data_x)
{

    arma::mat predOut;
    model.Predict(*data_x, predOut);
    return predOut;
}

bool MLPack_Wrapper::Initiate_Optimizer(int ndatacols)
{
    if (ndatacols!=0)
    {
        {   optimizer = ens::Adam(
            training_parameters.STEP_SIZE,
            ndatacols, // Batch size. Number of data points that are used in each
                        // iteration.
            0.9,        // Exponential decay rate for the first moment estimates.
            0.999,      // Exponential decay rate for the weighted infinity norm
                        // estimates.
            1e-8, // Value used to initialise the mean squared gradient parameter.
            ndatacols * training_parameters.EPOCHS, // Max number of iterations.
            training_parameters.STOP_TOLERANCE,            // Tolerance.
            true);
        }
    }
    else if (x_data!=nullptr)
    {
        if (x_data->n_cols!=0)
        {   optimizer = ens::Adam(
            training_parameters.STEP_SIZE,
            x_data->n_cols, // Batch size. Number of data points that are used in each
                        // iteration.
            0.9,        // Exponential decay rate for the first moment estimates.
            0.999,      // Exponential decay rate for the weighted infinity norm
                        // estimates.
            1e-8, // Value used to initialise the mean squared gradient parameter.
            x_data->n_cols * training_parameters.EPOCHS, // Max number of iterations.
            training_parameters.STOP_TOLERANCE,            // Tolerance.
            true);
        }
    }

    return true;
}
