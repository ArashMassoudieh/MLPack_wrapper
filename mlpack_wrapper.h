#ifndef MLPACK_WRAPPER_H
#define MLPACK_WRAPPER_H

#include <mlpack/prereqs.hpp>
#include <mlpack/core.hpp>
#include <mlpack/methods/ann/loss_functions/mean_squared_error.hpp>
#include <mlpack/core/data/scaler_methods/min_max_scaler.hpp>
#include <mlpack/methods/ann/layer/layer.hpp>
#include <mlpack/core/data/split_data.hpp>
#include <mlpack/methods/ann/ffn.hpp>
#include <mlpack/methods/ann/init_rules/he_init.hpp>
#include <ensmallen.hpp>
#include <vector>


using namespace mlpack;
using namespace mlpack::ann;
using namespace ens;
using namespace std;

enum class activation_function {ReLU, Linear, LeakyReLU};

struct meta_parameters
{
    int EPOCHS = 1;
    double STEP_SIZE = 5e-2;
    int BATCH_SIZE = 32;
    double STOP_TOLERANCE = 1e-8;
};

class MLPack_Wrapper
{
public:
    MLPack_Wrapper();
    bool SetDataSet(arma::mat *data_x, arma::mat *data_y);
    bool Initiate_Optimizer();
    bool Train_Single_Epoch();
    bool Construct_NetWork(vector<int> layer, vector<activation_function> types);
    bool Construct_NetWork(int n_inputs, vector<int> layer, vector<activation_function> types);

private:
    arma::mat *x_data = nullptr;
    arma::mat *y_data = nullptr;
    ens::Adam optimizer;
    meta_parameters training_parameters;
};

#endif // MLPACK_WRAPPER_H
