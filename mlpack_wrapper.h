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

class MLPack_Wrapper
{
public:
    MLPack_Wrapper();
    bool SetDataSet(arma::mat *data_x, arma::mat *data_y);
    bool Train_One_Epoch();
    bool Construct_NetWork(vector<int> layer, vector<activation_function> types);

private:
    arma::mat *x_data = nullptr;
    arma::mat *y_data = nullptr;
};

#endif // MLPACK_WRAPPER_H
