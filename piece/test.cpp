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
    int score = 0;
    int answer[CNO];
    int data[SETSIZE][CNO];
    int teacher[SETSIZE];
    int bestscore = 0;
    int bestanswer[CNO];

    srand(SEED);
    readdata(data, teacher);

    for (int i = 0; i < GENMAX; i++)
    {
        for (int j = 0; j < CNO; j++)
        {
            answer[j] = rand012();
        }

        score = calcscore(data, teacher, answer);

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

    /*最良解*/
    cout << "\nbestanswer\n";
    for (int j = 0; j < CNO; j++)
    {
        cout << bestanswer[j] << " ";
    }
    cout << ":score=" << bestscore;

    return 0;
}
