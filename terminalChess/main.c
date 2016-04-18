/* main.c
 * The Game runs here */
#include <stdio.h>
#include "board.h"

/* The Game Board */

/* All the pieces, the first 16 are whites */
piece pieces[32];
piece * brd[8][8];

int main(void){

	/* Set up the board structure */
	piece ** rows[8];
	piece * columns[64];
	int i;
	for(i = 0; i < 8; i++){
		rows[i] = &columns[8*i];
	}
	board b = rows;


	piece * black_pieces = &pieces[0];
	piece * white_pieces = &pieces[16];

	/* Init the shit */
	init_pieces(pieces);
	init_board(b, pieces);


	print_board(b);	

	size_t n = 0, rd_sz;
	
	char * cmnd;
	char line[10];
	int turn = 1;
	unsigned int r, c, type;
	piece * move;
	cmnd = &line[0];
	/* Play gaem */
	while(420){
		/* Swap out with FPGA version of getline() */
		/* Will likely have to write from scratch */
		rd_sz = getline(&cmnd, &n, stdin);
		cmnd[rd_sz - 1] = '\0'; /* Override the newline with null */
		parse_cmnd(cmnd, rd_sz, &r, &c, &type);	

		if(r >= 8 || c >= 8) continue;
		/* Now we know what kind of piece, and the final destination */	
		/* Make sure there is a piece of the specified type that can get here */
		if( (move = check_reachability(turn, c, r, type, (turn%2 == 0 ? black_pieces : white_pieces), b)) != NULL)
			move_piece(b, move, c, r);
		else continue;
	
		turn = (turn + 1) % 2;

		print_board(b);	
			
	}

return 0;

}


