#pragma once
#include<vector>
#include"Monomio.h"
using namespace std;
class Polinomio
{
private:
	vector<Monomio> monomios;
public:
	Polinomio();
	Polinomio(vector<Monomio>v);
	void AgregarMonomio(Monomio m);
	int GetValor(int n);
};

