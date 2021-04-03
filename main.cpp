
#include "Dataset.hpp"

int main(void)
{
    //絶対パスを入力してください。
    Mnist mnist;
    mnist.readTrainingFile("C:/train-images-idx3-ubyte/train-images.idx3-ubyte");
    mnist.readLabelFile("C:/train-labels-idx1-ubyte/train-labels.idx1-ubyte");
}