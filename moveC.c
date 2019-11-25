#include <stdio.h>
#include <stdlib.h>
#include "moveC.h"
#include "cmaster.h"

extern char cBoard[8][8];

//Implementasi fungsi dan prosedur

void moveP(List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address A = Nil;
    if (PType(P) == 'B') {
        if (i == 1) {
            if (cBoard[i+2][j] == ' '){     //cek depan B
                X(P) = j; Y(P) = i+2;
                A = AlokPiece(P);
                InsertFirst(ML, A);
            }
        }
        if (cBoard[i+1][j] == ' ') {
            X(P) = j; Y(P) = i+1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
        if (IsCanEat(PType(P), i+1,j+1)){
            X(P) = j+1; Y(P) = i+1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
        if (IsCanEat(PType(P), i+1, j-1)){
            X(P) = j-1; Y(P) = i+1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    if (PType(P) == 'w'){
        if (i == 6) {
            if (cBoard[i-2][j] == ' ' ) {
                X(P) = j; Y(P) = i-2;
                A = AlokPiece(P);
                InsertFirst(ML, A);
            }
        }    
        if (cBoard[i-1][j] == ' ') {
            X(P) = j; Y(P) = i-1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
        if (IsCanEat(PType(P), i-1,j+1)){
            X(P) = j+1; Y(P) = i-1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
        if (IsCanEat(PType(P), i-1, j-1)){
            X(P) = j-1; Y(P) = i-1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    //BLM ADA KASUS KALO DI SERONGYA ADA MUSUH, TRS BISA JALAN KE SITU
    //HRS BIKIN CHECK DULU
}

void moveR(List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address A = Nil;
    int n = 1;
    while (cBoard[i][j+n] == ' ') { //cek kanan
        if (n == 8){break; }
        X(P) = j+n; Y(P) = i;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n += 1;
    }
    if (IsCanEat(PType(P), i,j+n)){
        X(P) = j+n; Y(P) = i;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
    }
    n = 1;
    while (cBoard[i][j-n] == ' ') { //cek kiri
        if (n < 0){break; }
        X(P) = j-n; Y(P) = i;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n -= 1;
    }
    if (IsCanEat(PType(P), i,j-n)){
        X(P) = j-n; Y(P) = i;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
    }

    n = 1;
    while (cBoard[i+n][j] == ' ') { //cek depan
        if (n == 8){break; }
        X(P) = j; Y(P) = i+n;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n += 1;
    }
    if (IsCanEat(PType(P), i+n,j)){
        X(P) = j; Y(P) = i+n;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
    }
    n = 1;
    while (cBoard[i-n][j] == ' ') { //cek blkg
        if (n == 0){break; }
        X(P) = j; Y(P) = i-n;
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n -= 1;
    }
}
//MSH HRS DICEK  LG KONDISI BERENTINYA KALO IDX ARRAY BRP
//sc horse idx nya 0-7
void moveH (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address k;
        //NGECEK BISA JALAN GA
    if (cBoard[i+2][j+1] == ' ') {
        if((i+2 <=7) && (j+1 <= 7)){
            k =  Alokasi(BInfo(P), j+1, i+2);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i+2][j-1] == ' ')  {
        if((i+2 <=7) && (j-1 >= 0)){
            k =  Alokasi(BInfo(P), j-1, i+2);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i-2][j-1] == ' ') {
        if((i-2 >=0) && (j-1 >= 0)){
            X(P) = j-1; Y(P) = i-2;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i-2][j+1] == ' ') {
        if((i-2 >=0) && (j+1 <= 7)){
            X(P) = j+1; Y(P) = i-2;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    //
    if (cBoard[i+1][j+2] == ' ') {
        if((i+1 <=7) && (j+2 <= 7)){
            X(P) = j+2; Y(P) = i+1;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i+1][j-2] == ' ') {
        if((i+1 <=7) && (j-2 >= 0)){
            X(P) = j-2; Y(P) = i+1;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i-1][j-2] == ' ') {
        if((i-1 >=0) && (j-2 >= 0)){
            X(P) = j-2; Y(P) = i-1;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    if (cBoard[i-1][j+2] == ' ') {
        if((i-1 >=0) && (j+2 <= 7)){
            X(P) = j+2; Y(P) = i-1;
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
}

void moveB (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    int intv = 1; //interval
    address m;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while (cBoard[i+intv][j+intv] == ' ') {
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        X(P) = j+intv; Y(P) = i+intv;
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j-intv] == ' ') {
        if ((i -intv< 0) && (j-intv < 0)){
            break;
        }
        X(P) = j-intv; Y(P) = i-intv;
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i+intv][j-intv] == ' ') {
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        X(P) = j-intv; Y(P) = i+intv;
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j+intv] == ' ') {
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        X(P) = j+intv; Y(P) = i-intv;
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
}

void moveK (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address Alok;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    if (cBoard[i][j+1] == ' ') {
        if ((j <= 7)){
            X(P) = j+1; Y(P) = i;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i][j-1] == ' ') {
        if ((j >= 0)){
            X(P) = j-1; Y(P) = i;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j] == ' ') {
        if (i <= 7){
            X(P) = j; Y(P) = i+1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j] == ' ') {
        if (i >= 0) {
            X(P) = j; Y(P) = i-1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    //NGECEK SERONGNYA
    if (cBoard[i+1][j+1] == ' '){
        if ((i <= 7) && (j <= 7)){
            X(P) = j+1; Y(P) = i+1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j+1] == ' ') {
        if ((i >= 0) && (j <= 7)){
            X(P) = j+1; Y(P) = i-1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j-1] == ' ') {
        if ((i >= 0) && (j >= 0)){
            X(P) = j-1; Y(P) = i-1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j-1] == ' ') {
        if ((i <= 7) && (j >= 0)){
            X(P) = j-1; Y(P) = i+1;
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
}

void moveQ (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    int intv = 1; //interval
    address r = Nil;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while (cBoard[i+intv][j+intv] == ' ') {
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        X(P) = j+intv; Y(P) = i+intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j-intv] == ' ') {
        if ((i-intv < 0) && (j-intv < 0)){
            break;
        }
        X(P) = j+intv; Y(P) = i-intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i+intv][j-intv] == ' ') {
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        X(P) = j-intv; Y(P) = i+intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j+intv] == ' ') {
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        X(P) = j+intv; Y(P) = i-intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }

    intv = 1;
    while (cBoard[i][j+intv] == ' ') { //cek kanan
        if (j+intv == 8){break; }
        X(P) = j+intv; Y(P) = i;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i][j-intv] == ' ') { //cek kiri
        if (j-intv < 0){break; }
        X(P) = j-intv; Y(P) = i;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }

    intv = 1;
    while (cBoard[i+intv][j] == ' ') { //cek depan
        if (i+intv == 8){break; }
        X(P) = j; Y(P) = i+intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j] == ' ') { //cek blkg
        if (i-intv == 0){break; }
        X(P) = j; Y(P) = i-intv;
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv -= 1;
    }
}

void movePromote(List *ML, Piece P){
    address A;
    if (P.BInfo.PName == 'P') {
        if (Y(P) == 6){
            P.Y +=1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    else if (P.BInfo.PName == 'p') {
        if (Y(P) == 1){
            P.Y -= 1;
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
}