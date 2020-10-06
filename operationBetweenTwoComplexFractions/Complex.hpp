#pragma once
#include <iostream>
using namespace std;

class Complex {
	private:
		float real, imag;
	public:
		Complex();
		Complex getInput(char);		
		Complex multiplic(Complex);
		Complex div(Complex);
		Complex Adicao (Complex);
		Complex Subtracao (Complex);
		Complex formaPolar(char);		
		void printRet(char);
		void printSum();
		void printSub();
		void printMultiply();
		void printDiv();
		void printPol(char);
};