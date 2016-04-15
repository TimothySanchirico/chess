#include "piece.h"

void init_pawn(piece * p){
	
}

void init_pieces(piece * p){
	int i;
	
	for(i = 0; i < 16; i++)
		p[i].team = BLACK;

	p[0].type = ROOK;
	p[1].type = KNIGHT;
	p[2].type = BISHOP;
	p[3].type = KING;
	p[4].type = QUEEN;
	p[5].type = BISHOP;
	p[6].type = KNIGHT;
	p[7].type = ROOK;
	
	/* Init them all to pawns */
	for(i = 8; i < 16; i++)
		p[i].type = PAWN;
	

	for(i = 16; i < 32; i++){
		p[i].team = WHITE;
		if(i < 24) p[i].type = PAWN;
	}

	p[24].type = ROOK;
	p[25].type = KNIGHT;
	p[26].type = BISHOP;
	p[27].type = KING;
	p[28].type = QUEEN;
	p[29].type = BISHOP;
	p[30].type = KNIGHT;
	p[31].type = ROOK;


}



piece * check_reachability(int turn, unsigned int r, unsigned int c, unsigned int type, piece* team){
	int i;
	for(i = 0; i < 16; i++){
		if(type == team[i].type){
			if(type_can_move(turn, type, team[i].x, team[i].y, r, c)){
				return &(team[i]);
			}
		}
	}
	return NULL;	
}

int type_can_move(int team, unsigned int type, unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y){
	switch(type){
		case(PAWN):
			if( (end_y == (team == WHITE ? start_y - 1 : start_y + 1) ) && (start_x == end_x) )
				return 1;
			break;	

	}

	return 0;
}

void move_piece(piece***  b, piece * move, unsigned int r, unsigned int c){
	b[move->x][move->y] = NULL;
	move->x = r;
	move->y = c;
	b[r][c] = move;

}
