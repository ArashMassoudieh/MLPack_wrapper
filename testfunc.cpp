#include "testfunc.h"

testfunc::testfunc()
{

}

double testfunc::func(const arma::vec &x)
{
    if (function_type == func_type::logistic3)
        return exp(x[0])/(1+exp(x[0])) + exp(x[1])/(1+exp(x[1])) + exp(x[2])/(1+exp(x[2]));
    if (function_type == func_type::parabolic)
    {
        double sum = 0;
        for (int i=0; i<x.size(); i++)
            sum += pow(x[i],2);
        return sum;
    }
    if (function_type == func_type::sinsin)
    {
        return sin(x[0])*cos(x[1])*sin(x[2]);
    }
}
