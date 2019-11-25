// ADT dan library yang digunakan
/*#include "listchess.h"
#include "chessboard.h"
// benerin include nya rapihin antara queue stack list boolean mainceunah sama cmaster
*/
#include "listchess.h"
#include "stackchess.h"
#include "queuechess.h"
#include "moveC.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef CHESS_
#define CHESS_

//#define PName(P) (P).BInfo->PName
//#define PType(P) (P).BInfo->PType

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
#define Empty ' '

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

extern char cBoard[8][8];/* = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'b' , 'k' , 'q' , 'b' , 'h' , 'r' }
                    };
*/

boolean IsCheckmate (Piece P, List ML);
void scanList(List L, List * ML);
void scPawn(List *ML, int i, int j, char warnaBdk);
void scRook(List *ML, int i, int j, char warnaBdk);
void scHorse (List *ML, int i, int j, char warnaBdk);
void scBishop (List *ML, int i, int j, char warnaBdk);
void scKing (List *ML, int i, int j, char warnaBdk);
void scQueen(List *ML, int i, int j, char warnaBdk);
boolean IsCanEat (char input, int row, int col);
void scPromote(Piece P, List *ML);
void scEnpassant (Piece P, List *ML);
void scCastling (Piece P, List *L, List *ML, Stack S);

#endif