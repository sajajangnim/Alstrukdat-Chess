#include "queuechess.h"
#include <stdlib.h>


boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == 0 && Tail(Q) == 0);
}
boolean IsFull (Queue Q)
{
     return (Head(Q) == 1 && Tail(Q) == MaxElQ(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
int NBElmt (Queue Q)
{   if (IsEmpty(Q)) {
        return 0;
    }
    else if (Head(Q) == Tail(Q)) {
        return (1);
    }
    else if (Head(Q) < Tail(Q)) {
        return (Tail(Q) - Head(Q) + 1);
    }
    else {
        return (MaxElQ(Q)-Head(Q)+1+Tail(Q));
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
    
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxElQ(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else {
        MaxElQ(*Q) = 0;
    }

}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */

{
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
    }
    else {
    Tail(*Q) = Tail(*Q) % MaxElQ(*Q) + 1;
    }
    InfoTail(*Q) = X;
}

void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    
    if (Head(*Q)==Tail(*Q)) {
        *X = InfoHead(*Q);
        Head(*Q)=0;
        Tail(*Q)=0;
    }
    else {
        *X = InfoHead(*Q);   
        Head(*Q) = (Head(*Q) % (*Q).MaxElQ) + 1;
    }
}