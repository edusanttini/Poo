#include <iostream>
#include "Fracao.h"

int main() {

	Fracao fracao01, fracao02;
	fracao01.getValue();
	fracao02.getValue();
	fracao01.printNum(1);
	fracao01.printDen(1);
	fracao02.printNum(2);
	fracao02.printDen(2);
	fracao01.printFraction(1);
	fracao02.printFraction(2);
	fracao01.soma(fracao01.getNum(fracao01), fracao01.getDen(fracao01), fracao02.getNum(fracao02), fracao02.getDen(fracao02));
	fracao01.printSoma();
	fracao01.sub(fracao01.getNum(fracao01), fracao01.getDen(fracao01), fracao02.getNum(fracao02), fracao02.getDen(fracao02));
	fracao01.printSub();
	fracao01.multip(fracao01.getNum(fracao01), fracao01.getDen(fracao01), fracao02.getNum(fracao02), fracao02.getDen(fracao02));
	fracao01.printMult();
	fracao01.div(fracao01.getNum(fracao01), fracao01.getDen(fracao01), fracao02.getNum(fracao02), fracao02.getDen(fracao02));
	fracao01.printDiv();
	//operator overload
	fracao01.operator++();
	fracao02.operator++(1);
	fracao01.operator--();
	fracao02.operator--(1);
	return 0;
}