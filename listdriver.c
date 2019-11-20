#include "listchess.h"
#include <stdio.h>

int main(){
    List BList, WList;
    CreateList(&BList, 'B'); CreateList(&WList, 'w');
    printf("%d\n", NbElmt(WList));
    printf("%d\n", NbElmt(BList));
    PrintInfo(BList); PrintInfo(WList);
    return 0;
}