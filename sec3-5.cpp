/**
*    author:  YokoPhys
*    created: 2021/04/02 18:53:55
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

MatrixXd softmax(MatrixXd &x);

int main()
{
    MatrixXd a(1, 3);
    a << 0.3, 2.9, 4.0;
    cout << softmax(a) << endl;

    return 0;
}