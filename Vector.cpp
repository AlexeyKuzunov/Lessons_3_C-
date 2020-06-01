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
		//создаем новый массив на 1 больше
		nlen = len + 1;
		nv = new double[nlen];
		//проверяем, что он создался
		if (nv)
		{
			//копируем данные из старого массива в новый
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
		//создаем новый массив на разность индексов меньше
		nlen = len - (j - i - 1);
		nv = new double[nlen];
		//проверяем, что он создался
		if (nv)
		{
			//копируем данные из старого массива 
			for (ic = 0; ic < len; ic++)
			{
				if ((ic > i) && (ic < j))	//если индекс входит в промежуток между i и j
					continue;				//не копируем
				nv[it] = v[ic];
				it++;
			}

			delete[] v;		//удаляем старый массив
			v = nv;			//копируем в переменную адрес нового массива
			len = nlen;		//устанавливаем размер нового массива
		}
	}
}
