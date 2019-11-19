#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

char Player1[10];
char Player2[10];


void MakeBoard(MATRIKS *M) {
    Elmt(*M,1,8) = ROOK_B;
    Elmt(*M,2,8) = KNIGHT_B;
    Elmt(*M,3,8) = BISHOP_B;
    Elmt(*M,4,8) = QUEEN_B;
    Elmt(*M,5,8) = KING_B;
    Elmt(*M,6,8) = BISHOP_B;
    Elmt(*M,7,8) = KNIGHT_B;
    Elmt(*M,8,8) = ROOK_B;
    Elmt(*M,1,7) = PAWN_B;
    Elmt(*M,2,7) = PAWN_B;
    Elmt(*M,3,7) = PAWN_B;
    Elmt(*M,4,7) = PAWN_B;
    Elmt(*M,5,7) = PAWN_B;
    Elmt(*M,6,7) = PAWN_B;
    Elmt(*M,7,7) = PAWN_B;
    Elmt(*M,8,7) = PAWN_B;

    Elmt(*M,1,1) = ROOK_W;
    Elmt(*M,2,1) = KNIGHT_W;
    Elmt(*M,3,1) = BISHOP_W;
    Elmt(*M,4,1) = QUEEN_W;
    Elmt(*M,5,1) = KING_W;
    Elmt(*M,6,1) = BISHOP_W;
    Elmt(*M,7,1) = KNIGHT_W;
    Elmt(*M,8,1) = ROOK_W;
    Elmt(*M,1,2) = PAWN_W;
    Elmt(*M,2,2) = PAWN_W;
    Elmt(*M,3,2) = PAWN_W;
    Elmt(*M,4,2) = PAWN_W;
    Elmt(*M,5,2) = PAWN_W;
    Elmt(*M,6,2) = PAWN_W;
    Elmt(*M,7,2) = PAWN_W;
    Elmt(*M,8,2) = PAWN_W;
}

void DisplayBoard(MATRIKS *M) {
  for (int i = 1; i <= 39; i++) {
    printf("=");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,8));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,7));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,6));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,5));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,4));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,3));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,2));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i<=8; i++) {
    printf("%c",Elmt(*M,i,1));
    printf(" || ");
  }
  printf("\n");
  for (int i = 1; i <= 39; i++) {
    printf("=");
  }
  printf("\n");
}