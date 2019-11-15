#ifndef CHESS_
#define CHESS_

// ADT dan library yang digunakan
#include "listchess.h"
#include "chessboard.h"
#include "stackchess.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*bolehkah ini kugantii? karena udh byk yg pake adt di bawah di list
kuliat di stack ga terlalu byk make*/ 
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

#define PName(B) (B)->PName
#define PType(B) (B)->PType
#define BInfo(P)  (P).BInfo
#define X(P) (P).X
#define Y(P) (P).Y
#define BName(P) (P).BInfo.PName
#define BType(P) (P).BInfo.PType

#define PAWN_W 'm'
#define PAWN_B 'M'
#define KING_W 'k'
#define KING_B 'K'
#define KNIGHT_W 'n'
#define KNIGHT_B 'N'
#define BISHOP_W 'b'
#define BISHOP_B 'B'
#define ROOK_W 'r'
#define ROOK_B 'R'
#define QUEEN_W 'q'
#define QUEEN_B 'Q'

void scanBidak (List L, List *ML);


#endif