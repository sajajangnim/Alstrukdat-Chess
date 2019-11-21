#include "cmaster.h"
#include "boolean.h"
#include "listchess.h"
#include "stackchess.h"
#include "queuechess.h"
#include <string.h>
#include <stdio.h>

int main(){
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
    /*address P = First(WList);
    while(P!=Nil){
        printf("%c %c %d %d\n", PType(PInfo(P)), PName(PInfo(P)), X(PInfo(P)), Y(PInfo(P)));
        P = Next(P);
    }*/
    address P = First(BList);
    while (P != Nil){
        Piece temp = PInfo(P);
        int i = temp.X; int j = temp.Y;
        if (BType(BInfo(temp)) == 'B'){
            switch (cBoard[i][j]) {
            case ('P'): scPawn(&moveB, i, j, PType(temp)); P = Next(P);break;
            case ('R'): scRook(&moveB, i, j, PType(temp)); P = Next(P);break;
            case ('H'): scHorse(&moveB, i, j, PType(temp)); P = Next(P);break;
            case ('B'): scBishop(&moveB, i, j, PType(temp)); P = Next(P);break;
            case ('K'): scKing(&moveB, i, j, PType(temp)); P = Next(P);break;
            case ('Q'): scQueen(&moveB, i, j, PType(temp)); P = Next(P);break; 
            default: break;
            }
        }
        else {
            switch (cBoard[i][j]) {
            case ('p'): scPawn(&moveB, i, j, PType(temp)); break;
            case ('r'): scRook(&moveB, i, j, PType(temp)); break;
            case ('h'): scHorse(&moveB, i, j, PType(temp)); break;
            case ('b'): scBishop(&moveB, i, j, PType(temp)); break;
            case ('k'): scKing(&moveB, i, j, PType(temp)); break;
            case ('q'): scQueen(&moveB, i, j, PType(temp)); break; 
            default: break;
            }
        }
    }
    //scanList(BList, &moveB);
    PrintInfo(moveB);
    return 0;
}

/*List BList, WList;
    CreateList(&BList, 'B'); CreateList(&WList, 'w');
    printf("%d\n", NbElmt(WList));
    printf("%d\n", NbElmt(BList));
    PrintInfo(BList); PrintInfo(WList);
    */