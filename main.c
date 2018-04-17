#include "board_print_plain.h"

int main(void) {
	char board [8][8] = {0};
	int round = 0;
	FILE *log = fopen("chesslog.txt", "r");
	board_create (board);
	do {
		board_print (board, round);
		board_move (log, board);
		fscanf (log, "%d", &round);
	} while (round != EOF);
	//board_print (board, round);
	return 0;
}
	
	
