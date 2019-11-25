#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"

int main () {
	char namafile;
	IgnoreBlank();
	SalinKata();
	STARTKATA (&namafile);
	ADVKATA ();
	return 0;
}
