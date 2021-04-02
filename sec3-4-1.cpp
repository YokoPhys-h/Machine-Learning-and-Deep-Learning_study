/**
*    author:  YokoPhys
*    created: 2021/04/02 11:33:46
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

vector<float> sigmoid(vector<float> &x);
MatrixXd sigmoid(MatrixXd &x);
MatrixXd identity_function(MatrixXd &x);

int main()
{
    //0層から1層
    MatrixXd A1(1, 3);
    MatrixXd X(1, 2);
    MatrixXd B1(1, 3);
    MatrixXd W1(2, 3);

    X << 1, 0.5;

    W1 << 0.1, 0.3, 0.5,
        0.2, 0.4, 0.6;

    B1 << 0.1, 0.2, 0.3;

    A1 = X * W1 + B1;

    //1層から2層
    MatrixXd Z1 = sigmoid(A1);
    MatrixXd W2(3, 2);
    MatrixXd B2(1, 2);

    W2 << 0.1, 0.4,
        0.2, 0.5,
        0.3, 0.6;

    B2 << 0.1, 0.2;

    MatrixXd A2 = Z1 * W2 + B2;
    MatrixXd Z2 = sigmoid(A2);

    //出力層
    MatrixXd W3(2, 2);
    MatrixXd B3(1, 2);

    W3 << 0.1, 0.3,
        0.2, 0.4;

    B3 << 0.1, 0.2;

    MatrixXd A3 = Z2 * W3 + B3;
    //MatrixXd Y = identity_function(A3);

    cout << A3 << endl;

    return 0;
}