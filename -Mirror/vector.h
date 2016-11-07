#define My_VECTOR
//本文件定义 多维向量 及其运算

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

//实数域向量 double
class vector {
private:
	char eType = 'r';
	vector();
public:
	int Dimension = 0;//维度
	double *pCoordinate = NULL;//坐标
	double *pBasis = NULL;//基底

	vector(int, ...);
	~vector();

	operator vector_c();
	
	double length();//限定实数域
	vector Extend(int iLength, double *ipData = NULL);
	void Extendself(int iLength, double *ipData = NULL);
	vector Cut(int iStart, int iLength);
	void Cutself(int iStart, int iLength);
	double angle(vector x, vector y);
	vector operator *(double);
	vector operator /(double);
	vector operator -();
	vector operator =(vector &);

	//以下运算符，左右维度必须一致
	vector operator +(vector &);
	vector operator -(vector &);
	double operator *(vector &);//内积，基底正交
	vector operator %(vector &);//外积
	double distance(vector aff);
};

//复数域向量 complex
class vector_c : vector {

};