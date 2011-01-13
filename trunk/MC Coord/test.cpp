#include <stdio.h>
#include <stdlib.h>

int main () {
	FILE * pFile;
	pFile = fopen ("myfile.txt","w");
	fprintf (pFile, "I printed this using fprintf!\n");
	fclose (pFile);
	return 0;
}