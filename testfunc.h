#ifndef TESTFUNC_H
#define TESTFUNC_H

#include "armadillo"

enum class func_type {logistic3, parabolic, sinsin};

class testfunc
{
public:
    testfunc();
    double func(const arma::vec &x);
    func_type function_type;
};

#endif // TESTFUNC_H
