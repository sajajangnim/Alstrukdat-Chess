

#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"
#include "stackchess.h"
#include "chessboard.h"
#include "listchess.h"
#include "boolean.h"

//List *ML, char **cb, char warnaBdk
void scanList (List L, List *ML){
    address P = First(L);
    while (P != Nil){
        Piece temp = PInfo(P);  //exprexxion must have pointer type:(
        int i = temp.X; int j = temp.Y;
        if (PType(temp) == 'B'){
            switch (cBoard[i][j]) {
            case ('P'): scPawn(ML, i, j, PType(temp)); break;
            case ('R'): scRook(ML, i, j, PType(temp)); break;
            case ('H'): scHorse(ML, i, j, PType(temp)); break;
            case ('B'): scCamel(ML, i, j, PType(temp)); break;
            case ('K'): scKing(ML, i, j, PType(temp)); break;
            case ('Q'): scQueen(ML, i, j, PType(temp)); break; 
            default: break;
            }
        }
        else {
            switch (cBoard[i][j]) {
            case ('p'): scPawn(ML, i, j, PType(temp)); break;
            case ('r'): scRook(ML, i, j, PType(temp)); break;
            case ('h'): scHorse(ML, i, j, PType(temp)); break;
            case ('b'): scCamel(ML, i, j, PType(temp)); break;
            case ('k'): scKing(ML, i, j, PType(temp)); break;
            case ('q'): scQueen(ML, i, j, PType(temp)); break; 
            default: break;
            }
        }
        P = Next(P);    //expression must have pointer type
    }
}

void scPawn(List *ML, int i, int j, char warnaBdk){
    char P, p;
    Bidak pion;
    pion.PType = warnaBdk;
    address A;
    if (warnaBdk == 'B'){
        pion.PName = P;
        if (j == 7){
            if (cBoard[i-2][j] == ' '){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
            }
        }
        if (cBoard[i-1][j] == ' '){
            A = Alokasi(pion, i, j);
            InsertFirst(ML, A);
        }
    }
    else{
        pion.PName = p;
        if (j == 2){
            if (cBoard[i+2][j] == ' '){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
            }
        }    
        if (cBoard[i+1][j] == ' '){
            A = Alokasi(pion, i, j);
            InsertFirst(ML, A);
        }    
    }
    //BLM ADA KASUS KALO DI SERONGYA ADA MUSUH, TRS BISA JALAN KE SITU
    //HRS BIKIN CHECK DULU
}

void scRook(List *ML, int i, int j, char warnaBdk){
    char R, r;
    address A;
    Bidak benteng;
    if (warnaBdk == 'B'){
        benteng.PName = R;
    }
    else{
        benteng.PName = r;
    }
    benteng.PType = warnaBdk;
    int n = j;
    while (cBoard[i][j+1] == ' '){ //cek kanan
        if (n == 9){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n += 1;
    }
    while (cBoard[i][j-1] == ' '){ //cek kiri
        if (n == 0){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n -= 1;
    }

    n = i;
    while (cBoard[i+1][j] == ' '){ //cek depan
        if (n == 8){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n += 1;
    }
    while (cBoard[i-1][j] == ' '){ //cek blkg
        if (n == 0){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n -= 1;
    }
}
//MSH HRS DICEK  LG KONDISI BERENTINYA KALO IDX ARRAY BRP
//sc horse idx nya 0-7
void scHorse (List *ML, int i, int j, char warnaBdk){
    char H, h;
    Bidak kuda;
    address k;
    if(warnaBdk == 'B'){    //INISIALISASI BIDAK, PTYPENYA APA?
        kuda.PName = H; }
    else {
        kuda.PName = h; }
    kuda.PType = warnaBdk;
        //NGECEK BISA JALAN GA
    if (cBoard[i+2][j+1] == ' '){
        if((i <=7) && (j <= 7)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i+2][j-1] == ' ') {
        if((i <=7) && (j >= 0)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-2][j-1] == ' ') {
        if((i >=0) && (j >= 0)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-2][j+1] == ' ') {
        if((i >=0) && (j <= 7)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i+1][j+2] == ' ') {
        if((i <=7) && (j <= 7)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i+1][j-2] == ' ') {
        if((i <=7) && (j >= 0)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-1][j-2] == ' ') {
        if((i >=0) && (j >= 0)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-1][j+2] == ' ') {
        if((i >=0) && (j <= 7)){
            k = Alokasi(kuda, i, j);
            InsertFirst(ML, k);
        }
    }
}

void scBishop (List *ML, int i, int j, char warnaBdk){
    int intv = 1; //interval
    address m;
    char B, b;
    Bidak menteri; menteri.PType = warnaBdk;
    if (warnaBdk == 'B')    {menteri.PName = B;}
    else    {menteri.PName = b; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while (cBoard[i+1][j+1] == ' '){
        if ((i > 7) && (j > 7)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        i += 1;
    }
    while (cBoard[i-1][j-1] == ' '){
        if ((i < 0) && (j < 0)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        i += 1;
    }
    while (cBoard[i+1][j-1] == ' '){
        if ((i > 7) && (j < 0)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        i += 1;
    }
    while (cBoard[i-1][j+1] == ' '){
        if ((i < 0) && (j > 7)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        i += 1;
    }
}

void scKing (List *ML, int i, int j, char warnaBdk){
    address Alok;
    char K, k;
    Bidak raja; raja.PType = warnaBdk;
    if (warnaBdk == 'B')    {raja.PName = K;}
    else    {raja.PName = k; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    if (cBoard[i][j+1] == ' '){
        if ((j <= 7)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i][j-1] == ' '){
        if ((j >= 0)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j] == ' '){
        if (i <= 7){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j] == ' '){
        if (i >= 0) {
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
        //NGECEK SERONGNYA
    if (cBoard[i+1][j+1] == ' '){
        if ((i <= 7) && (j <= 7)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j+1] == ' '){
        if ((i >= 0) && (j <= 7)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j-1] == ' '){
        if ((i >= 0) && (j >= 0)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j-1] == ' '){
        if ((i <= 7) && (j >= 0)){
            Alok = Alokasi(raja, i, j);
            InsertFirst(ML, Alok);
        } 
    }
}

