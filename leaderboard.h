#include "mesin_kata.h"
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

FILE *fLB;
fLB = fopen("leaderboard.txt", "a");


boolean SaveLB(char* filename) {
    if (filename==NULL) {
        return false;
    }
    else {
        return true;
    }
}

boolean LoadLB(char* filename) {
    if (filename==NULL) {
        return false;
    }
    else {
        return true;
    }
}

void WriteLeaderBoard(char* filename) {
    
}

void PrintLeaderBoard(boolean P, int S[10]) {
    int i;
    int SkorUrut[10];
    SkorUrut = SortLB(S);
    if (P) {
        printf("Highest Score to Date\n");


    }
}