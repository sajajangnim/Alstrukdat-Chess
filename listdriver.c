#include "cmaster.h"
#include "boolean.h"
#include "listchess.h"
#include "stackchess.h"
#include "queuechess.h"
#include <string.h>
#include <stdio.h>

int main(){
        /*address tes;
    tes = First(*L);
    while (tes != Nil){
        printf("%c %c %d %d\n", PType(PInfo(tes)), PName(PInfo(tes)), X(PInfo(tes)), Y(PInfo(tes)));
        tes = Next(tes);
    }
    */
    char cBoard[8][8] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'B' , 'k' , 'q' , 'B' , 'h' , 'r' }
                };
    List BList, WList; CreateList(&BList, 'B'); CreateList(&WList, 'w');
    List moveB, moveW; CreateEmptyL(&moveB), CreateEmptyL(&moveW);
    char warnaBidak = 'B';
    Bidak pion; pion.PType = warnaBidak; pion.PName = 'P';
    printf("%c %c", pion.PType, pion.PName);
    /*
    Bidak pion; pion.PType = warnaBdk;
    address A = Nil;
    boolean found;
    if ((warnaBdk == 'B') && !found){
        pion.PName = 'P';
        if ((j == 1) && !found){
            if (cBoard[i+2][j] == ' '){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
                found = true;
                printf("tes\n");
            }
        }
        if ((cBoard[i+11][j] == ' ') && !found){
            A = Alokasi(pion, i, j);
            InsertFirst(ML, A);
            found = true;
            printf("tes\n");
        }
    }
    else{
        pion.PName = 'p';
        if (j == 6 && !found){
            if ((cBoard[i-2][j] == ' ' ) && !found){
                A = Alokasi(pion, i, j);
                InsertFirst(ML, A);
                found = true;
            }
        }    
        if ((cBoard[i-1][j] == ' ') && !found){
            A = Alokasi(pion, i, j);
            InsertFirst(ML, A);
            found = true;
        }
    }
    //scanList(BList, &moveB);
    PrintInfo(moveB);
    */
    return 0;
}

/*List BList, WList;
    CreateList(&BList, 'B'); CreateList(&WList, 'w');
    printf("%d\n", NbElmt(WList));
    printf("%d\n", NbElmt(BList));
    PrintInfo(BList); PrintInfo(WList);
    */