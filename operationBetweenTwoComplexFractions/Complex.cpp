#include "Complex.hpp"
#include <math.h>
#define PI 3.14159265

int r, subReal, multReal, polReal; 
float i, subImag, multImag, divImag, polImag, divReal;

Complex::Complex(){
	real = 0;
	imag = 0;
}

Complex Complex:: getInput(char num){
    cout << "Type the real part of the number "<<num<<" ";
	cin >> real;
	cout << "Type the imaginary part of the number "<<num<<" ";
	cin >> imag;
}

Complex Complex:: Adicao (Complex x){
	r = this->real + x.real;
	i = this->imag + x.imag;
}

Complex Complex:: Subtracao (Complex x){
	subReal = this->real - x.real;
	subImag = this->imag - x.imag; 
}

Complex Complex:: multiplic(Complex x){
	multReal = real*x.real - imag*x.imag;
	multImag = real*x.imag + imag*x.real;
}

Complex Complex:: div(Complex x) {
	float den = (x.real*x.real + x.imag*x.imag);
	divReal = (real*imag + x.real*x.imag)/den;
	divImag = (imag*x.real - real*x.imag)/den;
}

Complex Complex::formaPolar(char x){
	Complex k;
	k.real = sqrt(real*real + imag*imag);
    k.imag = acos(real/k.real) * 180.0 / PI;
    cout.precision(3);
	cout<<"The polar form of "<<x<<" is "<<k.real<<" / "<<k.imag<<"\n";	
}

void Complex::printRet(char a){
	cout<<a<<" it's "<<real<<", "<<imag<<"j"<<"\n";	
}

void Complex::printSum(){
	cout<<"The sum of the 2 complex numbers is "<<r<<", "<<i<<"j"<<"\n";
}
void Complex::printSub(){	
	cout<<"The subtraction of the 2 complex numbers is "<<subReal<<", "<<subImag<<"j"<<"\n";
}
void Complex::printMultiply(){
	cout<<"The multiplication of the 2 complex numbers is "<<multReal<<", "<<multImag<<"j"<<"\n";
}
void Complex::printDiv(){
	cout<<"The division of the 2 complex numbers is "<<divReal<<", "<<divImag<<"j"<<"\n";
}