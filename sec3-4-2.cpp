/**
*    author:  YokoPhys
*    created: 2021/04/02 11:33:46
**/

#include "sec3-4-2parameters.h"
int main()
{
    MatrixXd x(1, 2);
    x << 1.0, 0.5;

    MatrixXd y = forward(x);

    cout << y << endl;
    return 0;
}