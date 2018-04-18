all:
	gcc -Wall -o chessviz main.c board_initialization.c  checking.c decode.c move.c output.c
