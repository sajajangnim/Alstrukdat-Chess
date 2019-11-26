#include "stackchess.h"
#include <string.h>
#include <stdio.h>

int main(){
    Stack Stek;
    CreateEmptyS(&Stek);
    SInfo S;
    Piece benteng;benteng.BInfo.PName = 'R';benteng.BInfo.PType = 'B';
    benteng.X = 1; benteng.Y = 1;
    S.PInfo = benteng; S.prevX = 5; S.prevY = 2;
    S.prevMove = 's';
    Push(&Stek, S);
    return 0;
}