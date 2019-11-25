
#include "leaderboard.h"

#define file "leaderboard.txt"

int main() {
    int SB = 900;
    int SW = 788;
    ArrSkor LB;
    WriteLeaderBoard(SB);
    WriteLeaderBoard(SW);
    
    ReadLeaderBoard(LB);
    
    printf("%d\n", LB[0]);
    printf("%d\n", LB[11]);
    

    return 0;
}