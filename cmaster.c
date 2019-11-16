

#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"
#include "stackchess.h"
#include "chessboard.h"
#include "boolean.h"

//List *ML, char **cb, char warnaBdk
void scanArray(){
    address P = First(L1);
    int i = PInfo(P).X; int j = PInfo(P).Y;
    while (P != Nil){
        if (warnaBdk == 'B'){
            switch (cBoard[i][j]) {
            case ('P'): pawn(); break;
            case ('R'): rook(); break;
            case ('H'): horse(); break;
            case ('C'): camel(); break;
            case ('K'): king(); break;
            case ('Q'): queen(); break; 
            default: break;
            }
        }
        else {
            switch (cBoard[i][j]) {
            case ('p'): scPawn(i, j, warnaBdk); break;
            case ('r'): scRook(); break;
            case ('h'): scHorse(); break;
            case ('c'): scCamel(); break;
            case ('k'): scKing(); break;
            case ('q'): scQueen(); break; 
            default: break;
            }
        }
        P = Next(P);
    }
}

void scPawn(List *ML, int i, int j, char warnaBdk){
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
}

void scRook(List *ML, int i, int j, char warnaBdk){
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
        if (n == 9){break; }
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
