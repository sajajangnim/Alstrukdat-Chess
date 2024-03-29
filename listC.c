//Widad Istiqomah 18218011
//Implementasi list linear
//24/10/19
#include <stdio.h>
#include <stdlib.h>
#include "listchess.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyL (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateList(List *L, char warnaBidak){
    int i;
    address P = Nil;
    CreateEmptyL(L);
    Bidak Bdk; Bdk.PType = warnaBidak;
    for (i = 0;i <= 7;i++){
        if (warnaBidak == 'B'){
            Bdk.PName = 'P';
            int j = 1;
            P = Alokasi(Bdk, i, j);
            InsertFirst(L, P);
        }
        else if (warnaBidak == 'w'){
            Bdk.PName = 'p';
            int j = 6;
            P = Alokasi(Bdk, i, j);
            InsertFirst(L, P);
        }
    }
    if (warnaBidak == 'B'){
        int i = 0; int j = 0;
        Bdk.PType = 'B';
        while (i <= 7){
            switch (i){
            case (0): Bdk.PName = 'R'; break;
            case (1): Bdk.PName = 'H'; break;
            case (2): Bdk.PName = 'B';break;
            case (3): Bdk.PName = 'K'; break;
            case (4): Bdk.PName = 'Q'; break;
            case (5): Bdk.PName = 'B';break;
            case (6): Bdk.PName = 'H'; break;
            case (7): Bdk.PName = 'R'; break;
            default: break;
            }
            P = Alokasi(Bdk, i, j);
            InsertFirst(L, P);
            i += 1;
        }
    }
    if (warnaBidak == 'w'){
        int i = 0; int j = 7;
        //char b, r, h, k, q, w;
        Bdk.PType = 'w';
        while (i <= 7){
            switch (i){
            case (0): Bdk.PName = 'r'; break;
            case (1): Bdk.PName = 'h'; break;
            case (2): Bdk.PName = 'b';break;
            case (3): Bdk.PName = 'k'; break;
            case (4): Bdk.PName = 'q'; break;
            case (5): Bdk.PName = 'b';break;
            case (6): Bdk.PName = 'h'; break;
            case (7): Bdk.PName = 'r'; break;
            default: break;
            }
            P = Alokasi(Bdk, i, j);
            InsertFirst(L, P);
            i += 1;
        }
    }
}
/****************** Manajemen Memori ******************/
/*Piece AlokPiece (Bidak Bdk, posisi absis, posisi ord){
    Piece temp;
    temp = malloc (sizeof(Piece));
    if (P != Nil){
        BInfo(temp) = Bdk;
        X(temp) = absis;
        Y(temp) = ord;
        return temp;
    }
    else{
        return Nil;
    }
} */
address Alokasi (Bidak Bdk, posisi absis, posisi ord){
    address P;
    Piece temp;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        BInfo(temp) = Bdk;
        X(temp) = absis;
        Y(temp) = ord;
        PInfo(P) = temp;
        Next(P) = Nil;
        return P;
    }
    else{
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

address AlokPiece(Piece Pc){
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        PInfo(P) = Pc;
        Next(P) = Nil;
        return P;
    }
    else{
        return Nil;
    }
}

void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

boolean IsEmpty (List L){
    return (First(L) == Nil);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchBidak (List L, Bidak B){
    address P;
    boolean Found;
    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found)) {
        if ((PInfo(P).BInfo.PName == B.PName) && (PInfo(P).BInfo.PType == B.PType)) {
            Found = true;
        }
        else {
            P = Next(P);
        }
    }
    return P;
}
/* Mencari apakah ada elemen list dengan PName yang sama */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

address SearchPosisi (List L, Piece pc){
    address P;
    boolean Found;
    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found)) {
        if ((PInfo(P).X == pc.X) && (PInfo(P).Y == pc.Y)) {
            Found = true;
        }
        else {
            P = Next(P);
        }
    }
    return P;
}
/* Mencari apakah ada elemen list dengan posisi x dan y yang sama */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean IsEqualPiece (Piece P1, Piece P2){
    if (P1.X == P2.X){
        if (P1.Y == P2.Y){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Bidak B, posisi X, posisi Y){
    address P;
    P = Alokasi(B, X, Y);
    if (P != Nil){
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, Bidak B, posisi X, posisi Y){
    address P;
    P = Alokasi(B, X, Y);
    if (P != Nil){
        InsertLast(L, P);
    }
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, Piece *X){
    address P, nxP;
    P = First(*L);
    (*X) = PInfo(P);
    nxP = Next(P);
    First(*L) = nxP;
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, Piece *X){
    address P, nxP;
    DelLast(L, &P);
    (*X) = PInfo(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address Last;
    Last  = First(*L);
    if (Last == Nil){
        InsertFirst(L, P);
    }
    else{
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    (*P) = First(*L);
    First(*L) = Next(First(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, Piece X){
    address P, prec;
    Piece a;
    P = SearchPosisi(*L,X);
    if (P != Nil){
        if (P == First(*L)){
            DelVFirst(L, &a);
        }
        else{
            P = First(*L);
            while (!IsEqualPiece(PInfo(P), X)){
                prec = P;
                P = Next(P);
            }
            if (IsEqualPiece(PInfo(P), X)){
                Next(prec) = Next(Next(prec));
                Next(P) = Nil;
                Dealokasi(&P);
            }
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    address prec;
    (*P) = First(*L);
    prec = Nil;
    while (Next(*P) != Nil){
        prec = (*P);
        (*P) = Next(*P);
    }
    if (prec == Nil){
        DelFirst (L,P);
    }
    else{
        DelAfter(L, P, prec);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    int i;
    address P;
    P = First(L);
    for (i= 1; !IsEmpty(L); i++){
        printf("%d. ", i);
        switch (BInfo(PInfo(P)).PName){
        case ('P'):
        case ('p'): printf("Pion "); break;
        case ('R'):
        case ('r'): printf("Benteng "); break;
        case ('H'):
        case ('h'): printf("Kuda "); break;
        case ('B'):
        case ('b'): printf("Menteri "); break;
        case ('K'):
        case ('k'): printf("Raja "); break;
        case ('Q'):
        case ('q'): printf("Ratu "); break;
        default: break;
        }
        char row;
        int col;
        switch (X(PInfo(P))){
        case 0: row = 'a'; break;
        case 1: row = 'b'; break;
        case 2: row = 'c'; break;
        case 3: row = 'd'; break;
        case 4: row = 'e'; break;
        case 5: row = 'f'; break;
        case 6: row = 'g'; break;
        case 7: row = 'h'; break;
        default:  break;
        }
        switch (Y(PInfo(P))){
        case 0: col = 1; break;
        case 1: col = 2; break;
        case 2: col = 3; break;
        case 3: col = 4; break;
        case 4: col = 5; break;
        case 5: col = 6; break;
        case 6: col = 7; break;
        case 7: col = 8; break;
        default:  break;
        }
        printf("(%c,%d)\n", row, col);
        P = Next(P);
        if (P == Nil)
        {
            break;
        }
        //else{printf("\n");}
    }   
}

void PrintInfoMove (List L){
    address P;
    P = First(L);
    char row;
    int col;
    int i;
    for (i= 1; !IsEmpty(L); i++){
        printf("%d. ", i);
        switch (X(PInfo(P))){
        case 0: row = 'a'; break;
        case 1: row = 'b'; break;
        case 2: row = 'c'; break;
        case 3: row = 'd'; break;
        case 4: row = 'e'; break;
        case 5: row = 'f'; break;
        case 6: row = 'g'; break;
        case 7: row = 'h'; break;
        default:  break;
        }
        switch (Y(PInfo(P))){
        case 0: col = 1; break;
        case 1: col = 2; break;
        case 2: col = 3; break;
        case 3: col = 4; break;
        case 4: col = 5; break;
        case 5: col = 6; break;
        case 6: col = 7; break;
        case 7: col = 8; break;
        default:  break;
        }
        printf("(%c,%d)\n", row, col);
        P = Next(P);
        if (P == Nil)
        {
            break;
        }
        //else{printf("\n");}
    }   
}


/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int n = 0;
    address P;
    P = First(L);
    while (P != Nil){
        n += 1;
        P = Next(P);
    }
    return n;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
    address P;
    P = First(*L1);
    CreateEmptyL(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateEmptyL(L1);
    CreateEmptyL(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */