//Implementasi chess-master.h

#include <stdio.h>
#include <stdlib.h>
#include "chess-master.h"
#include "stackchess.h"
#include "boolean.h"
//#include "queuelist.h"

int main(){
    char pl1[5], pl2[5];
    char cmd[20];
    Stack StackGame;

    boolean win = false;
    printf("Masukkan nama pemain 1: ");scanf("%s", pl1);
    printf("Masukkan nama pemain 1: ");scanf("%s", pl2);
    while ((!IsFull(StackGame)) || (!win)){
        /*tampilin chessboard
        //DeleteHead Queue()
        //if (Q == 'B'){
            printf("Player 1");
        }
        else{
            printf("Player 2");
        }
        printf("Masukkan command: ");scanf("%s", cmd);
        if (cmd == 'MOVE'){
            void scanlistbidak
            taro dilist bidak yg bisa dgerakkin (movelist)
        }
        else if (cmd == 'SPECIAL_MOVE'){

        }
        else if (cmd == 'UNDO'){

        }
        else if (cmd == 'SAVE'{

        }
        else {}
        
        */

    }
    printf("Masukkan command: "); scanf("%s", cmd);

    return 0;
}

