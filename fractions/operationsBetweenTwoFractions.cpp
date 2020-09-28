#include <iostream>
#include <iomanip>
using namespace std;

float somaNumerador, subtracaoNumerador, somaDenominador, subtracaoDenominador, numeradorA, numeradorB, denominadorA, denominadorB;
int reducedNum1, reducedDen1, reducedNum2, reducedDen2;
int reducedNumSoma, reducedNumSubtracao, reducedDenSoma, reducedDenSubtracao;
float decimal1, decimal2, decimalSoma, decimalSubtracao, decimalMultiplic, decimalDivisao;
int numMultiplicacao, denMultiplicacao, reducedNumMultiplic, reducedDenMultiplic;
int numDivisao, denDivisao, reducedNumDivisao, reducedDenDvisao;

//estrutura para guardar os valores das variaveis de entrada
struct numDen{
    float numerador1, numerador2, denominador1, denominador2;
}num1, num2, den1, den2;

//metodo para receber os valores de entrada
void createNum(){
    cout<<"Digite o numerador A: ";
    cin>> num1.numerador1;
    cout<<"Digite o denominador A: ";
    cin>> den1.denominador1;
    cout<<"Digite o numerador B: ";
    cin>> num2.numerador2;
    cout<<"Digite o denominador B: ";
    cin>> den2.denominador2;    
}

/*metodo int para calcular o maior divisor comum
*retorna o maior divisor comum
*/
int mdc(int u, int v){
    int t;
    while(u > 0){
        if(v > u){
            t = u;
            u = v;
            v = t;
        }
        u -= v;
    }
    return v;
}

/*Metodo int para reduzir o numerador da fracao
*retorna o numerador reduzido
*/
int reducaoNumerador(int x, int y){
    int gcd = mdc(x, y);
    int reducedNum = x/gcd;
    
    return reducedNum;
}

/*Metodo int para reduzir o denominador da fracao
*retorna o denominador reduzido
*/
int reducaoDenominador(int x, int y){
    int gcd = mdc(x, y);
    int reducedDen = y/gcd;

    return reducedDen;
}

/*Metodo float para calcular a forma decimal(0.00) de uma fracao
*retorna o valor em float
*/
float formaDecimal(float x, float y){
    float racional = x / y;
    
    return racional;
}

//Metodo struct para receber a fracao A, reduzi-la e calcular sua forma decimal
numDen fracaoA(numDen numerador, numDen denominador){
    numeradorA = numerador.numerador1;
    denominadorA = denominador.denominador1;
    reducedNum1 = reducaoNumerador(numeradorA, denominadorA);
    reducedDen1 = reducaoDenominador(numeradorA, denominadorA);
    decimal1 = formaDecimal(numeradorA, denominadorA);
}

//Metodo struct para receber a fracao B, reduzi-la e calcular sua forma decimal
numDen fracaoB(numDen numerador, numDen denominador){
    numeradorB = numerador.numerador2;
    denominadorB = denominador.denominador2;
    reducedNum2 = reducaoNumerador(numeradorB, denominadorB);
    reducedDen2 = reducaoDenominador(numeradorB, denominadorB);
    decimal2 = formaDecimal(numeradorB, denominadorB);
}

/*Metodo struct para receber os valores das duas fracoes A e B, calcular a soma e
*chamar os metodos para reduzir e calcular a forma decimal com o resultado da soma
*/
numDen soma(numDen numerador1, numDen numerador2, numDen denominador1, numDen denominador2){
    int deno1 = denominador1.denominador1;
    int deno2 = denominador2.denominador2;
    somaDenominador = deno1 * deno2;
    int numeradorParcial1 = somaDenominador / deno1 * numerador1.numerador1;
    int numeradorParcial2 = somaDenominador / deno2 * numerador2.numerador2;
    somaNumerador = numeradorParcial1 + numeradorParcial2;
    reducedNumSoma = reducaoNumerador(somaNumerador, somaDenominador);
    reducedDenSoma = reducaoDenominador(somaNumerador, somaDenominador);
    decimalSoma = formaDecimal(somaNumerador, somaDenominador);
}

/*Metodo struct para receber os valores das duas fracoes A e B, calcular a subtracao e
*chamar os metodos para reduzir e calcular a forma decimal com o resultado da subtracao
*/
numDen subtracao(numDen numerador1, numDen numerador2, numDen denominador1, numDen denominador2){
    int deno1 = denominador1.denominador1;
    int deno2 = denominador2.denominador2;
    subtracaoDenominador = deno1 * deno2;
    int numeradorParcial1 = subtracaoDenominador / deno1 * numerador1.numerador1;
    int numeradorParcial2 = subtracaoDenominador / deno2 * numerador2.numerador2;
    subtracaoNumerador = numeradorParcial1 - numeradorParcial2;
    reducedNumSubtracao = reducaoNumerador(subtracaoNumerador, subtracaoDenominador);
    reducedDenSubtracao = reducaoDenominador(subtracaoNumerador, subtracaoDenominador);
    decimalSubtracao = formaDecimal(subtracaoNumerador, subtracaoDenominador);
}

/*Metodo struct para receber os valores das duas fracoes A e B, calcular a multiplicacao e 
chamar os metodos para reduzir e calcular a forma decimal com o resultado da multiplicacao
*/
numDen multiplicacao(numDen numeradorA, numDen numeradorB, numDen denominadorA, numDen denominadorB){
    int deno1 = denominadorA.denominador1;
    int deno2 = denominadorB.denominador2;
    int nume1 = numeradorA.numerador1;
    int nume2 = numeradorB.numerador2;
    numMultiplicacao = nume1 * nume2;
    denMultiplicacao = deno1 * deno2; 
    reducedNumMultiplic = reducaoNumerador(numMultiplicacao, denMultiplicacao);
    reducedDenMultiplic = reducaoDenominador(numMultiplicacao, denMultiplicacao);
    decimalMultiplic = formaDecimal(reducedNumMultiplic, reducedDenMultiplic);
}

/*Metodo struct para receber os valores das duas fracoes A e B, calcular a divisao e 
chamar os metodos para reduzir e calcular a forma decimal com o resultado da divisao
*/
numDen divisao(numDen numeradorA, numDen numeradorB, numDen denominadorA, numDen denominadorB){
    int deno1 = denominadorA.denominador1;
    int deno2 = denominadorB.denominador2;
    int nume1 = numeradorA.numerador1;
    int nume2 = numeradorB.numerador2;
    numDivisao = nume1 * deno2;
    denDivisao = nume2 * deno1;
    reducedNumDivisao = reducaoNumerador(numDivisao, denDivisao);
    reducedDenDvisao = reducaoDenominador(numDivisao, denDivisao);
    decimalDivisao = formaDecimal(reducedNumDivisao, reducedDenDvisao);
}

//Metodo para a impressao na tela de todas as variaveis de saida
void print(){
    //numeroA, sua forma reduzida e sua forma decimal 
    cout<<"\nA = "<<numeradorA<<"/"<<denominadorA<<" = "<<reducedNum1<<"/"<<reducedDen1<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimal1<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
    //numeroB, sua forma reduzida e sua forma decimal
    cout<<"B = "<<numeradorB<<"/"<<denominadorB<<" = "<<reducedNum2<<"/"<<reducedDen2<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimal2<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
    //soma, sua forma reduzida e sua forma decimal
    cout<<"A + B = "<<somaNumerador<<"/"<<somaDenominador<<" = "<<reducedNumSoma<<"/"<<reducedDenSoma<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimalSoma<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
    //subtracao, sua forma reduzida e sua forma decimal
    cout<<"A - B = "<<subtracaoNumerador<<"/"<<subtracaoDenominador<<" = "<<reducedNumSubtracao<<"/"<<reducedDenSubtracao<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimalSubtracao<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
    //multiplicação, sua forma reduzida e sua forma decimal
    cout<<"A * B = "<<numMultiplicacao<<"/"<<denMultiplicacao<<" = "<<reducedNumMultiplic<<"/"<<reducedDenMultiplic<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimalMultiplic<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
    //divisao, sua forma reduzida e sua forma decimal
    cout<<"A / B = "<<numDivisao<<"/"<<denDivisao<<" = "<<reducedNumDivisao<<"/"<<reducedDenDvisao<<" = ";
    std::cout<<std::fixed<<std::setprecision(3)<<decimalDivisao<<"\n";
    std::cout<<std::fixed<<std::setprecision(0);
}

int main(){

    createNum();
    fracaoA(num1, den1);
    fracaoB(num2, den2);
    soma(num1, num2, den1, den2);
    subtracao(num1, num2, den1, den2);
    multiplicacao(num1, num2, den1, den2);
    divisao(num1, num2, den1, den2);
    print();

   return 0;
}