#include <memory>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include "GradientDescent.h"

using std::fstream;

// �ݶ��½���dimΪ��������
GradientDescent::GradientDescent(int dim) {
	this->dimension = dim;
	this->theta = new double[dim];
	this->alpha = 0.1;
	this->iterDepth = 1000;
	for (int i = 0; i < dim; ++i) {
		theta[i] = 0;
	}
}

GradientDescent::~GradientDescent() {
	delete[]theta;
}


// ����alpha
void GradientDescent::setAlpha(double alp) {
	this->alpha = alp;
}

// ���õ�������
void GradientDescent::setIterdepth(int dep) {
	this->iterDepth = dep;
}


// ��rows�����ݽ���ѵ��
void GradientDescent::train(double **data, int rows) {
	printf("Process: Training started (%d rows).\n", rows);

	// ��ʱ��
	clock_t stime = clock();

	this->trainSize = rows;
	double *tmp = new double[dimension];
	this->trainData = data;
	// int lamda = 10000;
	for (int i = 0; i < iterDepth; ++i) {
		if (i == 800) {
			this->alpha = 0.001;
		}
		for (int pos = 0; pos < dimension; ++pos) {
			tmp[pos] = theta[pos] - alpha*getPartialDerivative(pos);
		}

		for (int pos = 0; pos < dimension; ++pos) {
			theta[pos] = tmp[pos];
		}
	}

	clock_t etime = clock();
	printf("Process: Training finished. (%f seconds)\n\n", (double)(etime - stime) / (clock_t)1000);
}

// ����ƫ��
double GradientDescent::getPartialDerivative(int j) {
	double res = 0;
	for (int i = 0; i < trainSize; ++i) {
		double h = 0;
		for (int pos = 0; pos < dimension; ++pos) {
			h += theta[pos] * trainData[i][pos];
		}

		res += (h - trainData[i][dimension])*trainData[i][j];
	}
	// printf("%lf/%d = %lf\n", res, trainSize, res / trainSize);
	return res / trainSize / 2;
}


// ����ϵ��theta
double* GradientDescent::getTheta() {
	return theta;
}

// �����ݽ���Ԥ����
double GradientDescent::verify(double **testData, int rows) {
	fstream os("result", fstream::out);
	int id = 0;
	for (int count = 0; count < rows; ++count) {
		double err = 0;
		double h = 0;
		for (int i = 0; i < dimension; ++i) {
			h += theta[i] * testData[count][i];
		}
		os << id++ << "," << h << std::endl;
	}

	return 0;
}

// ������֤����
double* GradientDescent::predict(double *lineData) {
	// uncomplete.

	return 0;
}