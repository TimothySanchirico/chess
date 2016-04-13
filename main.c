/* main.c
 * The Game runs here */
#include <stdio.h>
#include "board.h"

/* The Game Board */

/* All the pieces, the first 16 are whites */
piece pieces[32];
piece * brd[8][8];

int main(void){

	piece ** rows[8];
	piece * columns[64];
	int i;
	for(i = 0; i < 8; i++){
		rows[i] = &columns[8*i];
	}
	board b = rows;
	/* Init the shit */
	init_pieces(pieces);
	init_board(b, pieces);


	print_board(b);	

	/* Play gaem */
	while(420);

return 0;

}


