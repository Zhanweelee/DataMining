#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

class BackPropagation
{
private:
	int _nInput;            //�����ڵ����
	int _nHide;             //������ڵ����
	int _nOutput;           //�����ڵ����

	double **_pplfWeight1;  //�����-������Ȩϵ��
	double **_pplfWeight2;  //������-�����Ȩϵ��

	double *_plfHideIn, *_plfHideOut;       //�������������������
	double *_plfOutputIn, *_plfOutputOut;   //������������������

private:
	double(*f)(double);    //�����

public:
	/**
	���캯��������һ��δ��ѵ����Bp����
	param nInput �����ڵ����
	param nHide ������ڵ����
	param nOutput �����ڵ����
	*/
	BackPropagation(int nInput, int nHide, int nOutput);

	/**
	�����������������е�Bp����
	*/
	virtual ~BackPropagation();

	/**
	ͨ��������������Bp�������ѵ��
	param pplfInput ����������
	param pplfDesire �������������
	����ֵ ѵ���Ƿ�����
	*/
	bool Train(int n, double **pplfInput, double **pplfDesire);

	/**
	ʹ�õ�ǰ��Bp�����ָ��ģʽ���з���,����Ľ���洢��plfOutput��
	param plfInput �������ģʽ
	param plfOutput ��������
	*/
	void Classify(double plfInput[], double plfOutput[]);
};
#endif