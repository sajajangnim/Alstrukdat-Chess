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

boolean IsCheckmate (Piece P, List ML){
    Piece P;
    address temp;
    List move; CreateEmptyL(&move);
    scanList(ML, &move);
    temp = First(move);
    Piece tpiece = P;
    boolean bisa = false;
    int i = tpiece.Y; int j = tpiece.Y;
    while (temp != Nil){
        List moveBidak; CreateEmptyL(&moveBidak);
        switch (PName(PInfo(temp))){
        case ('P'): case ('p'): moveP(&moveBidak, PInfo(temp)); break;
        case ('R'): case ('r'): moveR(&moveBidak, PInfo(temp)); break;
        case ('H'): case ('h'): moveH(&moveBidak, PInfo(temp)); break;
        case ('B'): case ('b'): moveB(&moveBidak, PInfo(temp)); break;
        case ('K'): case ('k'): moveK(&moveBidak, PInfo(temp)); break;
        case ('Q'): case ('q'): moveQ(&moveBidak, PInfo(temp)); break;
        default: break;
        }
        if (cBoard[P.Y][P.X] == ' '){
            if (IsEqualPiece(tpiece, moveBidak.First->PInfo)){
                bisa = false;
                break;
            }
        }
        if (cBoard[i][j+1] == ' ') {
            if ((j <= 7)){
                tpiece.X +=1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa = false;
                    break;
                }
            }
        }
        if (cBoard[i][j-1] == ' ') {
            if ((j >= 0)){
                tpiece.X -=1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa = false;
                    break;
                }
            }
        }
        if (cBoard[i+1][j] == ' ') {
            if (i <= 7){
                tpiece.Y += 1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa =  false;
                    break;
                }
            }
        }
        if (cBoard[i-1][j] == ' ') {
            if (i >= 0) {
                tpiece.Y -=1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa =  false;
                    break;
                }
            }
        }
        //NGECEK SERONGNYA
        if (cBoard[i+1][j+1] == ' '){
            if ((i <= 7) && (j <= 7)){
                tpiece.Y +=1; tpiece.X += 1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa =  false;
                    break;
                }
            } 
        }
        if (cBoard[i-1][j+1] == ' ') {
            if ((i >= 0) && (j <= 7)){
                tpiece.Y -=1; tpiece.X += 1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa = false;
                    break;
                }
            }
        } 
        if (cBoard[i-1][j-1] == ' ') {
            if ((i >= 0) && (j >= 0)){
                tpiece.Y -=1; tpiece.X -= 1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa = false;
                    break;
                }
            } 
        }
        if (cBoard[i+1][j-1] == ' ') {
            if ((i <= 7) && (j >= 0)){
                tpiece.Y +=1; tpiece.X -= 1;
                if (IsEqualPiece(moveBidak.First->PInfo, tpiece)){
                    bisa = false;
                    break;
                }
            }
        }
        temp = Next(temp);
    }
    return bisa;
}

void scPawn(List *ML, int i, int j, char warnaBdk){
    //int j = temp.X; int i = temp.Y;
    Bidak pion; pion.PType = warnaBdk;
    address A = Nil;
    boolean found = false;
    if ((warnaBdk == 'B') && !found){
        pion.PName = 'P';
        if ((cBoard[i+1][j] == ' ') && !found){
            if (i <= 6){
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
            else if ((i == 1) && !found){
                if (cBoard[i+2][j] == ' '){     //cek depan B
                    A = Alokasi(pion, j, i);
                    InsertFirst(ML, A);
                    found = true;
                }
            }
        }
        if (IsCanEat(warnaBdk, i+1,j+1) || IsCanEat(warnaBdk, i+1, j-1)){
            if (!found){
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
        }
        if ((cBoard[i][j+1] == 'p' || cBoard[i][j-1] == 'p') && !found){
            A = Alokasi(pion, j, i);
            InsertFirst(ML, A);
        }
    }
    if ((warnaBdk == 'w') && !found){
        pion.PName = 'p';  
        if ((cBoard[i-1][j] == ' ') && !found){
            if (i >= 0){
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
            else if ((i == 6) && !found){
                if (cBoard[i-2][j] == ' ' ){
                    A = Alokasi(pion, j, i);
                    InsertFirst(ML, A);
                    found = true;
                }
            }  
        }
        if (IsCanEat(warnaBdk, i-1,j+1) || IsCanEat(warnaBdk, i-1, j-1)){
            if (!found){
                A = Alokasi(pion, j, i);
                InsertFirst(ML, A);
                found = true;
            }
        }
        if ((cBoard[i][j+1] == 'P' || cBoard[i][j-1] == 'P') && !found){
            A = Alokasi(pion, j, i);
            InsertFirst(ML, A);
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
    if ((IsCanEat(warnaBdk, i,j+n)) && !found){
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
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
    if ((IsCanEat(warnaBdk, i, j-n)) && !found){
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
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
    if ((IsCanEat(warnaBdk, i+n,j)) && !found){
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
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
    if ((IsCanEat(warnaBdk, i-n, j)) && !found){
        A = Alokasi(benteng, j, i);
        InsertFirst(ML, A);
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
    if ((IsCanEat(warnaBdk, i+2, j+1)) && !found){
        if((i+2 <=7) && (j+1 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((cBoard[i+2][j-1] == ' ') && !found) {
        if((i+2 <=7) && (j-1 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i+2, j-1)) && !found){
        if((i+2 <=7) && (j-1 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k );
            found = true;
        }
    }
    if ((cBoard[i-2][j-1] == ' ') && !found) {
        if((i-2 >=0) && (j-1 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i-2, j-1)) && !found){
        if((i-2 >=0) && (j-1 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((cBoard[i-2][j+1] == ' ') && !found) {
        if((i-2 >=0) && (j+1 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i-2, j+1)) && !found){
        if((i-2 >=0) && (j+1 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    //
    if ((cBoard[i+1][j+2] == ' ') && !found){
        if((i+1 <=7) && (j+2 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i+1, j+2)) && !found){
            if((i+1 <=7) && (j+2 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((cBoard[i+1][j-2] == ' ') && !found){
        if((i+1 <=7) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i+1, j-2)) && !found){
        if((i+1 <=7) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((cBoard[i-1][j-2] == ' ') && !found){
        if((i-1 >=0) && (j-2 >= 0)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i-1, j-2)) && !found){
        if(! ((i-1 >=0) && (j-2 >= 0))){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((cBoard[i-1][j+2] == ' ') && !found){
        if((i-1 >=0) && (j+2 <= 7)){
            k = Alokasi(kuda, j, i);
            InsertFirst(ML, k);
            found = true;
        }
    }
    if ((IsCanEat(warnaBdk, i-1, j+2)) && !found){
        if(!((i-1 >=0) && (j+2 <= 7))){
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
    if ((IsCanEat(warnaBdk, i+intv, j+intv)) && !found){
        if ((i+intv <= 7) && (j+intv <= 7)){
            m = Alokasi(menteri, j, i);
            InsertFirst(ML, m);
            found = true;
        }
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
    if ((IsCanEat(warnaBdk, i-intv, j-intv)) && !found){
        if ((i-intv <= 7) && (j-intv <= 7)){
            m = Alokasi(menteri, j, i);
            InsertFirst(ML, m);
            found = true;
        }
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
    if ((IsCanEat(warnaBdk, i+intv, j-intv)) && !found){
        if ((i+intv <= 7) && (j-intv <= 7)){
            m = Alokasi(menteri, j, i);
            InsertFirst(ML, m);
            found = true;
        }
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
    if ((IsCanEat(warnaBdk, i-intv, j+intv)) && !found){
        if ((i-intv <= 7) && (j+intv <= 7)){
            m = Alokasi(menteri, j, i);
            InsertFirst(ML, m);
            found = true;
        }
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
    if (IsCanEat(warnaBdk, i, j+1) && !found){
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
    if (IsCanEat(warnaBdk, i, j-1) && !found){
        if ((j-1 <= 7)){
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
    if (IsCanEat(warnaBdk, i+1, j) && !found){
        if ((i+1 <= 7)){
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
    if (IsCanEat(warnaBdk, i-1, j) && !found){
        if ((i-1 <= 7)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    //NGECEK SERONGNYA
    if ((cBoard[i+1][j+1] == ' ') && !found){
        if ((i+1 <= 7) && (j+1 <= 7)){
            Alok = Alokasi(raja, j, i);
            InsertFirst(ML, Alok);
            found = true;
        } 
    }
    if (IsCanEat(warnaBdk, i+1, j+1) && !found){
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
    if (IsCanEat(warnaBdk, i-1, j+1) && !found){
        if ((i-1 <= 7) && (j+1 <= 7)){
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
    if (IsCanEat(warnaBdk, i-1, j-1) && !found){
        if ((i-1 <= 7) && (j-1 <= 7)){
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
    if (IsCanEat(warnaBdk, i+1, j-1) && !found){
        if ((i+1 <= 7) && (j-1 <= 7)){
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
    if (warnaBdk == 'B')    {ratu.PName = 'Q';}
    else    {ratu.PName = 'q'; }

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
    if ((IsCanEat(warnaBdk, i+intv, j+intv)) && !found){
        if ((i+intv <= 7) && (j+intv <= 7)){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    intv = 1;
    while ((cBoard[i-intv][j-intv] == ' ') && !found){
        if ((i-intv < 0) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i-intv, j-intv)) && !found){
        if ((i-intv <= 7) && (j-intv <= 7)){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    intv = 1;
    while ((cBoard[i+intv][j-intv] == ' ') && !found){
        if ((i+intv > 7) && (j-intv < 0)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i+intv, j-intv)) && !found){
        if ((i+intv <= 7) && (j-intv <= 7)){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    intv = 1;
    while ((cBoard[i-intv][j+intv] == ' ') && !found){
        if ((i-intv < 0) && (j+intv > 7)){
            break;
        }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        intv += 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i-intv, j+intv)) && !found){
        if ((i-intv <= 7) && (j+intv <= 7)){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    int n = 1;
    while ((cBoard[i][j+n] == ' ') && !found){ //cek kanan
        if (j+n == 8){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i, j+n)) && !found){
        if (j+n <= 7){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    n = 1;
    while ((cBoard[i][j-n] == ' ') && !found){ //cek kiri
        if (j-n < 0){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i, j-n)) && !found){
        if (j-n >= 0){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    n = 1;
    while ((cBoard[i+n][j] == ' ') && !found){ //cek depan
        if (i+n == 8){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n += 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i+n, j)) && !found){
        if (i+n <= 7){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
    }
    n = 1;
    while ((cBoard[i-n][j] == ' ') && !found){ //cek blkg
        if (i-n == 0){break; }
        r = Alokasi(ratu, j, i);
        InsertFirst(ML, r);
        n -= 1;
        found = true;
    }
    if ((IsCanEat(warnaBdk, i-n, j)) && !found){
        if (i-n >= 0){
            r = Alokasi(ratu, j, i);
            InsertFirst(ML, r);
            found = true;
        }
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
        if (BType(BInfo(temp)) == 'w'){
            switch (cBoard[i][j]) {
            case ('p'): scPawn(ML, i, j, PType(temp)); P = Next(P); break;
            case ('r'): scRook(ML, i, j, PType(temp)); P = Next(P); break;
            case ('h'): scHorse(ML, i, j, PType(temp)); P = Next(P); break;
            case ('b'): scBishop(ML, i, j, PType(temp)); P = Next(P); break;
            case ('k'): scKing(ML, i, j, PType(temp)); P = Next(P); break;
            case ('q'): scQueen(ML, i, j, PType(temp)); P = Next(P); break; 
            default: break;
            }
        }
    }
}

boolean IsCanEat (char input, int row, int col){
    boolean eat;
    if (input == 'B'){
        switch (cBoard[row][col]){
        case ('p'):
        case ('r'):
        case ('h'):
        case ('b'):
        case ('k'):
        case ('q'): eat = true;break;
        default: eat = false; break;
        }
    }
    else{
        switch (cBoard[row][col]) {
            case ('P'):
            case ('R'):
            case ('H'):
            case ('B'):
            case ('K'):
            case ('Q'): eat = true;break; 
            default: eat = false; break;
        }
    }
    return eat;
}

void scPromote(Piece P, List *ML){
    address A;
    if (P.BInfo.PName == 'P') {
        if (P.Y == 6 && cBoard[Y(P)+1][X(P)] == ' '){
                A = AlokPiece(P);
                InsertFirst(ML, A);
        }
    }
    else if (P.BInfo.PName == 'p') {
        if (Y(P) == 1 && cBoard[Y(P)-1][X(P)] == ' '){
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
}

void scEnpassant (Piece P, List *ML){
    address A;
    if (P.BInfo.PName == 'P') {
        if (cBoard[Y(P)][X(P)+1] == 'p' || cBoard[Y(P)][X(P)-1] == 'p'){
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
    else if (P.BInfo.PName == 'p') {
        if (cBoard[Y(P)][X(P)+1] == 'P' || cBoard[Y(P)][X(P)-1] == 'P'){
            A = AlokPiece(P);
            InsertFirst(ML, A);
        }
    }
}

void scCastling (Piece P, List *L, List *ML, Stack S){
    //if (IsCheckmate(P, *L)){}
    boolean foundR = false; boolean emptyright = false;
    boolean foundK = false; boolean emptyleft = false;
    address A, K;
    for (int i = 0; !foundR; i++){
        if (S.T[i].PInfo.BInfo.PName == PName(P)) {
            foundR = true;
        }
    }
    for (int i = 0; !foundK; i++){
        if (PName(P) == 'R'){
            if (S.T[i].PInfo.BInfo.PName == 'K') {
                K = 
                foundK = true;
            }
        }
        else if (PName(P) == 'r'){
            if (S.T[i].PInfo.BInfo.PName == 'k') {
                foundK = true;
            }
        }
    }
    if ((!foundK && !foundR)){
        if (!IsCheckmate(P, *L)){
            int intv = 1;
            while (cBoard[P.Y][P.X+intv] == ' ') { //cek kanan
                if (P.X+intv == 8){break; }
                else{
                    emptyright = true;
                    intv += 1;
                }
            }
            intv = 1;
            while (cBoard[P.Y][P.X-intv] == ' ') { //cek kiri
                if (P.X-intv < 0){break; }
                else{
                    emptyleft = true;
                    intv += 1;
                }
            }
            address raja;
            boolean FoundK = false;
            raja = First(*L);
            while ((raja != Nil) && (!FoundK)) {
                if ((PInfo(raja).BInfo.PName == 'K') || (PInfo(raja).BInfo.PName == 'k')) {
                    FoundK = true;
                }
                else {
                    raja = Next(raja);
                }
            }
            if(emptyright){
                if (cBoard[Y(PInfo(raja))][X(PInfo(raja))+3] == 'R' ||cBoard[Y(PInfo(raja))][X(PInfo(raja))+3] == 'r'){
                    A = AlokPiece(P);
                    InsertFirst(ML, A);
                }
            }
            else if(emptyleft){
                if (cBoard[Y(PInfo(raja))][X(PInfo(raja))-4] == 'R' ||cBoard[Y(PInfo(raja))][X(PInfo(raja))-4] == 'r'){
                    A = AlokPiece(P);
                    InsertFirst(ML, A);
                }
            }
        }
    }
}