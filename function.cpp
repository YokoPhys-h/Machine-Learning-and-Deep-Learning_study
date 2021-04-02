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