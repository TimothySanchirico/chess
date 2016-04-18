#include "piece.h"

void init_pawn(piece * p){
	
}

void init_pieces(piece * p){
	int i;
	
	for(i = 0; i < 16; i++){
		p[i].dead = 0;
		p[i].team = BLACK;

	}

	p[0].type = ROOK;
	p[1].type = KNIGHT;
	p[2].type = BISHOP;
	p[3].type = QUEEN;
	p[4].type = KING;
	p[5].type = BISHOP;
	p[6].type = KNIGHT;
	p[7].type = ROOK;
	
	/* Init them all to pawns */
	for(i = 8; i < 16; i++)
		p[i].type = PAWN;
	

	for(i = 16; i < 32; i++){
		p[i].dead = 0;
		p[i].team = WHITE;
		if(i < 24) p[i].type = PAWN;
	}

	p[24].type = ROOK;
	p[25].type = KNIGHT;
	p[26].type = BISHOP;
	p[27].type = QUEEN;
	p[28].type = KING;
	p[29].type = BISHOP;
	p[30].type = KNIGHT;
	p[31].type = ROOK;


}



piece * check_reachability(int turn, unsigned int r, unsigned int c, unsigned int type, piece* team, piece *** b){
	if(space_occupied(c, r, team))
		return NULL;


	int i;
	for(i = 0; i < 16; i++){
		if(type == team[i].type && team[i].dead == 0){
			if(type_can_move(b, turn, type, team[i].x, team[i].y, r, c)){
				return &(team[i]);
			}
		}
	}
	return NULL;	
}

int space_occupied(int x, int y, piece * team){
	int i;
	for(i = 0; i < 16; i++){
		if(team[i].dead && team[i].x == x && team[i].y == y)
			return 1;
	}
	return 0;
}

int type_can_move(piece *** b, int team, unsigned int type, unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){
	switch(type){
		case(PAWN):
			return pawn_can_move(b, team, type, start_x, start_y, end_x, end_y);	

	}

	return 0;
}

void move_piece(piece***  b, piece * move, unsigned int r, unsigned int c){
	/* Probably where we send shit to the VGA */
	b[move->x][move->y] = NULL;
	move->x = r;
	move->y = c;
	/* Kill the enemy piece */
	if(b[r][c] != NULL)
		b[r][c]->dead = 1;
	b[r][c] = move;

}


int pawn_can_move(piece *** b, int team, unsigned int type, unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){

	/*TODO Empassant*/

	/* If the space is occupied, see if its a diaganol space we can take, otherwise we can't go to an occupied space */
	if(b[end_x][end_y] != NULL){
		if(b[end_x][end_y]->team != team){
			if(end_y == (team == WHITE ? start_y - 1 : start_y + 1) ){
				if(end_x == start_x + 1 || end_x == start_x - 1)
					return 1; 
			}
		}
		else
			return 0;
	}
					
	/* Make sure the space isnt occupied */
	if( (end_y == (team == WHITE ? start_y - 1 : start_y + 1) ) && (start_x == end_x) )
		return 1;
			
	/* If we're still at the start row we can move two */
	else if (start_y == (team == WHITE ? 6 : 1) && (end_y == (team == WHITE ? start_y - 2 : start_y + 2) ) && (start_x == end_x) )
		return 1;
	else
		return 0;

}


int bishop_can_move(piece *** b, int team, unsigned int type, unsigned int start_x, unsigned int start_y,
									 unsigned int end_x, unsigned int end_y){

}


/* Make sure there are no pieces in the way on the diagnol */
int check_diagnol(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){

}

/* Checks all the spaces along the horizontal */
int check_horizontal(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){

}

/* Checks all spaces along the vertical */
int check_vertical(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){

}


