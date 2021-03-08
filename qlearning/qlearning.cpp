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

int rand100();
int rand01;
double rand1();
void printqvalue(int qvalue[NODENO]);
int selecta(int s, int qvalue[NODENO]);
int updateq(int s, int qvalue[NODENO]);

int main()
{
    int s; //状態
    int t; //時刻
    int qvalue[NODENO];

    srand(SEED);
    /*Q値の初期化*/
    for (int i = 0; i < NODENO; i++)
    {
        qvalue[i] = rand100();
    }
    printqvalue(qvalue);

    /*学習の本体*/
    for (int i = 0; i < GENMAX; i++)
    {
        s = 0; //行動の初期状態
        for (int t = 0; t < 3; t++)
        {
            s = selecta(s, qvalue);         //行動選択
            qvalue[s] = updateq(s, qvalue); //Q値の更新
        }
        /*Q値の出力*/
        printqvalue(qvalue);
    }

    return 0;
}