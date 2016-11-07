#define My_COMPLEX
//���ļ������˸�������������

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