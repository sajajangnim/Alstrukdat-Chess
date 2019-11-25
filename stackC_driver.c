#include <stdio.h>
#include <stdlib.h>
#include "stackchess.h"

int main () {
	Stack stackC;
	SInfo X;
	CreateEmptyS (&stackC);
	IsEmptyS (stackC);
	IsFullS (stackC);
	Push (&stackC, X);
	Pop (&stackC, &X);

}
