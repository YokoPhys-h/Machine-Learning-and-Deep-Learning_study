/**
*    author:  YokoPhys
*    created: 2021/04/01 18:51:27
**/

#define _USE_MATH_DEFINES

#include <C:/Users/横山遥乙/Desktop/Machine-Learning-and-Deep-Learning_study/eigen-3.3.9/Eigen/Dense>
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
using namespace std;

bool AND(vector<float> x, vector<float> w, float b)
{
    float temp;
    temp = inner_product(x.begin(), x.end(), w.begin(), 0.f) + b;

    if (temp <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool NAND(vector<float> x, vector<float> w, float b)
{
    float temp;
    temp = inner_product(x.begin(), x.end(), w.begin(), 0.f) + b;

    if (temp <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool OR(vector<float> x, vector<float> w, float b)
{
    float temp;
    temp = inner_product(x.begin(), x.end(), w.begin(), 0.f) + b;

    if (temp <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    vector<float> x = {0, 1};     //入力
    vector<float> w = {0.5, 0.5}; //重み
    float b = -0.7;               //バイアス

    cout << AND(x, w, b) << endl;
    return 0;
}
