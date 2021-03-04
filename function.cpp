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

/*データセットの読み込み*/
void readdata(int data[SETSIZE][CNO], int teacher[SETSIZE])
{
    string file_name;
    cout << "please enter the datasets file name :";
    cin >> file_name;

    ifstream fin;
    fin.open(file_name);
    if (!fin)
    {
        cout << "failed to open this file.\n";
    }

    for (int i = 0; i < SETSIZE; i++)
    {
        for (int j = 0; j < CNO; j++)
        {
            fin >> data[i][j];
        }
        fin >> teacher[i];
    }
}

/*0,1,2のどれかを返す乱数*/
int rand012()
{
    int rnd;
    rnd = rand() % 3;
    return rnd;
}

/*解候補パターンのスコア*/
int calcscore(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO])
{
    int score = 0; /*スコア（0～SETSIZE点）*/
    int point;     /*一致した桁数(0～CNO)  */
    int i, j;

    for (i = 0; i < SETSIZE; ++i)
    {
        /*一致度計算*/
        point = 0;
        for (j = 0; j < CNO; ++j)
        {
            if (answer[j] == 2)
                point++; /*ワイルドカード*/
            else if (answer[j] == data[i][j])
                point++; /*一致*/
        }

        if ((point == CNO) && (teacher[i] == 1))
        {
            ++score;
        }
        else if ((point != CNO) && (teacher[i] == 0))
        {
            ++score;
        }
    }
    return score;
}