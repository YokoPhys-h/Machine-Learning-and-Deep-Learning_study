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
#include <map>
#include <C:/Program Files/eigen-3.3.9/Eigen/Dense>
using namespace Eigen;
using namespace std;

//シグモイド関数
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
//////////////////////////////////////////////////////////

//relu関数
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
/////////////////////////////////////////////////////////////////////

//恒等関数
MatrixXd identity_function(MatrixXd &x)
{
    MatrixXd result(x.rows(), x.cols());

    for (int i = 0; i < x.rows(); i++)
    {
        for (int j = 0; j < x.cols(); j++)
        {
            result(i, j) = x(i, j);
        }
    }

    return result;
}
/////////////////////////////////////////////////////////////

//ソフトマックス関数
MatrixXd softmax(MatrixXd &x)
{
    MatrixXd c(x.rows(), x.cols());
    MatrixXd test(x.rows(), x.cols());
    MatrixXd exp_x(x.rows(), x.cols());
    double sum_exp_x;
    MatrixXd result(x.rows(), x.cols());

    for (int i = 0; i < x.rows(); i++)
    {
        for (int j = 0; j < x.cols(); j++)
        {
            c(i, j) = x.maxCoeff();
        }
    }
    test = x - c;

    for (int i = 0; i < x.rows(); i++)
    {
        for (int j = 0; j < x.cols(); j++)
        {
            exp_x(i, j) = exp(test(i, j)); //オーバーフロー対策
        }
    }

    sum_exp_x = exp_x.sum();

    result = exp_x / sum_exp_x;
    return result;
}

/*3層ニューラルネットワーク*/
//初期値の格納
map<string, MatrixXd> init_network()
{
    /*各ニューロンの初期値*/
    /////////////////////////
    //0層
    MatrixXd b1(1, 3);
    MatrixXd W1(2, 3);

    W1 << 0.1, 0.3, 0.5,
        0.2, 0.4, 0.6;

    b1 << 0.1, 0.2, 0.3;

    //1層
    MatrixXd W2(3, 2);
    MatrixXd b2(1, 2);
    W2 << 0.1, 0.4,
        0.2, 0.5,
        0.3, 0.6;

    b2 << 0.1, 0.2;

    //2層
    MatrixXd W3(2, 2);
    MatrixXd b3(1, 2);
    W3 << 0.1, 0.3,
        0.2, 0.4;

    b3 << 0.1, 0.2;
    /////////////////////////
    map<string, MatrixXd> network;
    network["W1"] = W1;
    network["b1"] = b1;
    network["W2"] = W2;
    network["b2"] = b2;
    network["W3"] = W3;
    network["b3"] = b3;

    return network;
}
//信号出力
MatrixXd forward(MatrixXd X)
{
    map<string, MatrixXd> network = init_network();
    MatrixXd W1 = network["W1"];
    MatrixXd b1 = network["b1"];
    MatrixXd W2 = network["W2"];
    MatrixXd b2 = network["b2"];
    MatrixXd W3 = network["W3"];
    MatrixXd b3 = network["b3"];

    //0層から1層
    MatrixXd a1 = X * W1 + b1;
    //1層から2層
    MatrixXd z1 = sigmoid(a1);
    MatrixXd a2 = z1 * W2 + b2;
    MatrixXd z2 = sigmoid(a2);

    //出力層
    MatrixXd a3 = z2 * W3 + b3;

    MatrixXd y = identity_function(a3);

    return y;
}
///////////////////////////////////////////////////////////////