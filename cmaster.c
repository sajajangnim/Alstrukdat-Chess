//Implementasi cmaster.h

#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"

extern char cBoard[8][8];
//List *ML, char **cb, char warnaBdk

void scPawn(List *ML, int i, int j, char warnaBdk){
    char P, p;
    Bidak pion;
    pion.PType = warnaBdk;
    address A;
    boolean found;
    while (!found){
        if (warnaBdk == 'B'){
            pion.PName = P;
            if (j == 7){
                if (cBoard[i-2][j] == ' '){
                    A = Alokasi(pion, i, j);
                    InsertFirst(ML, A);
                    found = true; break;
                }
            }
            if (cBoard[i-1][j] == ' '){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
                found = true; break;
            }
        }
        else{
            pion.PName = p;
            if (j == 2){
                if (cBoard[i+2][j] == ' '){
                    A = Alokasi(pion, i, j);
                    InsertFirst(ML, A);
                    found = true; break;
                }
            }    
            if (cBoard[i+1][j] == ' '){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
                found = true; break;
            }
        }    
    }
    //BLM ADA KASUS KALO DI SERONGYA ADA MUSUH, TRS BISA JALAN KE SITU
    //HRS BIKIN CHECK DULU
}

void scRook(List *ML, int i, int j, char warnaBdk){
    char R, r;
    boolean found = false;
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
    while ((cBoard[i][j+1] == ' ') && !found){ //cek kanan
        if (n == 9){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n += 1;
        found = true;
    }
    n = j;
    while ((cBoard[i][j-1] == ' ') && !found){ //cek kiri
        if (n == 0){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n -= 1;
        found = true;
    }

    n = i;
    while ((cBoard[i+1][j] == ' ') && !found){ //cek depan
        if (n == 8){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n += 1;
        found = true;
    }
    n = i;
    while ((cBoard[i-1][j] == ' ') && !found){ //cek blkg
        if (n == 0){break; }
        A = Alokasi(benteng, i, j);
        InsertFirst(ML, A);
        n -= 1;
        found = true;
    }
}
//MSH HRS DICEK  LG KONDISI BERENTINYA KALO IDX ARRAY BRP
//sc horse idx nya 0-7
void scHorse (List *ML, int i, int j, char warnaBdk){
    boolean found = false;
    char H, h;
    Bidak kuda;
    address k;
    if(warnaBdk == 'B'){    //INISIALISASI BIDAK, PTYPENYA APA?
        kuda.PName = H; }
    else {
        kuda.PName = h; }
    kuda.PType = warnaBdk;
        //NGECEK BISA JALAN GA
    while (!found){
        if (cBoard[i+2][j+1] == ' '){
            if((i <=7) && (j <= 7)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i+2][j-1] == ' ') {
            if((i <=7) && (j >= 0)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i-2][j-1] == ' ') {
            if((i >=0) && (j >= 0)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i-2][j+1] == ' ') {
            if((i >=0) && (j <= 7)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i+1][j+2] == ' ') {
            if((i <=7) && (j <= 7)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i+1][j-2] == ' ') {
            if((i <=7) && (j >= 0)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i-1][j-2] == ' ') {
            if((i >=0) && (j >= 0)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
        else if (cBoard[i-1][j+2] == ' ') {
            if((i >=0) && (j <= 7)){
                k = Alokasi(kuda, i, j);
                InsertFirst(ML, k);
                found = true;break;
            }
        }
    }
}

void scBishop (List *ML, int i, int j, char warnaBdk){
    int intv = 1; //interval
    address m;
    char B, b;
    boolean found = false;
    Bidak menteri; menteri.PType = warnaBdk;
    if (warnaBdk == 'B')    {menteri.PName = B;}
    else    {menteri.PName = b; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while ((cBoard[i+intv][j+intv] == ' ') && !found){
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i-intv][j-intv] == ' ') && !found){
        if ((i -intv< 0) && (j-intv < 0)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i+intv][j-intv] == ' ') && !found){
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i-1][j+1] == ' ') && !found){
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        m = Alokasi(menteri, i, j);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
}

void scKing (List *ML, int i, int j, char warnaBdk){
    address Alok;
    char K, k;
    boolean found = false;
    Bidak raja; raja.PType = warnaBdk;
    if (warnaBdk == 'B')    {raja.PName = K;}
    else    {raja.PName = k; }
    
    while (!found){
    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
        if (cBoard[i][j+1] == ' '){
            if ((j <= 7)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i][j-1] == ' '){
            if ((j >= 0)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i+1][j] == ' '){
            if (i <= 7){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i-1][j] == ' '){
            if (i >= 0) {
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        //NGECEK SERONGNYA
        if (cBoard[i+1][j+1] == ' '){
            if ((i <= 7) && (j <= 7)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i-1][j+1] == ' '){
            if ((i >= 0) && (j <= 7)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i-1][j-1] == ' '){
            if ((i >= 0) && (j >= 0)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
        if (cBoard[i+1][j-1] == ' '){
            if ((i <= 7) && (j >= 0)){
                Alok = Alokasi(raja, i, j);
                InsertFirst(ML, Alok);
                break;
            } 
        }
    }
}

void scQueen(List *ML, int i, int j, char warnaBdk){
    int intv = 1; //interval
    address r = Nil;
    char B, b;
    boolean found = false;
    Bidak ratu; ratu.PType = warnaBdk;
    if (warnaBdk == 'B')    {ratu.PName = B;}
    else    {ratu.PName = b; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while ((cBoard[i+1][j+1] == ' ') && !found){
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i-1][j-1] == ' ') && !found){
        if ((i-intv < 0) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i+1][j-1] == ' ') && !found){
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i-1][j+1] == ' ') && !found){
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    int n = j;
    while ((cBoard[i][j+1] == ' ') && !found){ //cek kanan
        if (n == 9){break; }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    n = j;
    while ((cBoard[i][j-1] == ' ') && !found){ //cek kiri
        if (n == 0){break; }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }

    n = i;
    while ((cBoard[i+1][j] == ' ') && !found){ //cek depan
        if (n == 8){break; }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    n = i;
    while ((cBoard[i-1][j] == ' ') && !found){ //cek blkg
        if (n == 0){break; }
        r = Alokasi(ratu, i, j);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }
}

void scanList(List L, List *ML){
    address P = First(L);
    while (P != Nil){
        Piece temp = PInfo(P);  //expression must have pointer type:(
        int i = temp.X; int j = temp.Y;
        if (BInfo(temp).PType == 'B'){
            switch (cBoard[i][j]) {
            case ('P'): scPawn(ML, i, j, BType(temp)); break;
            case ('R'): scRook(ML, i, j, BType(temp)); break;
            case ('H'): scHorse(ML, i, j, BType(temp)); break;
            case ('B'): scBishop(ML, i, j, BType(temp)); break;
            case ('K'): scKing(ML, i, j, BType(temp)); break;
            case ('Q'): scQueen(ML, i, j, BType(temp)); break; 
            default: break;
            }
        }
        else {
            switch (cBoard[i][j]) {
            case ('p'): scPawn(ML, i, j, BType(temp)); break;
            case ('r'): scRook(ML, i, j, BType(temp)); break;
            case ('h'): scHorse(ML, i, j, BType(temp)); break;
            case ('b'): scBishop(ML, i, j, BType(temp)); break;
            case ('k'): scKing(ML, i, j, BType(temp)); break;
            case ('q'): scQueen(ML, i, j, BType(temp)); break; 
            default: break;
            }
        }
        P = Next(P);
    }
}