#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

char board[3][3] = {{'7','8','9'},
                    {'4','5','6'},
                    {'1','2','3'}};
int row, column, choice, i;
char turn = 'X';
bool draw = false;

void displayBoard(bool isLastDisplay, int result){

    cout<<"\n### JOGO DA VELHA ### v1.3 ### By SantCorporate ###\n\n";
    cout<<"##JOGO PARA 2 JOGADORES##\n";
    cout<<"\nJogador 01 -> [X] ## Jogador 02 -> [O]\n\n";
    if(isLastDisplay){
        if(result == 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);            
        else if(result == 2)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    }
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n"; 
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void playerTurn(){
    if(turn == 'X'){
        cout<<"\n\nJogador 01, sua vez de jogar! Seu marcador: [X]\n";
        cout<<"Escolha um numero correspondente a uma posicao na tabela acima: ";
    }
    else if(turn == 'O'){
        cout<<"\n\nJogador 02, sua vez de jogar! Seu marcador: [O]\n";
        cout<<"Escolha um numero correspondente a uma posicao na tabela acima: ";
    }
    
    cin>> choice;
    switch(choice){
        case 1: row=2; column=0; break;
        case 2: row=2; column=1; break;
        case 3: row=2; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=0; column=0; break;
        case 8: row=0; column=1; break;
        case 9: row=0; column=2; break;
        default:
            cout<<"Tecla invalida, pressione um numero de 1 a 9!";
    }
    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }else {
        cout<<"Posicao ja preenchida anteriormente, favor escolher novamente com mais atencao!!!!";
        playerTurn();
    }
    displayBoard(false, '0');
}

bool rowsAndColumnsWinCheck(){
    for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] &&
           board[i][0] == board[i][2] ||
           board[0][i] == board[1][i] &&
           board[0][i] == board[2][i])
            return true;        
        return false;
}

bool diagonalsWinCheck(){
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
       board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;
    return false;
}

//redoo if condition with more than one boolean as a parameter keeps failing
bool continueGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;
        }
    }
    return false;         
}

bool isGameTied(){
    if(!continueGame()){
        draw = true;
        return true;
    }
    else
        return false;
}

bool isGameOver(){
    
    if(rowsAndColumnsWinCheck())
        return false;
    if(diagonalsWinCheck())
        return false;
    if(continueGame())
        return true;	
    if(isGameTied())       
        return false;
    cout<<"CHECK: Did not attempted to any scnario at isGameOver.jogoDaVelha, exiting game";
    return false;   
}

void gameOver(){
    if(rowsAndColumnsWinCheck() || diagonalsWinCheck()){
        if(turn == 'O'){
            displayBoard(true, 1);    
            cout<<"\n\nO jogador 01 venceu, congrats!\n";
        }
        else if(turn == 'X'){
            displayBoard(true, 1);    
            cout<<"\n\nO jogador 02 venceu, congrats!\n";
        }
    }
    else if(isGameTied){
        displayBoard(true, 2);    
        cout<<"\nJOGO EMPATOU!!!";
    }
    else
        cout<<"CHECK: Did not attempted to any ending scnario at main.jogoDaVelha, maybe try to run me again? *-*";
}

int main()
{
    while(isGameOver()){
        displayBoard(false, '0');
        playerTurn();
        system("cls");        
    }    
    gameOver();
} 
