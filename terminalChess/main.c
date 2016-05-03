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
	int piece_num;
	/* Play gaem */
	while(420){
		/* Swap out with FPGA version of getline() */
		/* Will likely have to write from scratch */
		rd_sz = getline(&cmnd, &n, stdin);
		cmnd[rd_sz - 1] = '\0'; /* Override the newline with null */
		parse_cmnd(cmnd, rd_sz, &r, &c, &type);	
		printf("%s    %d\n", cmnd, (int)rd_sz);	
		if(r >= 8 || c >= 8) continue;
		/* Now we know what kind of piece, and the final destination */	
		/* Make sure there is a piece of the specified type that can get here */
		if( (piece_num = check_reachability(turn, c, r, type, 
		(turn%2 == 0 ? black_pieces : white_pieces), b)) != -1){

			move = (turn%2 == 0 ? &black_pieces[piece_num] : &white_pieces[piece_num]);
			/* Make sure moving wouldn't put us in check */
			if(move->type != KING){

				/* If we are taking an enemy piece, take that into account
 * 				when considering if we will be in check */
				if(b[c][r] != NULL) b[c][r]->dead = 1;
				
				/* Simulate having moved to check if we'd still be in check */
				b[move->x][move->y] = NULL;
				piece * temp = b[c][r];
				b[c][r] = move;


				if(check_check(b, move, (turn%2 == 0 ? black_pieces : white_pieces),
					 (turn%2 == 0 ? white_pieces : black_pieces) )){
				
					/* Reset piece */
					b[move->x][move->y] = move;
					b[c][r] = temp;

	
					if(b[c][r] != NULL) b[c][r]->dead = 0;
					continue;



				}
				else {
					/* Reset board to prep for actual move */
					b[move->x][move->y] = move;
					b[c][r] = temp;

				}
				
				
			}
			else {
			
				/* See if the king is tryna move into check */
				if(b[c][r] != NULL) b[c][r]->dead = 1;
				piece temp;
				temp.x = c;
				temp.y = r;
				
				if(check_coord(b, &temp, (turn%2 == 1 ? black_pieces : white_pieces))){
					if(b[c][r] != NULL) b[c][r]->dead = 0;
					continue;	
				}	
				
				if(b[c][r] != NULL) b[c][r]->dead = 0;
			}
			int killed = killed_piece(b, c, r, pieces);
			printf("Killed %d\n", killed);
			
			/* Check if we are castling */
			if(move->type == KING && c == (c > move->x ? move->x + 2 : move->x - 2)){
				if(turn == WHITE){
					if(c > move->x) printf("White kingside castle\n");
					else printf("White queenside castle\n"); 
				}
				else {
					if(c > move->x) printf("Black kingside castle\n");
					else printf("Black queenside castle\n"); 
				}
			}
			move_piece(b, move, c, r);


			/* Check if the other team is in check */
			if(check_check(b, move, (turn%2 == 0 ? white_pieces : black_pieces),
				 (turn%2 == 1 ? white_pieces : black_pieces) )){
			
				printf((turn%2 == 0 ? "White" : "Black"));
				printf("is in check!\n");
			}
		}
		else continue;
	
		turn = (turn + 1) % 2;

		print_board(b);	
			
	}

return 0;

}


