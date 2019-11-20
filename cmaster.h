// ADT dan library yang digunakan
/*#include "listchess.h"
#include "chessboard.h"
// benerin include nya rapihin antara queue stack list boolean mainceunah sama cmaster
*/
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef CHESS_
#define CHESS_

typedef struct{
    char PName;
    char PType;
} Bidak;
/*typedef struct {
    int X;
    int Y;
} posisi;
*/
typedef struct {
    Bidak BInfo;
    int X;
    int Y;
    //posisi CurrLoc;
    //posisi NextLoc;
} Piece;

#define Nil 0
#define BName(B) (B).PName
#define BType(B) (B).PType
#define BInfo(P)  (P).BInfo
#define X(P) (P).X
#define Y(P) (P).Y
#define PName(P) (P).BInfo->PName
#define PType(P) (P).BInfo->PType

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
/*
const PAWN_W 1 //pion
const PAWN_B 1
const KING_W 10
const KING_B 10
const KNIGHT_W 2 //kuda
const KNIGHT_B 2
const BISHOP_W 4 //menteri
const BISHOP_B 4
const ROOK_W 4 //benteng
const ROOK_B 4
const QUEEN_W 8
const QUEEN_B 8
*/

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