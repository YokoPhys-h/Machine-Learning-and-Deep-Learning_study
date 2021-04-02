/**
*    author:  YokoPhys
*    created: 2021/04/02 10:59:23
**/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <set>
#include <numeric>
#include <list>
#include <C:/Program Files/eigen-3.3.9/Eigen/Dense>
using namespace Eigen;
using namespace std;

vector<float> sigmoid(vector<float> &x)
{
    vector<float> result;
    result.resize(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        result[i] = 1. / (1 + exp(-x[i]));
    }
    return result;
}
MatrixXd sigmoid(MatrixXd &x)
{
    MatrixXd result(x.rows(), x.cols());

    for (int i = 0; i < x.rows(); i++)
    {
        for (int j = 0; j < x.cols(); j++)
        {
            result(i, j) = 1. / (1 + exp(-x(i, j)));
        }
    }

    return result;
}

vector<float> relu(vector<float> &x)
{
    vector<float> result;
    result.resize(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > 0)
        {
            result[i] = 1;
            return result;
        }
        else
        {
            result[i] = 0;
            return result;
        }
    }
    return result;
}