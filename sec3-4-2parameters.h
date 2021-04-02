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
vector<float> sigmoid(vector<float> &x);
MatrixXd sigmoid(MatrixXd &x);

//恒等関数
MatrixXd identity_function(MatrixXd &x);

//3層ニューラルネットワーク
//初期値格納
map<string, MatrixXd> init_network();
//入力信号の出力
MatrixXd forward(MatrixXd X);
