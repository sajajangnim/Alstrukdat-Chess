
#include "listchess.h"
#include "stackchess.h"

//Deklarasi fungsi dan prosedur
void moveP (List *ML, Piece P);
void moveR (List *ML, Piece P);
void moveH (List *ML, Piece P);
void moveB (List *ML, Piece P);
void moveQ (List *ML, Piece P);
void moveK (List *ML, Piece P);
void movePromote(List *ML, Piece P);
void moveEnpassant (Piece P, List *ML);
void moveCastling (Piece P, List *ML, Stack S);