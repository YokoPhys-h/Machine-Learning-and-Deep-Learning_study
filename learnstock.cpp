/**
*    author:  Haruto Yokoyama
*    created: 2021/03/02 20:25:10
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

/*記号定数の定義*/
#define OK 1
#define NG 0
#define SETSIZE 100
#define CNO 10
#define GENMAX 10000
#define SEED 32767

using namespace std;

/*関数のプロトタイプの宣言*/
void readdata(int data[SETSIZE][CNO], int teacher[SETSIZE]);

int rand012();                                                                //012を返す乱数生成
int calcscore(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO]); //解候補パターンのスコアの計算

int main()
{
    int i, j;
    int score = 0;
    int answer[CNO];
    int data[SETSIZE][CNO];
    int teacher[SETSIZE];
    int bestscore = 0;
    int bestanswer[CNO];

    srand(SEED); //乱数の初期化

    readdata(data, teacher); //学習データセットの読み込み

    /*解候補生成と検査*/
    for (int i = 0; i < GENMAX; i++)
    {
        /*解候補生成*/
        for (int j = 0; j < CNO; j++)
        {
            answer[j] = rand012();
        }

        /*検査*/
        score = calcscore(data, teacher, answer);

        /*最良スコアの更新*/
        if (score > bestscore)
        {
            for (int j = 0; j < CNO; j++)
            {
                bestanswer[j] = answer[j];
            }
            bestscore = score;

            for (int j = 0; j < CNO; j++)
            {
                cout << bestanswer[j] << " ";
            }
            cout << ":score=" << bestscore << "\n";
        }
    }

    cout << "\nbestscore\n";
    for (int j = 0; j < CNO; j++)
    {
        cout << bestanswer[j] << " ";
    }
    cout << ":score=" << bestscore;

    return 0;
}
