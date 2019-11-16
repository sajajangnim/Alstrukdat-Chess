#include "boolean.h"

#ifndef CHESSBOARD_H 
#define CHESSBOARD_H

/* Kamus Umum */

#define MaxRow 8
#define MaxCol 8
#define MaxStatus 8
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
typedef char ElType;
typedef int PlayWhite;
typedef int PlayBlack;

typedef struct {
    PlayWhite PW [MaxStatus];
} WhiteStatus;

typedef struct {
    PlayBlack PB [MaxStatus];
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
void DisplayBoard(ChessBoard T);

/* Untuk menampilkan papan catur setelah pemain bergerak */
void ChangeBoard(int, int, int, int);
/* ********** SELEKTOR ********** */
/* *** Menghasilkan sebuah elemen *** */

#endif