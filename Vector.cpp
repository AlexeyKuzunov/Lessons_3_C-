#include "Vector.h"
#include <iostream>
#include <stdlib.h>
#include<iomanip>
#include <cassert>

int Vector::size() const
{
	return len;
}

Vector::Vector(int N = 0) : v(0), len(0)
{
	if (N > 0)
		v = new double[N];
	if (v) len = N;
}

Vector::Vector(const Vector& temp) : v(0), len(0)
{
	if (temp.len > 0)
		v = new double[temp.len];
	if (v) {
		len = temp.len;
		for (int i = 0; i < len; i++)
		{
			v[i] = temp.v[i];
		}
	}
}

Vector::~Vector()
{
	delete[] v;
}

double& Vector::operator[](int index)
{
	assert(index >= 0 && index < len);
	return v[index];
}

double Vector::operator[](int index) const
{
	assert(index >= 0 && index < len);
	return v[index];
}

void Vector::insert()
{
	double* nv;
	int i, nlen;

	if (len > 0) {
		//������� ����� ������ �� 1 ������
		nlen = len + 1;
		nv = new double[nlen];
		//���������, ��� �� ��������
		if (nv)
		{
			//�������� ������ �� ������� ������� � �����
			for (i = 0; i < len; i++)
			{
				nv[i] = v[i];
			}
			delete[] v;
			v = nv;
			len = nlen;
		}
	}
}

void Vector::erase(int i, int j)
{
	double* nv;
	int ic, nlen, it = 0;
	if ((len > 0) || ((j - i) > 1))
	{
		//������� ����� ������ �� �������� �������� ������
		nlen = len - (j - i - 1);
		nv = new double[nlen];
		//���������, ��� �� ��������
		if (nv)
		{
			//�������� ������ �� ������� ������� 
			for (ic = 0; ic < len; ic++)
			{
				if ((ic > i) && (ic < j))	//���� ������ ������ � ���������� ����� i � j
					continue;				//�� ��������
				nv[it] = v[ic];
				it++;
			}

			delete[] v;		//������� ������ ������
			v = nv;			//�������� � ���������� ����� ������ �������
			len = nlen;		//������������� ������ ������ �������
		}
	}
}
