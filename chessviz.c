#include <stdio.h>

int main(void) {
	char board [8][8] = {0};
	int i, j;
	board[0][0] = 'r';
	board[0][1] = 'n';
	board[0][2] = 'b';
	board[0][3] = 'q';
	board[0][4] = 'k';
	board[0][5] = 'b';
	board[0][6] = 'n';
	board[0][7] = 'r';
	for (i = 0; i <= 7; ++i)
		board[1][i] = 'p';
	board[7][0] = 'R';
	board[7][1] = 'N';
	board[7][2] = 'B';
	board[7][3] = 'Q';
	board[7][4] = 'K';
	board[7][5] = 'B';
	board[7][6] = 'N';
	board[7][7] = 'R';
	for (i = 0; i <= 7; ++i)
		board[6][i] = 'P';
	for (i=0; i<=7; ++i) {
		for (j=0; j<=7; ++j) {
			printf("%c", board [i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
	
	
