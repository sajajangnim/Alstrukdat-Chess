#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

char Player1[10];
char Player2[10];


void MakeBoard(ChessBoard *T) {
    int i,j;
    for (i = 1; i <= MaxRow; i++) {
        switch (i) {
            case (1): for (j = 1; j <= MaxCol; j++) {
                                switch (j) {
                                    case (1):
                                    case (8): (*T).Board[i][j] = ROOK_B;
                                    case (2):
                                    case (7): (*T).Board[i][j] = KNIGHT_B;
                                    case (3):
                                    case (6): (*T).Board[i][j] = BISHOP_B;
                                    case (4): (*T).Board[i][j] = QUEEN_B;
                                    case (5): (*T).Board[i][j] = KING_B;
                                }
            }
            case (2): for (j = 1; j <= MaxCol; j++) {
                                (*T).Board[i][j] = PAWN_B;
            }
            case (7): for (j = 1; j <= MaxCol; j++) {
                                (*T).Board[i][j] = PAWN_W;
            }
            case (8): for (j = 1; j <= MaxCol; j++) {
                                switch (j) {
                                    case (1):
                                    case (8): (*T).Board[i][j] = ROOK_W; break;
                                    case (2):
                                    case (7): (*T).Board[i][j] = KNIGHT_W; break;
                                    case (3):
                                    case (6): (*T).Board[i][j] = BISHOP_W; break;
                                    case (4): (*T).Board[i][j] = QUEEN_W; break;
                                    case (5): (*T).Board[i][j] = KING_W; break;
                                }
            }
            default: for (j = 1; j <= MaxCol; j++) {
                                (*T).Board[i][j] = ' ';
            }
        }
    }
}

void DisplayBoard(ChessBoard T) {
    int i;
    int j;
    int n = 8;

    printf("BLACK: %s", Player1);
    for (i = 1; i <= 15; i++) {
        printf(" ");
    }
    printf("white: %s\n", Player2);

    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
    for (i = 1; i <= 8; i++) {
        j = 1;
        printf("|| ");
        while (j <= (n)) {
            printf("%c", T.Board[i-1][j-1]);
            printf(" || ");
            j++;
        }
        printf("\n");
    }
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
}