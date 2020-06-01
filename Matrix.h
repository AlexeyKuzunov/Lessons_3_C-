#pragma once
#include "Vector.h"
class Matrix :
	public Vector
{
protected:
	static const unsigned int Row = 2;
	static const unsigned int Col = 2;
	double*** v;   // [Row] [Col] = { { 0, 0}, {0, 0} };
public:
	Matrix(int N=0) : Vector(N) {}
	Matrix(const Matrix& temp) : Vector((const Vector&)temp) {}
	//~Matrix();
	int size() const;
	double& operator [] (int index);
	double operator [] (int index) const;
	friend Matrix& operator+=(Matrix& M, int d);
};

