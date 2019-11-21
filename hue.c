#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmaster.h"


void Menu();
void NewGame();
void InputCommand(List *L, List *moveL);
void Move(List *L, List *moveL);
void Display();
char cBoard[8][8] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'B' , 'k' , 'q' , 'B' , 'h' , 'r' }
                };
                
char Player1[10];
char Player2[10];
/*
List BList, WList;
List moveB, moveW;
Queue playQ;
Stack histMove;
//boolean win;
*/
int main() {
    Menu();
    return 0;
}

void Menu(){
    int input;
    printf("Welcome to our chess game.\n");
    printf("New Game [1]\n");
    printf("Load Game [2]\n");
    printf("Leaderboard [3]\n");
    printf("Masukkan pilihan: \n");
    scanf("%d", &input);
    if (input == 1) {
        NewGame();
    }
    else if (input == 2){
        //LoadGame();
    }
    else {
        //Leaderboard();
    }

}

void NewGame(){
    extern char Player1[10];
    extern char Player2[10];
    List BList, WList; CreateList(&BList, 'B'); CreateList(&WList, 'w');
    List moveB, moveW; CreateEmptyL(&moveB), CreateEmptyL(&moveW);
    Queue playQ; CreateEmptyQ(&playQ, 2); Add(&playQ, 'B'); Add(&playQ, 'w');
    Stack histMove; CreateEmptyS(&histMove);
    //extern boolean win;
    printf("Masukkan Player Black: \n"); scanf("%s", Player1);//fgets(Player1, 10, stdin); 
    printf("Masukkan Player White: \n"); scanf("%s", Player2);//fgets(Player2, 10, stdin); 
    while ((!IsFullS(histMove))){
        char playing;
        Display();
        Del(&playQ, &playing);
        Add(&playQ, playing);
        if (playing == 'B'){
            printf("BLACK's turn\n"); InputCommand(&BList, &moveB);
        }
        else{
            printf("white's turn\n"); InputCommand(&WList, &moveW);
        }
    }
    /* } */   
}

void Display(){
    int i;
    int j;
    int n = 8;

    printf("BLACK: %s", Player1);
    for (i = 1; i <= 15; i++) {
        printf(" ");
    }
    printf("white: %s\n", Player2);

    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
    for (i = 1; i <= 8; i++) {
        j = 1;
        printf("|| ");
        while (j <= (n)) {
            printf("%c", cBoard[i-1][j-1]);
            printf(" || ");
            j++;
        }
        printf("\n");
    }
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
}

void InputCommand(List *L, List *moveL){
    char Cmd[20];
    printf("Masukkan command: ");
    scanf("%s", Cmd);
    if (strcmp(Cmd, "MOVE") == 0) {
        Move(L, moveL);
    }
    /*
    else if (Cmd == "SPECIAL MOVE";) {
        SpecialMove();
    } */
    
}

void Move(List *L, List *moveL){
    printf("Daftar bidak yang bisa bergerak:\n");
    scanList(*L, moveL);
    PrintInfo(*moveL);
    address P = First(*moveL);
    int choice; scanf("%d", &choice);
    for (int i = 1; i <= choice;i++){
        P = Next(P);
    }
    
}