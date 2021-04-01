/**
*    author:  Haruto Yokoyama
*    created: 2021/03/08 11:28:29
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
using namespace std;

#define GENMAX 1000 //学習の繰り返し回数
#define NODENO 15   //Q値のノード数
#define ALPHA 0.1   //学習係数
#define GAMMA 0.9   //割引率
#define EPSILON 0.3 //行動選択のランダム性を決定
#define SEED 32767  //乱数のシード

/*Q値を出力*/
void printqvalue(int qvalue[NODENO])
{
    for (int i = 1; i < NODENO; i++)
    {
        cout << qvalue[i] << " ";
    }
    cout << "\n";
}

/*0~1の実数を返す乱数関数*/
double rand1(void)
{
    double rnd;
    rnd = (double)rand() / RAND_MAX;
    return rnd;
}

/*0または1を返す乱数関数*/
int rand01(void)
{
    int rnd;
    rnd = rand() % 2;
    return rnd;
}

/*0~100を返す乱数関数*/
int rand100(void)
{
    int rnd;
    rnd = rand() % 101;
    return rnd;
}

/*Q値の更新*/
int updateq(int s, int qvalue[NODENO])
{
    int qv;
    int qmax;

    /*最下段の場合*/
    if (s > 6)
    {
        if (s == 14)
        {
            qv = qvalue[s] + ALPHA * (1000 - qvalue[s]);
        }
        else
        {
            qv = qvalue[s];
        }
    }
    /*最下段以外*/
    else
    {
        if ((qvalue[2 * s + 1]) > (qvalue[2 * s + 2]))
        {
            qmax = qvalue[2 * s + 1];
        }
        else
        {
            qmax = qvalue[s * s + 2];
        }
        qv = qvalue[s] + ALPHA * (GAMMA * qmax - qvalue[s]);
    }

    return qv;
}

/*行動の選択*/
int selecta(int olds, int qvalue[NODENO])
{
    int s;

    /*ε-greedy法による行動選択*/
    if (rand1() < EPSILON)
    {
        /*ランダムに行動*/
        if (rand01() == 0)
        {
            s = 2 * olds + 1;
        }
        else
        {
            s = 2 * olds + 2;
        }
    }
    else
    {
        /*Ｑ値最大値を選択*/
        if ((qvalue[2 * olds + 1]) > (qvalue[2 * olds + 2]))
        {
            s = 2 * olds + 1;
        }
        else
        {
            s = 2 * olds + 2;
        }
    }

    return s;
}
