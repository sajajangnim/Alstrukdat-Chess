/* File: mesin_kata.c */
/* Jingga Mutiara Windyarahma / 18218031 */

#include "mesin_kata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;




void IgnoreBlank() {
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}


void SalinKata() {
    int i = 1;
    while ((CC != MARK) && (CC != BLANK)) {
        CKata.TabKata[i] = GetCC();
        ADV();
        i++;
    }
    CKata.Length = i-1;
}


void STARTKATA(char* filename) {
    char namafile[100];
    START(namafile);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA() {
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    }
    else {
        SalinKata();
    }
}




