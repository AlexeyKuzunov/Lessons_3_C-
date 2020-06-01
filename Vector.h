#pragma once

class Vector
{
protected:
	double* v;
	int len;
public:
	int size() const;
	Vector(int N);
	Vector(const Vector& temp);
	~Vector();
	double& operator [] (int index);
	double operator [] (int index) const;
	void insert();
	void erase(int i, int j);
};

