
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include "boolean.h"
#include "string.h"
#include "mesin_kar.h"

#define file "leaderboard.txt"

typedef char Skor[5];
typedef int ArrSkor[10];

// ----------------------------------------------

char CC;
boolean EOP;
static FILE *pita;
static int retval;
void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita

Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen("leaderboard.txt", "a");
    ADV();
}
void ADV()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC()
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    if (CC != MARK) {
        return CC;
    }

}

boolean IsEOP()
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/
{
    // TODO --> IMPLEMENTASI FUNGSI INI
    return (CC == MARK);

}


// ---------------------------------------------------

#define NMax 5
#define BLANK ' '
#define MARK '.'

typedef struct {
	char TabKata[NMax+1];
	int Length;
} Kata;

/* State Mesin Kata */

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



void SortLB(Skor S, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)  {     
    // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  {
           if (S[j] < S[j+1]) {
               temp = S[j+1];
               S[j+1] = S[j];
               S[j] = temp;
           }
              
              
        }
   }
}



void WriteLeaderBoard(int S) {
    FILE *fp;
    fp = fopen(file, "a");
    Skor CSkor;
    sprintf(CSkor, "%d", S);
    fputs(CSkor, fp);
    fputs(" ", fp);
    fclose(fp);
}

void ReadLeaderBoard(ArrSkor A) {
    int i = 0;
    int SkorInt;
    FILE *fp;
    fp = fopen(file, "a");
    fputs(".", fp);
    fclose(fp);
    while (!EndKata) {
        STARTKATA(file);
        sscanf(CKata.TabKata, "%d", SkorInt);
        A[i] = SkorInt;
        ADVKATA();
        i++;
    }  
}

void PrintLeaderBoard() {
    printf("Highest Score to Date\n");




}

