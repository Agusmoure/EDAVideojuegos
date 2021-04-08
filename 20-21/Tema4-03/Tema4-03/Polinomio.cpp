#include "Polinomio.h"
#include<algorithm>
Polinomio::Polinomio(){}
Polinomio::Polinomio( vector<Monomio>v){
	monomios = v;
}
void Polinomio:: AgregarMonomio(Monomio m){
	monomios.push_back(m);
	sort(monomios.begin(), monomios.end());
}
int Polinomio::GetValor(int n){
	int suma = 0;
	for (size_t i = 0; i < monomios.size(); i++)
	{
		suma += monomios.at(i).GetValor(n);
	}
	return suma;
}