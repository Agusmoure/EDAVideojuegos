#pragma once
class Monomio
{
private:
	int expo;
	int coef;
public:
	Monomio(int e=0,int c=0);
	int GetExp()const;
	int GetCoef()const;
	int GetValor(int n);
	bool Falla();
	friend bool operator<(const Monomio& m, const Monomio& n);
	friend bool operator>(const Monomio& m, const Monomio& n);
};