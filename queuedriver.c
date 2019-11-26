#include "queuechess.h"
#include <string.h>
#include <stdio.h>

int main(){
    Queue Qyu;
    CreateEmptyQ(&Qyu, 3);
    Add(&Qyu, 'w');
    return 0;
}