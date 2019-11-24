/* ********** Definisi TYPE MATRIKS dengan indeks integer dan elemen char ********** */

#ifndef ARRAYCHESS_H
#define ARRAYCHESS_H

#include "boolean.h"

/* Ukuran Minimum dan Maksimum baris dan kolom */
// #define MinRow 1
#define MaxRow 8
// #define MinCol 1
#define MaxCol 8

/* Define Bidak */
#define PAWN_W 'p'
#define PAWN_B 'P'
#define KING_W 'k'
#define KING_B 'K'
#define KNIGHT_W 'h'
#define KNIGHT_B 'H'
#define BISHOP_W 'b'
#define BISHOP_B 'B'
#define ROOK_W 'r'
#define ROOK_B 'R'
#define QUEEN_W 'q'
#define QUEEN_B 'Q'
#define EMPTY ' '

typedef int idx;
typedef char ElTypeA;
typedef struct {
    ElTypeA Mem[MaxRow][MaxCol];
    int NRowEff; /* Banyaknya baris efektif */
    int NColEff; /* Banyaknya kolom efektif */
} ARRAY;

/* SELEKTOR */
#define NRowEff(A) (A).NRowEff
#define NColEff(A) (A).NColEff
#define Elmt(A,i,j) (A).Mem[(i)][(j)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeArray(ARRAY *A);
/* I.S. sembarang */
/* F.S. Terbentuk array A kosong dengan kapasitas [MaxRow][MaxCol] */

/* Untuk menampilkan papan catur */
void DisplayBoard(ARRAY *A);

#endif