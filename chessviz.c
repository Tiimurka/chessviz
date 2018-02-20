#include <stdio.h>

int main(void){
	char  board [8][8] = {0};
	board [0][0] = 'r';
	board [0][1] = 'n';
	board [0][2] = 'b';
	board [0][3] = 'q';
	board [0][4] = 'k';
	board [0][5] = 'b';
	board [0][6] = 'n';
	board [0][7] = 'r';
	int i, j;
	for (i=0; i<7; ++i){
		for (j=0; j<7; ++j) {
			printf ("%c", board [i][j]);
		}
		printf ("\n");
	}
	
	return 0;
}
	
	