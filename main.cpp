/******************************************************************************************************
������� ����� ������� �����, ����������� ����� ������� ���������� ������ 2�2.
����������  �  ���  �����������,  ����������,  �����������  �����������,��������
������������. �������������� �������� [], +=, -=, *=
******************************************************************************************************/

#include <stdlib.h>
#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

void main()
{
	Vector T(10);
	setlocale(LC_CTYPE, "rus");
	for (int i = 0; i < T.size(); i++)
	{
		T[i] = i;
		cout << T[i] << '\n';
	}
	cout << '\n';
	T.insert();
	T[T.size() - 1] = 10;
	for (int i = 0; i < T.size(); i++)
	{
		cout << T[i] << '\n';
	}
	cout << '\n';
	T.erase(3, 6);
	for (int i = 0; i < T.size(); i++)
	{
		cout << T[i] << '\n';
	}

	Matrix M(5);
	for (int i = 0; i < M.size(); i++)
	M += 1;

	system("pause");

}