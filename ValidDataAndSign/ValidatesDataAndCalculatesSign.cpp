#include <iostream>

using namespace std;
string signox, mes;
class Register{
    private: 
        int day, month, year;
    public:
        void getUserData(){
            cout<<"Digite o dia: ";
            cin>>day;
            cout<<"Digite o mes: ";
            cin>>month;
            cout<<"Digite o ano: ";
            cin>>year;
        }

        bool isLeapYear(){
            int a = year;
            if(a%4==0 && (a%100!=0 || a%400==0))
                return true;
            else 
                return false;
        }

        bool dataExists(){
            if ((day >= 1 && day <= 31) && 
            (month >= 1 && month <= 12) && 
            (year >= 1900 && year <= 2100))
                return true;
            else
                return false;
        }

        bool isExclusiveData(){
            if ((isLeapYear()) && (day == 29 && month == 2)) //condicao para o dia 29/02, exclusiva de anos bissextos
                return true;
            if (day <= 28 && month == 2) //verifica o mes de feveireiro
                return true;
            else
                return false;
        }

        bool isRegularData(){
            if ((day <= 30) && 
                (month == 4 ||
                 month == 6 || 
                 month == 9 ||
                 month == 11)) //verifica meses com 30 dias
                return true;
            if ((day <= 31) && 
                (month == 1 || 
                 month == 3 || 
                 month == 5 || 
                 month == 7 || 
                 month == 8 || 
                 month == 10 ||
                 month == 12)) //verifica meses com 31 dias
                return true;
            else
                return false;
        }

        bool isDataCorrect(){
            if (dataExists()){
                if (isExclusiveData())
                    return true;
                if (isRegularData())
                    return true;
                else
                    return false;
            }
            else
                return false;
        }

        void printDataAndSign(string mes, string signox){
            int dia = day, ano = year;
            cout<<"\n"<<dia<<" de "<<mes<<" de "<<ano<<"\nSigno: "<<signox<<"\n";
            if(isLeapYear())
                cout<<"Ano Bissexto :)\n";
            else
                cout<<"Nao e bissexto :(\n";
        }

        void checkSign(int dia, string firstSign, string lastSign, string month){
            int d = day;
            if (d <= dia)  
                        signox = (firstSign);
                    else
                        signox = (lastSign);
                    mes = (month);
        }

        int getSign(){
            int d = day, m = month;         
            switch (m){
                case 1:
                    checkSign(20, "Capricornio", "Aquario", "Janeiro");
                break;
                case 2:
                    checkSign(18, "Aquario", "Peixes", "Fevereiro");
                break;
                case 3:
                    checkSign(20, "Peixes", "Aries", "Marco");
                break;
                case 4:
                    checkSign(20, "Aries", "Touro", "Abril");
                break;
                case 5:
                    checkSign(20, "Touro", "Gemeos", "Maio");
                break;
                case 6:
                    checkSign(20, "Gemeos", "Cancer", "Junho");
                break;
                case 7:
                    checkSign(22, "Cancer", "Leao", "Julho");
                break;
                case 8:
                    checkSign(22, "Leao", "Virgem", "Agosto");
                break;
                case 9:
                    checkSign(22, "Virgem", "Libra", "Setembro");
                break;
                case 10:
                    checkSign(22, "Libra", "Escorpiao", "Outubro");
                break;
                case 11:
                    checkSign(21, "Escorpiao", "Sagitario", "Novembro");
                break;
                case 12:
                    checkSign(21, "Sagitario", "Capricornio", "Dezembro");
                break;
                default:
                    cout<<"400 - Bad Request :s";
            }
        }
};

int main(){
    Register user;
    user.getUserData();
    user.isDataCorrect();
    while (!user.isDataCorrect()){
        cout<<"Insira uma data valida!!!\n";
        user.getUserData();
    }
    user.getSign();
    user.printDataAndSign(mes, signox);
}