#include "complex.h"

complex::complex() {}

complex::complex(double iReal, double iImag)
{
	this->real = iReal;
	this->imag = iImag;
}

complex complex::operator=(complex &aff)
{
	this->real = aff.real;
	this->imag = aff.imag;
	return *this;
}

complex complex::operator+(complex &aff)
{
	return complex(this->real + aff.real, this->imag + aff.imag);
}

complex complex::operator-(complex &aff)
{
	return complex(this->real - aff.real, this->imag - aff.imag);
}

complex complex::operator*(complex &aff)
{
	complex rComplex;
	rComplex.real = this->real * aff.real - this->imag * aff.imag;
	rComplex.imag = this->real * aff.imag + this->imag * aff.real;
	return rComplex;
}

complex complex::operator/(complex &aff)
{
	complex rComplex;
	double div = pow(aff.real, 2) + pow(aff.imag, 2);
	rComplex.real = (this->real * aff.real + this->imag * aff.imag) / div;
	rComplex.imag = (this->imag * aff.real - this->real * aff.imag) / div;
	return rComplex;
}

double complex::Length()
{
	return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}
