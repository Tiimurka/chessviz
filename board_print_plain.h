#include <stdio.h>
#include <stdbool.h>

struct field {
	char letter;
	short number;
};

struct turn {
	bool color;
	struct field old_pos;
	struct field new_pos;
};

char board_create (char board[8][8])
{
	int i;
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
	return 0;
}

void board_print (char board[8][8], int round)
{
	int i, j;
	printf ("round %d\n", round);
	for (i=7; i>=0; --i) {
		for (j=0; j<=7; ++j) {
			printf("%c", board [i][j]);
		}
		printf("\n");
	}
		printf("\n");
		return;
}	

struct turn read_turn (FILE *log, struct turn turn)
{
	//int a, b;
	do{
    fscanf (log, "%c", &turn.old_pos.letter);
	//printf("turn.old_pos.letter is now %c\n", turn.old_pos.letter);
	//if (a == EOF){
	//	printf("a is now %d\n", a);
	//	}
	//b = feof(log);
	//printf("b is now %d\n", b);
	//perror("fscanf");
	} while(turn.old_pos.letter < 64);
	fscanf (log, "%hi", &turn.old_pos.number);
	do{
    fscanf (log, "%c", &turn.new_pos.letter);
	} while(turn.new_pos.letter < 64);
	fscanf (log, "%hi", &turn.new_pos.number);
	return turn;
}

void board_step (char board[8][8], struct turn turn)
{
	char tmp;
	turn.old_pos.letter = turn.old_pos.letter - 'a';
	turn.new_pos.letter = turn.new_pos.letter - 'a';
	tmp = board[turn.old_pos.number][(short)turn.old_pos.letter];
	board[turn.old_pos.number][(short)turn.old_pos.letter] = ' ';
	board[turn.new_pos.number][(short)turn.new_pos.letter] = tmp;
}

void board_move (FILE *log, char board[8][8])
{
	struct turn turn;
	turn.color = 0;
	read_turn (log, turn);
	board_step (board, turn);
	turn.color = 1;
	read_turn (log, turn);
	board_step (board, turn);
}