#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Reader.h"
#include "GradientDescent.h"
#include "BackPropagation.h"

using namespace std;

#define _CRT_SECURE_NO_WARNINGS


string train_file = "train_temp.csv";
string test_file = "test_temp.csv";

extern double sigmoid(double);
extern double antsigmoid(double);

int main() {
	// 读取文件
	Reader trainReader(train_file);
	// 获得训练集
	double** trainData = trainReader.process();
	
	/*
		// 梯度下降
		GradientDescent processor(trainReader.getCol() - 1); // 初始化参数个数
		processor.setAlpha(0.1); // 设置步长
		processor.setIterdepth(10); // 设置迭代深度
		processor.train(trainData, trainReader.getRow()); // 用所有数据进行训练
	*/

	int nPara = trainReader.getCol() - 1;
	int nTrainSize = trainReader.getRow();

	BackPropagation processor(nPara, nPara, 1);
	double **desire = new double*[nTrainSize];
	for (int i = 0; i < nTrainSize; ++i) {
		desire[i] = new double[1];
		desire[i][0] = sigmoid(trainData[i][nPara]);
	}

	processor.Train(nTrainSize, trainData, desire);

	// 读取文件
	Reader testReader(test_file);
	// 获得测试集
	double** testData = testReader.process();

	int nTestSize = testReader.getRow();

	double *plfOP = new double[1];
	double *result = new double[nTestSize];

	fstream fs("res.csv", fstream::out);
	fs << "id,reference" <<endl;

	// 计算测试集结果
	for (int i = 0; i < nTestSize; ++i) {
		processor.Classify(testData[i], plfOP);
		result[i] = plfOP[0];
		fs << i + 1 << "," << antsigmoid (result[i]) << endl;
	}
	fs.close();

	cout << endl;

	return 0;
}