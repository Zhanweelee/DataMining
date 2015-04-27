#ifndef METHOD
#define METHOD

class Method {
public:
	Method() {};

	// 用rows行数据进行训练
	virtual void train(double **data, int rows)  = 0;

	// 对数据进行预测结果
	virtual double *predict(double *data) = 0;

	// 进行验证数据
	virtual double verify(double **data, int rows) = 0;

private:
	// 训练集
	double** trainData;

	// 参数个数
	int dimension;

	// 训练集大小
	int trainSize;
};

#endif