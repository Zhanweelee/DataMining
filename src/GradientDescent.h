#ifndef GRADIENT_DESCENT
#define GRADIENT_DESCENT

#include "Method.h"

class GradientDescent : public Method {
public:
	// �ݶ��½���dimΪ��������
	GradientDescent(int dim);

	~GradientDescent();

	// ��rows�����ݽ���ѵ��
	void train(double **data, int rows);

	// ����alpha
	void setAlpha(double alp);

	// ���õ�������
	void setIterdepth(int dep);

	// ����ϵ��theta
	double *getTheta();

	// �����ݽ���Ԥ����
	double *predict(double *data);

	// ������֤����
	double verify(double **data, int rows);

	// ����ƫ��
	double getPartialDerivative(int i);

private:
	// ѵ����
	double** trainData;

	// ϵ��
	double* theta;

	// ��������
	int dimension;

	// ѵ������С
	int trainSize;

	// ���ò���
	double alpha;

	// ���õ������
	int iterDepth;
};

#endif