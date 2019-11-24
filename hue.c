#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackchess.h"
#include "listchess.h"
#include "cmaster.h"

void Menu();
void NewGame();
void InputCommand(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Move(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Undo(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Display();
address ListKeN(List L, int N);
void PrintLoc(int row, int col);
char cBoard[8][8] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'b' , 'k' , 'q' , 'b' , 'h' , 'r' }
                };

char IdX[8] = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' };
                
char Player1[10];
char Player2[10];
int i;
List BList, WList;
List ownB, ownW;
List moveBl, moveWh;
List validMove;


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
    extern List BList, WList; CreateList(&BList, 'B'); CreateList(&WList, 'w');
    extern List validMove; CreateEmptyL(&validMove);
    extern List ownB, ownW; CreateEmptyL(&ownB); CreateEmptyL(&ownW);
    Queue playQ; CreateEmptyQ(&playQ, 2); Add(&playQ, 'B'); Add(&playQ, 'w');
    Stack histMove; CreateEmptyS(&histMove);
    //extern boolean win;
    printf("Masukkan Player Black: \n"); scanf("%s", Player1);//fgets(Player1, 10, stdin); 
    printf("Masukkan Player White: \n"); scanf("%s", Player2);//fgets(Player2, 10, stdin); 
    int turn = 1;
    while (turn <=100){
        char playing;
        Display();
        Del(&playQ, &playing);
        Add(&playQ, playing);
        if (playing == 'B'){
            //PrintInfo(BList);PrintInfo(WList);
            printf("BLACK's turn\n"); InputCommand(&BList, &validMove, &ownB, &WList, &histMove);
        }
        else{
            printf("white's turn\n"); InputCommand(&WList, &validMove, &ownW, &BList, &histMove);
        }
        turn += 1;
    }
    printf("Game End!\n");
}

void Display() {
    int i;
    int j;
    int n = 8;
    extern char Player1[10];
    extern char Player2[10];

    printf("BLACK: %s", Player1);
    for (i = 1; i <= 15; i++) {
        printf(" ");
    }
    printf("white: %s\n", Player2);
    printf("\n");

    printf("     ");
    for (i = 1; i <= 8; i++) {
            printf("%c", IdX[i-1]);
            printf("    ");
    }
    printf("\n");

    printf("  ");
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
    for (i = 1; i <= 8; i++) {
        j = 1;
        printf("%d || ", i);
        while (j <= (n)) {
            printf("%c", cBoard[i-1][j-1]);
            printf(" || ");
            j++;
        }
        printf("\n");
    }
    printf("  ");
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
}

void InputCommand(List *L, List *moveL, List * eatL, List *lawan, Stack *history){
    char Cmd[20];
    printf("Masukkan command: ");
    scanf("%s", Cmd);
    if (strcmp(Cmd, "MOVE") == 0) {
        Move(L, moveL, eatL, lawan, history);
    }
    else if (strcmp(Cmd, "UNDO") == 0){
        Undo(L, moveL, eatL, lawan, history);
    }
    
    /*
    else if (Cmd == "SPECIAL MOVE";) {
        SpecialMove();
    } */
    
}

address ListKeN(List L, int N) {
    address P;
    P = First(L);
    int i;
    for (i = 1; i < N; i++) {
        P = Next(P);
    }
    return P;
}
void PrintLoc(int row, int col){
    switch (col){
        case 0: col = 'a'; break;
        case 1: col = 'b'; break;
        case 2: col = 'c'; break;
        case 3: col = 'd'; break;
        case 4: col = 'e'; break;
        case 5: col = 'f'; break;
        case 6: col = 'g'; break;
        case 7: col = 'h'; break;
        default:  break;
        }
    switch (row){
        case 0: row = 1; break;
        case 1: row = 2; break;
        case 2: row = 3; break;
        case 3: row = 4; break;
        case 4: row = 5; break;
        case 5: row = 6; break;
        case 6: row = 7; break;
        case 7: row = 8; break;
        default:  break;
        }
    printf("(%c,%d)", col, row);
}
void Move(List *L, List *moveL, List * eatL, List *lawan, Stack *history){
    printf("Daftar bidak yang bisa bergerak:\n");
    scanList(*L, moveL);
    PrintInfo(*moveL);

    int choice; 
    do{
        printf("Pilih bidak yang ingin digerakkan: ");
        scanf("%d", &choice);
    } while (choice > NbElmt(*moveL));
    
    address P = ListKeN(*moveL, choice);

        //cek bidak yg dipilih bisa gerak dimana
    List moveBidak; CreateEmptyL(&moveBidak);
    switch (PName(PInfo(P))){
    case ('P'):
    case ('p'): moveP(&moveBidak, PInfo(P)); break;
    case ('R'):
    case ('r'): moveR(&moveBidak, PInfo(P)); break;
    case ('H'):
    case ('h'): moveH(&moveBidak, PInfo(P)); break;
    case ('B'):
    case ('b'): moveB(&moveBidak, PInfo(P)); break;
    case ('K'):
    case ('k'): moveK(&moveBidak, PInfo(P)); break;
    case ('Q'):
    case ('q'): moveQ(&moveBidak, PInfo(P)); break;
    default: break;
    }

        //tampilin piece yg dipilih bisa gerak kemana, pilih mau kmn
    printf("Daftar posisi tujuan yang mungkin:\n");
    PrintInfoMove(moveBidak);
    int choice2; 
    do{
        printf("Pilih posisi tujuan bidak: ");
        scanf("%d", &choice2);
    } while (choice2 > NbElmt(moveBidak));
    address mBidak = ListKeN(moveBidak, choice2);  //ambil info piece yg dipilih
        //tambah, apus list MOVING PIECE BENERAN
    address mainL = First(*L);
    boolean done = false;
    int row, col;
    address temp;
    while ((mainL != Nil) && !done){
        if ((mainL->PInfo.X == P->PInfo.X) && (mainL->PInfo.Y == P->PInfo.Y)) {
            if (IsCanEat(PType(PInfo(mBidak)), Y(PInfo(mBidak)), X(PInfo(mBidak)))){
                if (PType(PInfo(mBidak)) == 'B') {
                    temp = SearchPosisi(*lawan, mBidak->PInfo); //CARI PIECE YG MAU DIMAKAN
                    InsertFirst(eatL, temp);    //TARO PIECENYA DI LIST OWN
                    DelP(lawan, PInfo(mBidak));   //HAPUS PIECE DR LIST LAWAN
                }
                if (PType(PInfo(mBidak)) == 'w') {
                    temp = SearchPosisi(*lawan, mBidak->PInfo);
                    InsertFirst(eatL, temp);
                    DelP(lawan, PInfo(mBidak));
                }
            }
            row = Y(PInfo(P));col = X(PInfo(P));
            cBoard[row][col] = ' ';
            PInfo(mainL) = PInfo(mBidak);
            cBoard[Y(PInfo(mainL))][X(PInfo(mainL))] = PName(PInfo(mainL));
            SInfo S; S.PInfo = PInfo(mBidak); S.prevX = col; S.prevY = row;
            Push(history, S);
            done = true;
        }
        else{
            mainL = Next(mainL);
        }
    }
    printf("Bidak ");
    switch (BInfo(PInfo(mainL)).PName){
        case ('P'): case ('p'): printf("pion "); break;
        case ('R'): case ('r'): printf("benteng "); break;
        case ('H'): case ('h'): printf("kuda "); break;
        case ('B'): case ('b'): printf("menteri "); break;
        case ('K'): case ('k'): printf("raja "); break;
        case ('Q'): case ('q'): printf("ratu "); break;
        default: break;
        }
    printf("telah berpindah dari ");PrintLoc(row, col); printf(" ke "); PrintLoc(Y(PInfo(mainL)), X(PInfo(mainL)));printf("\n");
    CreateEmptyL(moveL);
    CreateEmptyL(&moveBidak);
}

void Undo(List *L, List *moveL, List * eatL, List *lawan, Stack *history){
    SInfo P1, P2; address temp;
    Pop(history, &P1); Pop(history, &P2);
    Piece tempB = P1.PInfo;
    temp = SearchPosisi(*lawan, tempB);
    if (temp != Nil){
        temp->PInfo.X = P1.prevX;
        temp->PInfo.Y = P1.prevY;
    }
    else{
        temp->PInfo.X = P1.prevX;
        temp->PInfo.Y = P1.prevY;
        InsertFirst(lawan, temp);
    }
    cBoard[P1.PInfo.Y][P1.PInfo.X] = ' ';
    cBoard[temp->PInfo.Y][temp->PInfo.X] = PName(PInfo(temp));
    tempB = P2.PInfo;
    temp = SearchPosisi(*L, tempB);
    if (temp != Nil){
        temp->PInfo.X = P2.prevX;
        temp->PInfo.Y = P2.prevY;
    }
    else{
        temp->PInfo.X = P2.prevX;
        temp->PInfo.Y = P2.prevY;
        InsertFirst(L, temp);
    }
    cBoard[P2.PInfo.Y][P2.PInfo.X] = ' ';
    cBoard[temp->PInfo.Y][temp->PInfo.X] = PName(PInfo(temp));
    printf("Gerakan sampai giliran sebelumnya berhasil dibatalkan.\n");
    PrintInfo(*L); PrintInfo(*lawan);
}