#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Mnist
{
public:
    vector<vector<double>> readTrainingFile(string filename);
    vector<double> readLabelFile(string filename);
};