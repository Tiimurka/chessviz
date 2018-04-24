all: chessviz

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/board_initialization.o: src/board_initialization.c
	gcc -Wall -Werror -c src/board_initialization.c -o build/board_initialization.o 

build/move.o: src/move.c
	gcc -Wall -Werror -c src/move.c -o build/move.o 

build/decode.o: src/decode.c
	gcc -Wall -Werror -c src/decode.c -o build/decode.o

build/output.o: src/output.c
	gcc -Wall -Werror -c src/output.c -o build/output.o

build/checking.o: src/checking.c
	gcc -Wall -Werror -c src/checking.c -o build/checking.o

chessviz: build/checking.o build/board_initialization.o build/move.o build/output.o build/main.o build/decode.o
	gcc -Wall build/checking.o build/board_initialization.o build/move.o build/main.o build/output.o build/decode.o -o chessviz

.PHONY: clean
clean:
	rm -rf build/*.o
