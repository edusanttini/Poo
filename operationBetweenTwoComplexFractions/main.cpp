#include <iostream>
#include "Complex.hpp"

int main(int argc, char** argv) {

	Complex fractionA, fractionB;
	fractionA.getInput('a');
	fractionB.getInput('b');		
	fractionA.printRet('A');
	fractionB.printRet('B');
	fractionA.Adicao(fractionB);
	fractionA.printSum();	
	fractionA.Subtracao(fractionB);
	fractionA.printSub();	
	fractionA.multiplic(fractionB);
	fractionA.printMultiply();	
	fractionA.div(fractionB);
	fractionA.printDiv();	
	fractionA.formaPolar('A');	
	fractionB.formaPolar('B');	
	return 0;
}