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
	// ��ȡ�ļ�
	Reader trainReader(train_file);
	// ���ѵ����
	double** trainData = trainReader.process();
	
	/*
		// �ݶ��½�
		GradientDescent processor(trainReader.getCol() - 1); // ��ʼ����������
		processor.setAlpha(0.1); // ���ò���
		processor.setIterdepth(10); // ���õ������
		processor.train(trainData, trainReader.getRow()); // ���������ݽ���ѵ��
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

	// ��ȡ�ļ�
	Reader testReader(test_file);
	// ��ò��Լ�
	double** testData = testReader.process();

	int nTestSize = testReader.getRow();

	double *plfOP = new double[1];
	double *result = new double[nTestSize];

	fstream fs("res.csv", fstream::out);
	fs << "id,reference" <<endl;

	// ������Լ����
	for (int i = 0; i < nTestSize; ++i) {
		processor.Classify(testData[i], plfOP);
		result[i] = plfOP[0];
		fs << i + 1 << "," << antsigmoid (result[i]) << endl;
	}
	fs.close();

	cout << endl;

	return 0;
}