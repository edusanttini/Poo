#include <iostream>
using namespace std;

class Fracao {
private:
	int num, den;
public:
	Fracao();
	Fracao getValue();
	Fracao getNum(Fracao);
	Fracao getDen(Fracao);
	void printNum(int);
	void printDen(int);
	void printFraction(int);
	void soma(Fracao, Fracao, Fracao, Fracao);
	void printSoma();
	void sub(Fracao, Fracao, Fracao, Fracao);
	void printSub();
	void multip(Fracao, Fracao, Fracao, Fracao);
	void printMult();
	void div(Fracao, Fracao, Fracao, Fracao);
	void printDiv();
	void operator ++ ();
	void operator ++ (int);
	void operator -- ();
	void operator -- (int);
};