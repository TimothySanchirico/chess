all : chess piece.o board.o 

chess: piece.o board.o
	gcc -o chess main.c piece.o board.o -g

piece.o: piece.h
	gcc -c piece.c -g

board.o: board.h piece.o
	gcc -c  board.c -g


clean:
	rm *.o chess
