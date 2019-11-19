#include "boolean.h"
#include "matriks.h"

#ifndef CHESSBOARD_H 
#define CHESSBOARD_H

/* Kamus Umum */

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


/* Definisi elemen dan koleksi objek */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeBoard (MATRIKS *M);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas [MaxRow][MaxCol] */

/* Untuk menampilkan papan catur */
void DisplayBoard(MATRIKS *M);

/* Untuk menampilkan papan catur setelah pemain bergerak */
void ChangeBoard(int, int, int, int);
/* ********** SELEKTOR ********** */
/* *** Menghasilkan sebuah elemen *** */

#endif