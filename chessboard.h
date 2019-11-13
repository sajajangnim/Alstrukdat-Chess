#include "boolean.h"

#ifndef CHESSBOARD_H 
#define CHESSBOARD_H

/* Kamus Umum */

#define MaxRow 8
#define MaxCol 8
#define MaxStatus 8

/* Definisi elemen dan koleksi objek */
typedef char ElType;
typedef int PlayWhite;
typedef int PlayBlack;

typedef struct {
    PlayWhite PW [MaxStatus];
} WhiteStatus;

typedef struct {
    PlayBlack PB [MaxStatus]
} BlackStatus;

typedef struct 
{
	ElType Board [MaxRow][MaxCol]; /* memori tempat penyimpan elemen (container) */
} ChessBoard;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeBoard (ChessBoard *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas [MaxRow][MaxCol] */

/* Untuk menampilkan papan catur */
void DisplayBoard();

/* Untuk menampilkan papan catur setelah pemain bergerak */
void ChangeBoard(int, int, int, int);
/* ********** SELEKTOR ********** */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

#endif