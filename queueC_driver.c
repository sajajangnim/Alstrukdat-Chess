#include <stdio.h>
#include <stdlib.h>
#include "queuechess.h"


int main () {
	
	Queue Q;
	infotype X;
	IsEmptyQ (Q);
	IsFull (Q);
	NBElmt (Q);
	CreateEmptyQ (&Q,2);
	DeAlokasi(&Q);
	Add (&Q, X);
	Del (&Q, &X);
	
	return 0;
}
