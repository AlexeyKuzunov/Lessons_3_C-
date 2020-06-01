#include "Matrix.h"

/*
Matrix::Matrix(int N)
{
	if (N > 0)
		v = new double[N];
	if (v) len = N;
}
*/

int Matrix::size() const
{
	return Vector::size();
}

double& Matrix::operator[](int index)
{
	return Vector::operator[] (index);
}

double Matrix::operator[](int index) const
{
	return Vector::operator[](index);
}

Matrix& operator+=(Matrix& M, int d)
{
	for (int col = 0; col < 2; col++)
	{
		for (int row = 0; row < 2; row++)
		{
			M.v[1][col][row] = M.v[1][col][row] + d;
		}
	}
	return M;
}
