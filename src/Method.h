#ifndef METHOD
#define METHOD

class Method {
public:
	Method() {};

	// ��rows�����ݽ���ѵ��
	virtual void train(double **data, int rows)  = 0;

	// �����ݽ���Ԥ����
	virtual double *predict(double *data) = 0;

	// ������֤����
	virtual double verify(double **data, int rows) = 0;

private:
	// ѵ����
	double** trainData;

	// ��������
	int dimension;

	// ѵ������С
	int trainSize;
};

#endif