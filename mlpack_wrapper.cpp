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
bool MLPack_Wrapper::Train_One_Epoch()
{
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

    FFN<MeanSquaredError<>, HeInitialization> model;
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
