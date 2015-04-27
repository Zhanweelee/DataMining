#ifndef GRADIENT_DESCENT
#define GRADIENT_DESCENT

#include "Method.h"

class GradientDescent : public Method {
public:
	// 梯度下降，dim为参数个数
	GradientDescent(int dim);

	~GradientDescent();

	// 用rows行数据进行训练
	void train(double **data, int rows);

	// 设置alpha
	void setAlpha(double alp);

	// 设置迭代层数
	void setIterdepth(int dep);

	// 返回系数theta
	double *getTheta();

	// 对数据进行预测结果
	double *predict(double *data);

	// 进行验证数据
	double verify(double **data, int rows);

	// 计算偏导
	double getPartialDerivative(int i);

private:
	// 训练集
	double** trainData;

	// 系数
	double* theta;

	// 参数个数
	int dimension;

	// 训练集大小
	int trainSize;

	// 设置步长
	double alpha;

	// 设置迭代深度
	int iterDepth;
};

#endif