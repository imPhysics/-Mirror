#define My_COMPLEX
//本文件定义了复数，及其运算

#ifndef VS_MATH
#define VS_MATH
#include<math.h>
#endif // !VS_MATH

class complex {
public:
	double real = 0;
	double imag = 0;

	complex();
	complex(double, double);
	complex operator =(complex &);
	complex operator +(complex &);
	complex operator -(complex &);
	complex operator *(complex &);
	complex operator /(complex &);
	double Length();
};