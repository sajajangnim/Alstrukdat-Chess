#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"

extern char cBoard[8][8];

//Deklarasi fungsi dan prosedur
void moveP (List *ML, Piece P);
void moveR (List *ML, Piece P);
void moveH (List *ML, Piece P);
void moveB (List *ML, Piece P);
void moveQ (List *ML, Piece P);
void moveK (List *ML, Piece P);

void moveP(List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address A = Nil;
    if (PType(P) == 'B') {
        if (i == 1) {
            if (cBoard[i+2][j] == ' '){     //cek depan B
                A = AlokPiece(P);
                InsertFirst(ML, A);
            }
        }
        if (cBoard[i+1][j] == ' ') {
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    else{
        if (i == 6) {
            if (cBoard[i-2][j] == ' ' ) {
                A = AlokPiece(P);
                InsertFirst(ML, A);
            }
        }    
        if (cBoard[i-1][j] == ' ') {
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    //BLM ADA KASUS KALO DI SERONGYA ADA MUSUH, TRS BISA JALAN KE SITU
    //HRS BIKIN CHECK DULU
}

void scRook(List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address A = Nil;
    int n = 1;
    while (cBoard[i][j+n] == ' ') { //cek kanan
        if (n == 8){break; }
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n += 1;
    }
    n = 1;
    while (cBoard[i][j-n] == ' ') { //cek kiri
        if (n < 0){break; }
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n -= 1;
    }

    n = 1;
    while (cBoard[i+n][j] == ' ') { //cek depan
        if (n == 8){break; }
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n += 1;
    }
    n = 1;
    while (cBoard[i-n][j] == ' ') { //cek blkg
        if (n == 0){break; }
        A =  AlokPiece(P);
        InsertFirst(ML, A);
        n -= 1;
    }
}
//MSH HRS DICEK  LG KONDISI BERENTINYA KALO IDX ARRAY BRP
//sc horse idx nya 0-7
void scHorse (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address k;
        //NGECEK BISA JALAN GA
    if (cBoard[i+2][j+1] == ' ') {
        if((i <=7) && (j <= 7)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i+2][j-1] == ' ')  {
        if((i <=7) && (j >= 0)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-2][j-1] == ' ') {
        if((i >=0) && (j >= 0)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-2][j+1] == ' ') {
        if((i >=0) && (j <= 7)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    //
    else if (cBoard[i+1][j+2] == ' ') {
        if((i <=7) && (j <= 7)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i+1][j-2] == ' ') {
        if((i <=7) && (j >= 0)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-1][j-2] == ' ') {
        if((i >=0) && (j >= 0)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
    else if (cBoard[i-1][j+2] == ' ') {
        if((i >=0) && (j <= 7)){
            k =  AlokPiece(P);
            InsertFirst(ML, k);
        }
    }
}

void scBishop (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    int intv = 1; //interval
    address m;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while (cBoard[i+intv][j+intv] == ' ') {
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j-intv] == ' ') {
        if ((i -intv< 0) && (j-intv < 0)){
            break;
        }
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i+intv][j-intv] == ' ') {
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-1][j+1] == ' ') {
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        m =  AlokPiece(P);
        InsertFirst(ML, m);
        intv += 1;
    }
}

void scKing (List *ML, Piece P){
    int j = X(P); int i = Y(P);
    address Alok;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    if (cBoard[i][j+1] == ' ') {
        if ((j <= 7)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i][j-1] == ' ') {
        if ((j >= 0)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j] == ' ') {
        if (i <= 7){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j] == ' ') {
        if (i >= 0) {
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    //NGECEK SERONGNYA
    if (cBoard[i+1][j+1] == ' '){
        if ((i <= 7) && (j <= 7)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j+1] == ' ') {
        if ((i >= 0) && (j <= 7)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i-1][j-1] == ' ') {
        if ((i >= 0) && (j >= 0)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
    if (cBoard[i+1][j-1] == ' ') {
        if ((i <= 7) && (j >= 0)){
            Alok =  AlokPiece(P);
            InsertFirst(ML, Alok);
        } 
    }
}

void scQueen(List *ML, Piece P){
    int j = X(P); int i = Y(P);
    int intv = 1; //interval
    address r = Nil;

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while (cBoard[i+intv][j+intv] == ' ') {
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j-intv] == ' ') {
        if ((i-intv < 0) && (j-intv < 0)){
            break;
        }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i+intv][j-intv] == ' ') {
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j+intv] == ' ') {
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }

    intv = 1;
    while (cBoard[i][j+intv] == ' ') { //cek kanan
        if (j+intv == 8){break; }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i][j-intv] == ' ') { //cek kiri
        if (j-intv < 0){break; }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }

    intv = 1;
    while (cBoard[i+intv][j] == ' ') { //cek depan
        if (i+intv == 8){break; }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv += 1;
    }
    intv = 1;
    while (cBoard[i-intv][j] == ' ') { //cek blkg
        if (i-intv == 0){break; }
        r =  AlokPiece(P);
        InsertFirst(ML, r);
        intv -= 1;
    }
}