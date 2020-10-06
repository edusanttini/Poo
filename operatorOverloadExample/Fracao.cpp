#include "Fracao.h"
#include <math.h>

int somaNum, somaDen, subNum, subDen, multNum, multDen, divNum, divDen;

Fracao::Fracao() {
	num = 0;
	den = 0;
}

Fracao Fracao::getValue() {
	cout << "Digite o numerador: ";
	cin >> num;
	cout << "Digite o denominador: ";
	cin >> den;
	return *this;
}

Fracao Fracao::getNum(Fracao n) {
	n.num;
	return n;
}

Fracao Fracao::getDen(Fracao d) {
	d.den;
	return d;
}

void Fracao::printNum(int fracao) {
	cout << "O numerador da fracao " << fracao << " eh: " << num << "\n";
}

void Fracao::printDen(int fracao) {
	cout << "O denominador da fracao " << fracao << " eh: " << den << "\n";
}

void Fracao::printFraction(int fracao) {
	cout << "A fracao "<< fracao <<" eh: " << num << "/" << den << "\n";	
}

void Fracao::soma(Fracao x1, Fracao y1, Fracao x2, Fracao y2){	
	int n1, d1, n2, d2;
	n1 = x1.num; n2 = x2.num;
	d1 = y1.den; d2 = y2.den;
	somaDen = d1 * d2;
	int numParcial1 = somaDen / d1 * n1;
	int numParcial2 = somaDen / d2 * n2;
	somaNum = numParcial1 + numParcial2;
}

void Fracao::sub(Fracao x1, Fracao y1, Fracao x2, Fracao y2) {
	int n1, d1, n2, d2;
	n1 = x1.num; n2 = x2.num;
	d1 = y1.den; d2 = y2.den;
	subDen = d1 * d2;
	int numParcial1 = subDen / d1 * n1;
	int numParcial2 = subDen / d2 * n2;
	subNum = numParcial1 - numParcial2;
}

void Fracao::multip(Fracao x1, Fracao y1, Fracao x2, Fracao y2) {
	int n1, d1, n2, d2;
	n1 = x1.num; n2 = x2.num;
	d1 = y1.den; d2 = y2.den;
	multNum = n1 * n2;
	multDen = d1 * d2;
}

void Fracao::div(Fracao x1, Fracao y1, Fracao x2, Fracao y2) {
	int n1, d1, n2, d2;
	n1 = x1.num; n2 = x2.num;
	d1 = y1.den; d2 = y2.den;
	divNum = n1 * d2;
	divDen = n2 * d1;
}

void Fracao::printSoma() {
	cout << "A soma da fracao eh: " << somaNum << "/" << somaDen << "\n";
}

void Fracao::printSub() {
	cout << "A subtracao da fracao eh: " << subNum << "/" << subDen << "\n";
}

void Fracao::printMult() {
	cout << "A multiplicacao da fracao eh: " << multNum << "/" << multDen << "\n";
}

void Fracao::printDiv() {
	cout << "A divisao da fracao eh: " << divNum << "/" << divDen << "\n";
}

void Fracao::operator++(){
	int x = num++;
	int y = den++;
	cout <<"Incremento pre fixado no numerador e denominador da fracao 1: " << x << "/" << y << "\n";
}

void Fracao::operator++(int) {
	int x = ++num;
	int y = ++den;
	cout << "Incremento pos fixado no numerador e denominador da fracao 2: " << x << "/" << y<<"\n";
}

void Fracao::operator--() {
	int x = num--;
	int y = den--;
	cout << "Decremento pre fixado no numerador e denominador da fracao 1: " << x << "/" << y << "\n";
}

void Fracao::operator--(int) {
	int x = --num;
	int y = --den;
	cout << "Decremento pos fixado no numerador e denominador da fracao 2: " << x << "/" << y;
}