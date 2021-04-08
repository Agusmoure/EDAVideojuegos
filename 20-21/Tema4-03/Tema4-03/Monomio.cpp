#include "Monomio.h"
#include <math.h>
 bool operator<(const Monomio& m, const Monomio& n) {
     if (m.GetExp() < n.GetExp())return true;
     if (m.GetExp() > n.GetExp())return false;
     if (m.GetCoef() < n.GetCoef())return true;
     return false;
}
 bool operator>(const Monomio& m, const Monomio& n) {
     return n < m;
 }
 Monomio::Monomio(int e,int c){
     expo = e;
     coef = c;
 }
 int Monomio::GetExp()const {
     return expo;
 }
 int Monomio::GetCoef()const {
     return coef;
 }
 int Monomio::GetValor(int n) {
     return coef * pow(n, expo);
 }
 bool Monomio::Falla() {
     return expo == 0 && coef == 0;
 }