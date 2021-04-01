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

void readdata(int data[SETSIZE][CNO], int teacher[100])
{
    string file_name;
    cout << "please enter your datasets file name :";
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

int rand012(void)
{
    int rnd;
    rnd = rand() % 3;
    return rnd;
}

int calcscore(int data[SETSIZE][CNO], int teacher[SETSIZE], int answer[CNO])
{
    int score = 0;
    int point;

    for (int i = 0; i < SETSIZE; i++)
    {
        point = 0;
        for (int j = 0; j < CNO; j++)
        {
            if (answer[j] == data[i][j])
            {
                point++;
            }
            else if (answer[j] == 2)
            {
                point++;
            }
        }

        if ((point == CNO) && (teacher[i] == 1))
        {
            score++;
        }
        else if ((point != CNO) && (teacher[i] == 0))
        {
            score++;
        }
    }
    return score;
}