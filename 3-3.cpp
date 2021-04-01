/**
*    author:  YokoPhys
*    created: 2021/04/01 20:45:14
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

int main()
{
    MatrixXd X(1, 2);
    X << 1, 2;

    MatrixXd Y(2, 3);
    Y << 1, 3, 5,
        2, 4, 6;

    cout << X * Y << endl;
    return 0;
}