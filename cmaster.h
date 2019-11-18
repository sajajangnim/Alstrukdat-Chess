// ADT dan library yang digunakan
#include "listchess.h"
#include "chessboard.h"
#include "stackchess.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef CHESS_
#define CHESS_

typedef struct{
    char PName;
    char PType;
} Bidak;
typedef int posisi;
typedef struct {
    Bidak BInfo;
    posisi X;
    posisi Y;
} Piece;

#define BName(B) (B)->PName
#define BType(B) (B)->PType
#define BInfo(P)  (P).BInfo
#define X(P) (P).X
#define Y(P) (P).Y
#define PName(P) (P).BInfo.PName
#define PType(P) (P).BInfo.PType

#define PAWN_W 'p' //pion
#define PAWN_B 'P'
#define KING_W 'k'
#define KING_B 'K'
#define KNIGHT_W 'h' //kuda
#define KNIGHT_B 'H'
#define BISHOP_W 'b' //menteri
#define BISHOP_B 'B'
#define ROOK_W 'r' //benteng
#define ROOK_B 'R'
#define QUEEN_W 'q'
#define QUEEN_B 'Q'

char cBoard[8][8] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'b' , 'k' , 'q' , 'b' , 'h' , 'r' }
                    };

void scanList(List L, List * ML);
void scPawn(List *ML, int i, int j, char warnaBdk);
void scRook(List *ML, int i, int j, char warnaBdk);
void scHorse (List *ML, int i, int j, char warnaBdk);
void scBishop (List *ML, int i, int j, char warnaBdk);
void scKing (List *ML, int i, int j, char warnaBdk);
void scQueen(List *ML, int i, int j, char warnaBdk);

#endif