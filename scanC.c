//Implementasi cmaster.h

#include <stdio.h>
#include <stdlib.h>
#include "cmaster.h"

extern char cBoard[8][8]; /*= {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'B' , 'k' , 'q' , 'B' , 'h' , 'r' }
                };*/
//List *ML, char **cb, char warnaBdk

void scPawn(List *ML, int i, int j, char warnaBdk){
    //int j = temp.X; int i = temp.Y;
    Bidak pion; pion.PType = warnaBdk;
    address A = Nil;
    boolean found = false;
    if ((warnaBdk == 'B') && !found){
        pion.PName = 'P';
        if ((i == 1) && !found){
            if (cBoard[i+2][j] == ' '){     //cek depan B
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
        }
        if ((cBoard[i+1][j] == ' ') && !found){
            A = Alokasi(pion, j, i);
            InsertFirst(ML, A);
            found = true;
        }
    }
    else if ((warnaBdk == 'w') && !found){
        pion.PName = 'p';
        if ((i == 6) && !found){
            if ((cBoard[i-2][j] == ' ' ) && !found){
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
        }    
        if ((cBoard[i-1][j] == ' ') && !found){
            A = Alokasi(pion, j, i);
            InsertFirst(ML, A);
            found = true;
        }
    }
    //BLM ADA KASUS KALO DI SERONGYA ADA MUSUH, TRS BISA JALAN KE SITU
    //HRS BIKIN CHECK DULU
}

void scRook(List *ML, int i, int j, char warnaBdk){
    //int j = temp.X; int i = temp.Y;
    boolean found = false;
    address A = Nil;
    Bidak benteng; benteng.PType = warnaBdk;
    if (warnaBdk == 'B'){
        benteng.PName = 'R';
    }
    else{
        benteng.PName = 'r';
    }
    int n = 1;
    while ((cBoard[i][j+n] == ' ') && !found){ //cek kanan
        if (j+n == 8){break; }
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
        n += 1;
        found = true;
    }
    n = 1;
    while ((cBoard[i][j-n] == ' ') && !found){ //cek kiri
        if (j-n < 0){break; }
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
        n -= 1;
        found = true;
    }

    n = 1;
    while ((cBoard[i+n][j] == ' ') && !found){ //cek depan
        if (i+n == 8){break; }
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
        n += 1;
        found = true;
    }
    n = 1;
    while ((cBoard[i-n][j] == ' ') && !found){ //cek blkg
        if (i-n == 0){break; }
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
        n -= 1;
        found = true;
    }
}
//MSH HRS DICEK  LG KONDISI BERENTINYA KALO IDX ARRAY BRP
//sc horse idx nya 0-7
void scHorse (List *ML, int i, int j, char warnaBdk){
    boolean found = false;
    Bidak kuda;
    address k;
    if(warnaBdk == 'B'){
        kuda.PName = 'H'; }
    else {
        kuda.PName = 'h'; }
    kuda.PType = warnaBdk;
        //NGECEK BISA JALAN GA
    if ((cBoard[i+2][j+1] == ' ') && !found){
        if((i+2 <=7) && (j+1 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if ((cBoard[i+2][j-1] == ' ') && !found) {
        if((i+2 <=7) && (j-1 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if (cBoard[i-2][j-1] == ' ') {
        if((i-2 >=0) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if (cBoard[i-2][j+1] == ' ') {
        if((i-2 >=0) && (j+1 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    //
    else if (cBoard[i+1][j+2] == ' ') {
        if((i+1 <=7) && (j+2 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if (cBoard[i+1][j-2] == ' ') {
        if((i+1 <=7) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if (cBoard[i-1][j-2] == ' ') {
        if((i-1 >=0) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    else if (cBoard[i-1][j+2] == ' ') {
        if((i-1 >=0) && (j+2 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
}

void scBishop (List *ML, int i, int j, char warnaBdk){
    int intv = 1; //interval
    address m;
    boolean found = false;
    Bidak menteri; menteri.PType = warnaBdk;
    if (warnaBdk == 'B')    {menteri.PName = 'B';}
    else    {menteri.PName = 'b'; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while ((cBoard[i+intv][j+intv] == ' ') && !found){
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        m = Alokasi(menteri, j, i);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i-intv][j-intv] == ' ') && !found){
        if ((i -intv< 0) && (j-intv < 0)){
            break;
        }
        m = Alokasi(menteri, j, i);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i+intv][j-intv] == ' ') && !found){
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        m = Alokasi(menteri, j, i);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
    intv = 1;
    while ((cBoard[i-intv][j+intv] == ' ') && !found){
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        m = Alokasi(menteri, j, i);
        InsertFirst(ML, m);
        intv += 1;
        found = true;
    }
}

void scKing (List *ML, int i, int j, char warnaBdk){
    address Alok;
    boolean found = false;
    Bidak raja; raja.PType = warnaBdk;
    if (warnaBdk == 'B')    {raja.PName = 'K';}
    else    {raja.PName = 'k'; }
    
    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    if ((cBoard[i][j+1] == ' ') && !found){
        if ((j+1 <= 7)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i][j-1] == ' ') && !found){
        if ((j-1 >= 0)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i+1][j] == ' ') && !found){
        if (i+1 <= 7){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i-1][j] == ' ') && !found){
        if (i-1 >= 0) {
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    //NGECEK SERONGNYA
    if (cBoard[i+1][j+1] == ' '){
        if ((i+1 <= 7) && (j+1 <= 7)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i-1][j+1] == ' ') && !found){
        if ((i-1 >= 0) && (j+1 <= 7)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i-1][j-1] == ' ') && !found){
        if ((i-1 >= 0) && (j-1 >= 0)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if ((cBoard[i+1][j-1] == ' ') && !found){
        if ((i+1 <= 7) && (j-1 >= 0)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
}

void scQueen(List *ML, int i, int j, char warnaBdk){
    int intv = 1; //interval
    address r = Nil;
    boolean found = false;
    Bidak ratu; ratu.PType = warnaBdk;
    if (warnaBdk == 'B')    {ratu.PName = 'B';}
    else    {ratu.PName = 'b'; }

    //INISIALISASI BIDAK ^. NGECEK BISA JALAN GA >
    while ((cBoard[i+intv][j+intv] == ' ') && !found){
        if ((i+intv > 7) && (j+intv > 7)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i-intv][j-intv] == ' ') && !found){
        if ((i-intv < 0) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i+intv][j-intv] == ' ') && !found){
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    while ((cBoard[i-intv][j+intv] == ' ') && !found){
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    int n = 1;
    while ((cBoard[i][j+n] == ' ') && !found){ //cek kanan
        if (j+n == 8){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    n = 1;
    while ((cBoard[i][j-n] == ' ') && !found){ //cek kiri
        if (j-n < 0){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }

    n = 1;
    while ((cBoard[i+n][j] == ' ') && !found){ //cek depan
        if (i+n == 8){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    n = 1;
    while ((cBoard[i-n][j] == ' ') && !found){ //cek blkg
        if (i-n == 0){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }
}

void scanList(List L, List *ML){
    //printf("tes\n");
    address P = First(L);
    while (P != Nil){
        Piece temp = PInfo(P);  //expression must have pointer type:(
        int j = temp.X; int i = temp.Y;
        if (BType(BInfo(temp)) == 'B'){
            switch (cBoard[i][j]) {
            case ('P'): scPawn(ML, i, j, PType(temp)); P = Next(P); break;
            case ('R'): scRook(ML, i, j, PType(temp)); P = Next(P); break;
            case ('H'): scHorse(ML, i, j, PType(temp)); P = Next(P);break;
            case ('B'): scBishop(ML, i, j, PType(temp)); P = Next(P);break;
            case ('K'): scKing(ML, i, j, PType(temp));  P = Next(P);break;
            case ('Q'): scQueen(ML, i, j, PType(temp));   P = Next(P);break; 
            default: break;
            }
        }
        else if (BType(BInfo(temp)) == 'w'){
            switch (cBoard[i][j]) {
            case ('p'): scPawn(ML, i, j, PType(temp)); P = Next(P);  break;
            case ('r'): scRook(ML, i, j, PType(temp)); P = Next(P);  break;
            case ('h'): scHorse(ML, i, j, PType(temp)); P = Next(P);  break;
            case ('b'): scBishop(ML, i, j, PType(temp)); P = Next(P);  break;
            case ('k'): scKing(ML, i, j, PType(temp)); P = Next(P);  break;
            case ('q'): scQueen(ML, i, j, PType(temp)); P = Next(P);  break; 
            default: break;
            }
        }
    }
}