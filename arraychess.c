#include <stdio.h>
#include <stdlib.h>
#include "arraychess.h"

char Player1[4];
char Player2[4];

void MakeArray(ARRAY *A) {
    for (int i=1; i<=8; i++) {
        if (i == 1) {
            for (int j=1; j<=8; j++) {
                if ((j==1) || (j==8)) {
                    Elmt(*A,(i-1),(j-1)) = ROOK_B;
                } else if ((j==2) || (j==7)) {
                    Elmt(*A,(i-1),(j-1)) = KNIGHT_B;
                } else if ((j==3) || (j==6)) {
                    Elmt(*A,(i-1),(j-1)) = BISHOP_B;
                } else if (j==4) {
                    Elmt(*A,(i-1),(j-1)) = QUEEN_B;
                } else {
                    Elmt(*A,(i-1),(j-1)) = KING_B;
                }
            }
        } else if (i == 2) {
            for (int j=1; j<=8; j++) {
                Elmt(*A,(i-1),(j-1)) = PAWN_B;
            }
        } else if (i == 7) {
            for (int j=1; j<=8; j++) {
                Elmt(*A,(i-1),(j-1)) = PAWN_W;
            }
        } else if (i == 8) {
            for (int j=1; j<=8; j++) {
                if ((j==1) || (j==8)) {
                    Elmt(*A,(i-1),(j-1)) = ROOK_W;
                } else if ((j==2) || (j==7)) {
                    Elmt(*A,(i-1),(j-1)) = KNIGHT_W;
                } else if ((j==3) || (j==6)) {
                    Elmt(*A,(i-1),(j-1)) = BISHOP_W;
                } else if (j==4) {
                    Elmt(*A,(i-1),(j-1)) = QUEEN_W;
                } else {
                    Elmt(*A,(i-1),(j-1)) = KING_W;
                }
            }
        } else {
            for (int j=1; j<=8; j++) {
                Elmt(*A,(i-1),(j-1)) = EMPTY;
            }
        }
    }
}

void DisplayBoard(ARRAY *A) {
    int i;
    int j;
    int n = 8;
    extern char Player1[4];
    extern char Player2[4];
    extern char IdX[8];
    extern int SkorB, SkorW;

    printf("\n");
    printf("\n");
    printf("\n");
    printf("     ");

    printf("%s: %d", Player1, SkorB);
    for (i = 1; i <= 25; i++) {
        printf(" ");
    }
    printf("%s: %d\n", Player2, SkorW);
    printf("\n");

    printf("     ");
    for (i = 1; i <= 8; i++) {
            printf("%c", IdX[i-1]);
            printf("    ");
    }
    printf("\n");

    printf("  ");
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");
    for (i = 1; i <= 8; i++) {
        j = 1;
        printf("%d || ", i);
        while (j <= (n)) {
            printf("%c", Elmt(*A,i-1,j-1));
            printf(" || ");
            j++;
        }
        printf("%d\n", i);
    }
    printf("  ");
    for (i = 1; i <= 42; i++) {
        printf("=");
    }
    printf("\n");

    printf("     ");
    for (i = 1; i <= 8; i++) {
            printf("%c", IdX[i-1]);
            printf("    ");
    }
    printf("\n");
}