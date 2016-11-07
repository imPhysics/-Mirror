#include "vector.h"

vector::vector() {}

vector::vector(int iDataSum, ...)
{
	if (!iDataSum) throw L"参数异常";
	this->pData = new double[iDataSum];
	memset(this->pData, (double)0.0, iDataSum * sizeof(double));
	va_list ap;
	va_start(ap, iDataSum);
	for (int i = 0; i < iDataSum; i++) {
		(this->pData)[i] = va_arg(ap, double);
	}
	va_end(ap);
}

vector::~vector()
{
	if (this->pData)
		delete[] this->pData;
}

vector::operator vector_c()
{

}

double vector::length() {
	double rNum = 0.0;
	for (int i = 0; i < this->Dimension; i++) {
		rNum += pow(this->pData[i], 2);
	}
	return sqrt(rNum);
}

vector vector::Extend(int iLength, double *ipData = NULL)
{
	if (iLength < 0) throw L"参数异常";
	vector rVector = vector();
	rVector.Dimension = this->Dimension + iLength;
	rVector.pData = new double[rVector.Dimension];
	for (int i = 0; i < this->Dimension; i++)
		rVector.pData[i] = this->pData[i];
	for (int i = 0; i < iLength; i++)
		rVector.pData[this->Dimension + i] = (ipData ? this->pData[i] : (double)0.0);
	return rVector;
}

void  vector::Extendself(int iLength, double * ipData = NULL)
{
	if (iLength < 0) throw L"参数异常";
	int rDimension = this->Dimension + iLength;
	double * rpData = new double[rDimension];
	for (int i = 0; i < this->Dimension; i++)
		rpData[i] = this->pData[i];
	for (int i = 0; i < iLength; i++)
		rpData[this->Dimension + i] = (ipData ? ipData[i] : (double)0.0);
	this->Dimension = rDimension;
	delete[] this->pData;
	this->pData = rpData;
}

vector vector::Cut(int iStart, int iLength)
{
	if (iLength <= 0 || iStart + iLength - 1 > this->Dimension) throw L"参数异常";
	vector rVector = vector();
	rVector.Dimension = iLength;
	rVector.pData = new double[iLength];
	for (int i = 0; i < iLength; i++)
		rVector.pData[i] = this->pData[iStart + i - 1];
	return rVector;
}

void vector::Cutself(int iStart, int iLength)
{
	if (iLength <= 0 || iStart + iLength - 1 > this->Dimension) throw L"参数异常";
	double * rpData = new double[iLength];
	for (int i = 0; i < iLength; i++)
		rpData[i] = this->pData[iStart + i - 1];
	delete[] this->pData;
	this->pData = rpData;
	this->Dimension = iLength;
}

vector vector::operator*(double div)
{
	vector rVector = vector();
	rVector.Dimension = this->Dimension;
	for (int i = 0; i < rVector.Dimension; i++)
		rVector.pData[i] = this->pData[i] * div;
	return rVector;
}

vector vector::operator/(double div)
{
	vector rVector = vector();
	rVector.Dimension = this->Dimension;
	for (int i = 0; i < rVector.Dimension; i++)
		rVector.pData[i] = this->pData[i] / div;
	return rVector;
}

vector vector::operator-()
{
	vector rVector = vector();
	rVector.Dimension = this->Dimension;
	for (int i = 0; i < rVector.Dimension; i++)
		rVector.pData[i] = -this->pData[i];
	return rVector;
}

vector vector::operator=(vector &aff)
{
	double * rpData = aff.pData;
	if (this->pData)
		delete[] this->pData;
	this->Dimension = aff.Dimension;
	this->pData = rpData;
	return *this;
}

vector vector::operator+(vector &aff)
{
	if (this->Dimension != aff.Dimension)
		throw L"向量间维数不一致";
	vector rVector = vector();
	rVector.Dimension = this->Dimension;
	for (int i = 0; i < rVector.Dimension; i++)
		rVector.pData[i] = this->pData[i] + aff.pData[i];
	return rVector;
}

vector vector::operator-(vector & aff)
{
	if (this->Dimension != aff.Dimension)
		throw L"向量间维数不一致";
	vector rVector = vector();
	rVector.Dimension = this->Dimension;
	for (int i = 0; i < rVector.Dimension; i++)
		rVector.pData[i] = this->pData[i] - aff.pData[i];
	return rVector;
}

double vector::operator*(vector &aff)//内积
{
	if (this->Dimension != aff.Dimension)
		throw L"向量间维数不一致";
	double rNum = (double)0.0;
	for (int i = 0; i < this->Dimension; i++)
		rNum += this->pData[i] * aff.pData[i];
	return rNum;
}

vector vector::operator%(vector &aff)//外积
{
	if (this->Dimension != aff.Dimension) throw L"向量间维数不一致";
	if (this->Dimension < 3) throw L"2维空间内无外积";
	//需要行列式定义

	return vector();
}

double vector::distance(vector aff) {
	return ((*this) - aff).length();
}