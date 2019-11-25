#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackchess.h"
#include "listchess.h"
#include "cmaster.h"
#include "leaderboard.h"

void Menu();
void NewGame();
void InputCommand(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Move(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Undo(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void Display();
address ListKeN(List L, int N);
void PrintLoc(int row, int col);
int UpdateSkor(char Player);
void SpecialMove(List *L, List *moveL, List * eatL, List *lawan, Stack *history);
void WhoWins(int W, int B);
void Leaderboard();

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
                
char Player1[4];
char Player2[4];
int i;
List BList, WList;
List ownB, ownW;
List moveBl, moveWh;
List validMove;

int SkorB, SkorW;
int SkorB, SkorW;
ArrSkor HighScore;



int main() {
    Menu();
    return 0;
}

void Menu(){
    int input;
    boolean stop = false;
    printf("Welcome to our chess game.\n");
    printf("New Game [1]\n");
    printf("Load Game [2]\n");
    printf("Leaderboard [3]\n");
    printf("Masukkan pilihan: \n");
    scanf("%d", &input);
    while (!stop){
        if (input == 1) {
            NewGame(); stop = true;
        }
        else if (input == 2){
            //LoadGame(); stop = true;
        }
        else {
            Leaderboard(); stop = true;
        }
    }
}

void NewGame(){
    extern char Player1[4];
    extern char Player2[4];
    extern List BList, WList; CreateList(&BList, 'B'); CreateList(&WList, 'w');
    extern List validMove; CreateEmptyL(&validMove);
    extern List ownB, ownW; CreateEmptyL(&ownB); CreateEmptyL(&ownW);
    Queue playQ; CreateEmptyQ(&playQ, 2); Add(&playQ, 'B'); Add(&playQ, 'w');
    Stack histMove; CreateEmptyS(&histMove);
    //extern boolean win;
    printf("Masukkan Player Black: \n"); scanf("%s", Player1);
    printf("Masukkan Player White: \n"); scanf("%s", Player2);
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
    WhoWins(SkorW, SkorB);
}

void Display() {
    int i;
    int j;
    int n = 8;
    extern char Player1[4];
    extern char Player2[4];

    printf("\n");
    printf("\n");
    printf("\n");
    printf("     ");

    printf("%s: %d", Player1, SkorB);
    for (i = 1; i <= 25; i++) {
        printf(" ");
    }
    printf("%s: %d\n", Player2, SkorW);
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
    };
<<<<<<< HEAD
    
=======
    //address 
>>>>>>> hiyaa
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
    boolean stop = false;
    while (!stop){
        if (strcmp(Cmd, "MOVE") == 0) {
            Move(L, moveL, eatL, lawan, history); stop = true;
        }
        else if (strcmp(Cmd, "UNDO") == 0){
            Undo(L, moveL, eatL, lawan, history); stop = true;
        }
<<<<<<< HEAD
        else if (strcmp(Cmd, "SPECIAL MOVE") == 0){
            SpecialMove(L, moveL, eatL, lawan, history); stop = true;
        }
    }
    
    /*
    else if (Cmd == "SPECIAL MOVE";) {
        SpecialMove();
    } */
    
=======
        /*
        else if (Cmd == "SPECIAL MOVE";) {
            SpecialMove();
        } */
    }    
>>>>>>> hiyaa
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
    extern int SkorB, SkorW;
    SkorB = 0;
    SkorW = 0;
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
    address temp,prec;
    SInfo S;
    while ((mainL != Nil) && !done){
        if ((mainL->PInfo.X == P->PInfo.X) && (mainL->PInfo.Y == P->PInfo.Y)) {
            if (IsCanEat(PType(PInfo(mBidak)), Y(PInfo(mBidak)), X(PInfo(mBidak)))){
                if (PType(PInfo(mBidak)) == 'B') {
                    temp = First(*lawan);
                    while (!IsEqualPiece(PInfo(temp), PInfo(mBidak))){  //CARI PIECE YG MAU DIMAKAN
                        prec = temp;
                        temp = Next(temp);
                    }
                    if (IsEqualPiece(PInfo(temp), PInfo(mBidak))){  //HAPUS PIECE DR LIST LAWAN
                        Next(prec) = Next(Next(prec));
                    }
                    InsertFirst(eatL, temp);    //TARO PIECENYA DI LIST OWN
                    SkorB = SkorB + UpdateSkor(temp->PInfo.BInfo.PName);
                }
                if (PType(PInfo(mBidak)) == 'w') {
                    temp = First(*lawan);
                    while (!IsEqualPiece(PInfo(temp), PInfo(mBidak))){
                        prec = temp;
                        temp = Next(temp);
                    }
                    if (IsEqualPiece(PInfo(temp), PInfo(mBidak))){
                        Next(prec) = Next(Next(prec));
                    }
                    InsertFirst(eatL, temp);
                    SkorW = SkorW + UpdateSkor(temp->PInfo.BInfo.PName);
                }
                S.prevMove = 'E';
<<<<<<< HEAD
                

=======
>>>>>>> hiyaa
            }
            else{
                S.prevMove = 'O';
            }
            row = Y(PInfo(P));col = X(PInfo(P));
            cBoard[row][col] = ' ';
            PInfo(mainL) = PInfo(mBidak);
            cBoard[Y(PInfo(mainL))][X(PInfo(mainL))] = PName(PInfo(mainL));
            S.PInfo = PInfo(mBidak); S.prevX = col; S.prevY = row;
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

        //first pop &synch
    Piece tempB = P1.PInfo;
    temp = SearchPosisi(*lawan, tempB);
    printf("tes\n");
    if (IsEqualPiece(PInfo(temp), tempB)){
        printf("!nIL\n");
        temp->PInfo.X = P1.prevX;
        temp->PInfo.Y = P1.prevY;
        printf("tes\n");
    }
    else if (temp == Nil){
        printf("NIL\n");
        PInfo(temp) = tempB;
        //List cobs; CreateEmptyL(&cobs);
        temp->PInfo.X = P1.prevX;
        temp->PInfo.Y = P1.prevY;
        InsertFirst(lawan, temp);
        printf("INSERTED\n");
        //InsertFirst(&cobs, temp);PrintInfo(cobs);
    }
    cBoard[P1.PInfo.Y][P1.PInfo.X] = ' ';
    cBoard[temp->PInfo.Y][temp->PInfo.X] = PName(PInfo(temp));
    printf("P2\n");
        //2nd pop & synch
    tempB = P2.PInfo;
    temp = SearchPosisi(*L, tempB);
    if (temp != Nil){
        printf("!NIL2\n");
        temp->PInfo.X = P2.prevX;
        temp->PInfo.Y = P2.prevY;
    }
    else{
        PInfo(temp) = tempB;
        temp->PInfo.X = P2.prevX;
        temp->PInfo.Y = P2.prevY;
        InsertFirst(L, temp);
        printf("NIL2\n");
    }
    cBoard[P2.PInfo.Y][P2.PInfo.X] = ' ';
    cBoard[temp->PInfo.Y][temp->PInfo.X] = PName(PInfo(temp));
    printf("Gerakan sampai giliran sebelumnya berhasil dibatalkan.\n");
    PrintInfo(*L); PrintInfo(*lawan);
}

<<<<<<< HEAD
=======
int UpdateSkor(char Player) {
    int Skor;
    Skor = 0;
        switch (Player)
        {
        case ('k'): 
        case ('K'): Skor = Skor + 10;
            break;
        case ('Q'):
        case ('q'): Skor = Skor + 8;
            break;
        case ('B'):
        case ('b'): Skor = Skor + 4;
            break;
        case ('H'):
        case ('h'): Skor = Skor + 2;
            break;
        case ('R'):
        case ('r'): Skor = Skor + 4;
            break;
        case ('P'):
        case ('p'): Skor = Skor + 1;
            break;
         }
        return Skor;
    }

>>>>>>> hiyaa
void SpecialMove(List *L, List *moveL, List * eatL, List *lawan, Stack *history){
    
    address P = First(*L);
    address A;
    while (P != Nil) {
        switch (PName(PInfo(P))){
        case ('K'): case ('k'): scCastling(PInfo(P), L, moveL, *history); break;
        case ('P'): case ('p'): scEnpassant(PInfo(P), moveL); scPromote(PInfo(P), moveL); break;
        default: break;
        }
    }
    printf("Daftar gerakan khusus yang bisa dilakukan:\n");
    address print = First(*moveL);
    for (int i = 0; print != Nil; i++){
        printf("%d. ", i);
        switch (PName(PInfo(print))){
        case ('K'): case ('k'): printf("Castling\n"); break;
        case ('P'):
        case ('p'):
            if(PType(PInfo(print)) == 'B'){
                if (Y(PInfo(print)) == 6){
                    printf("Pawn Promotion\n");
                }
            }
            else if (PType(PInfo(print)) == 'b'){
                if (Y(PInfo(print)) == 1){
                    printf("Pawn Promotion\n");
                }
            }
            else{
                printf("En Passant\n");
            }
        default: break;
        }
    }
    printf("Pilih gerakan khusus yang ingin dilakukan: ");
    int n; scanf("%d", &n);         //cari piece yg dipilih
    address move = ListKeN(*moveL, n);
    List listmove; CreateEmptyL(&listmove);
    switch (PName(PInfo(move))){
        case ('K'): case ('k'): moveCastling(PInfo(move), &listmove, *history); break;
        case ('P'): case ('p'): 
            if(PType(PInfo(print)) == 'B'){
                if (Y(PInfo(print)) == 6){
                    movePromote(&listmove, PInfo(move));
                }
            }
            else if (PType(PInfo(print)) == 'b'){
                if (Y(PInfo(print)) == 1){
                    movePromote(&listmove, PInfo(move));
                }
            }
            else{
                moveEnpassant(PInfo(move), &listmove);
            }
        default: break;
    }
        //move piece
        //tampilin piece yg dipilih bisa gerak kemana, pilih mau kmn
    printf("Daftar posisi tujuan yang mungkin:\n");
    PrintInfoMove(listmove);
    int choice2;    //pilih piece
    do{
        printf("Pilih posisi tujuan bidak: ");
        scanf("%d", &choice2);
    } while (choice2 > NbElmt(listmove));
    address mBidak = ListKeN(listmove, choice2);  //ambil info piece yg dipilih
        //tambah, apus list MOVING PIECE BENERAN
    address mainL = First(*L);
    boolean done = false;
    int row, col;
    address temp,prec;
    SInfo S;
    while ((mainL != Nil) && !done){
        if ((mainL->PInfo.X == move->PInfo.X) && (mainL->PInfo.Y == move->PInfo.Y)) {
            if (IsCanEat(PType(PInfo(mBidak)), Y(PInfo(mBidak)), X(PInfo(mBidak)))){
                if (PType(PInfo(mBidak)) == 'B') {
                    temp = First(*lawan);
                    while (!IsEqualPiece(PInfo(temp), PInfo(mBidak))){  //CARI PIECE YG MAU DIMAKAN
                        prec = temp;
                        temp = Next(temp);
                    }
                    if (IsEqualPiece(PInfo(temp), PInfo(mBidak))){  //HAPUS PIECE DR LIST LAWAN
                        Next(prec) = Next(Next(prec));
                    }
                    InsertFirst(eatL, temp);    //TARO PIECENYA DI LIST OWN
                    SkorB = SkorB + UpdateSkor(temp->PInfo.BInfo.PName);
                }
                if (PType(PInfo(mBidak)) == 'w') {
                    temp = First(*lawan);
                    while (!IsEqualPiece(PInfo(temp), PInfo(mBidak))){
                        prec = temp;
                        temp = Next(temp);
                    }
                    if (IsEqualPiece(PInfo(temp), PInfo(mBidak))){
                        Next(prec) = Next(Next(prec));
                    }
                    InsertFirst(eatL, temp);
                    SkorW = SkorW + UpdateSkor(temp->PInfo.BInfo.PName);
                }
                S.prevMove = 'S';
            }
            else{
                S.prevMove = 's';
            }
            row = Y(PInfo(move));col = X(PInfo(move));
            cBoard[row][col] = ' ';
            PInfo(mainL) = PInfo(mBidak);
            cBoard[Y(PInfo(mainL))][X(PInfo(mainL))] = PName(PInfo(mainL));
            S.PInfo = PInfo(mBidak); S.prevX = col; S.prevY = row;
            Push(history, S);
            done = true;
        }
        else{
            mainL = Next(mainL);
        }
    }
        //selesai move
    printf("Bidak");
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
<<<<<<< HEAD
    
}

void WhoWins(int W, int B) {
    if (W > B) {
        WriteLeaderBoard(W);
        printf("white wins.");
    }
    else if (W < B) {
        WriteLeaderBoard(B);
        printf("BLACK wins.");
    }
    else {
        printf("It's a tie.");
    }
}

void Leaderboard() {
    ReadLeaderBoard(HighScore);
    PrintLeaderBoard(HighScore);
=======

>>>>>>> hiyaa
}