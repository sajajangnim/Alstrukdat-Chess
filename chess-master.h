#ifndef CHESS_
#define CHESS_




typedef struct {
    int x;
    int y;
} Loc;

typedef struct {
    loc PLoc;
    char PType;
    char PName;
} Piece;

#define Loc(X) Loc.x
#define Loc(Y) Loc.y
#define Piece(Loc) Piece.PLoc
#define Piece(LocX) Piece.PLoc.x
#define Piece(LocY) Piece.PLoc.y
#define Piece(Type) Piece.PType
#define Piece(Name) Piece.PName


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