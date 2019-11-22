#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"
#include "listchess.h"
#include "queuechess.h"


void MainMenu();
void NewGame();
void InputCommand();
void Display();
char Board[8][8] = {
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

int main() {
List BList, WList;
CreateList(&BList, "B");
CreateList(&WList, "W");

MainMenu();

return 0;
}

void MainMenu() {
    int k;
    printf("Welcome to our chess game.\n");
    printf("New Game [1]\n");
    printf("Load Game [2]\n");
    printf("Leaderboard [3]\n");
    printf("Masukkan pilihan: \n");
    scanf("%d", &k);
    if (k == 1) {
        NewGame();
    }
    /* else if (k == 2);
        LoadGame();
    else {
        Leaderboard();
    } */

}

void NewGame() {
    char Player1[10];
    char Player2[10];
    Queue QPlayer;
    Stack StackPiece;
    CreateEmptyQ(&QPlayer, 2);
    Add(&QPlayer, 'B');
    Add(&QPlayer, 'W');
    printf("Masukkan Player Black: \n");
    scanf("%s", Player1);
    printf("Masukkan Player White: \n");
    scanf("%s", Player2);
    /* while (!IsFull(StackPiece)) { */
    Display();
    InputCommand();
    /* } */   
}

void Display() {
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
            printf("%c", Board[i-1][j-1]);
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

void InputCommand() {
    char Cmd[20];
    printf("Masukkan command: ");
    /* scanf("%s", &Cmd);
    if (Cmd == "MOVE") {
        if (Head(Q)=='B') {
        Move();
    }
    else if (Cmd == "SPECIAL MOVE";) {
        SpecialMove();
    } */
    
}

address ListKeN(List L, int N) {
    address P;
    P = First(L);
    for (i = 1; i <= N; i++) {
        P = Next(P);
    }
    return P;
}


void Move(List L, List *MoveList) {
    int chosen;
    address P;
    printf("Daftar pilihan bidak yang dapat bergerak:\n");
    scanList(L, *MoveList);
    PrintInfo(*MoveList);
    printf("Pilih bidak yang ingin digerakkan:\n");
    scanf("%d", &chosen);
    P = ListKeN(*MoveList, chosen);

    switch (BName(BInfo(PInfo(*P)))
    {
    case ('H'):
        scHorse()
        break;
    
    default:
        break;
    }

    
    
}