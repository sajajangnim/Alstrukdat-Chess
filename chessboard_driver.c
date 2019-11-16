#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

int main() {
    ChessBoard T;
    MakeBoard(*T);
    DisplayBoard(T);

    return 0;
}