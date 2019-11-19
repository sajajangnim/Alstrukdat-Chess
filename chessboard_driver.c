#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

int main() {
    MATRIKS CBoard;
    MakeBoard(&CBoard);
    DisplayBoard(&CBoard);

    return 0;
}