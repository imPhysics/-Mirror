#define My_VECTOR
//���ļ����� ��ά���� ��������

#ifndef VS_STDARG
#define VS_STDARG
#include<stdarg.h>
#endif // !VS_STDARG

#ifndef VS_MEMORY
#define VS_MEMORY
#include<memory.h>
#endif // !VS_MEMORY

#ifndef VS_MATH
#define VS_MATH
#include<math.h>
#endif // !VS_MATH

//ʵ�������� double
class vector {
private:
	char eType = 'r';
	vector();
public:
	int Dimension = 0;//ά��
	double *pCoordinate = NULL;//����
	double *pBasis = NULL;//����

	vector(int, ...);
	~vector();

	operator vector_c();
	
	double length();//�޶�ʵ����
	vector Extend(int iLength, double *ipData = NULL);
	void Extendself(int iLength, double *ipData = NULL);
	vector Cut(int iStart, int iLength);
	void Cutself(int iStart, int iLength);
	double angle(vector x, vector y);
	vector operator *(double);
	vector operator /(double);
	vector operator -();
	vector operator =(vector &);

	//���������������ά�ȱ���һ��
	vector operator +(vector &);
	vector operator -(vector &);
	double operator *(vector &);//�ڻ�����������
	vector operator %(vector &);//���
	double distance(vector aff);
};

//���������� complex
class vector_c : vector {

};