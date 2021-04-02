/**
*    author:  YokoPhys
*    created: 2021/04/01 21:09:04
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

vector<float> sigmoid(vector<float> &x);

int main()
{
    vector<float> x = {-1, 1, 0};
    vector<float> result(3);
    result = sigmoid(x);
    for (int i = 0; i < x.size(); i++)
    {
        cout << result[i] << " " << endl;
    }
    return 0;
}