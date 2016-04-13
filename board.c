#include "board.h"


void print_board(board b){
	if(b == NULL) return;

	int i= 0, j, color = 0, row =8;
	char column = 'A';
	for(; i < 8; i++){
		j = 0;

		printf(" %d", row--);

		for(; j < 8; j++){
			/* Set Background Color */
			printf(color%2 == 0 ? "\x1b[41m" : "\x1b[44m" );
			print_piece(b, j,i);
			color++; 
		}
		color++;

				
		printf("\x1b[0m\n");
	}
	if(i == 8)
		printf("   A B C D E F G H \n");
	
}

void print_piece(board b, int x, int y) {
	
	if (b[x][y] == NULL) 
		printf("  ");

	else {
		/* Set the color */
		printf( b[x][y]->team == WHITE ? "\x1b[37m" : "\x1b[30m" );
		switch(b[x][y]->type){

			case(PAWN):
				printf(" P");
				break;
			case(KNIGHT):
				printf(" K");
				break;
			case(BISHOP):
				printf(" B");
				break;
			case(ROOK):
				printf(" R");
				break;
			case(QUEEN):
				printf(" Q");
				break;
			case(KING):
				printf(" K");
				break;

			default:
				printf("  ");
				break;
		}
		/* Reset color settings */
		printf("\x1b[0m");
	}

	

}

void init_board(board b, piece * p){
	int i;

	/* Init Rows with pieces seperately */
	for(i = 0; i < 8; i++){
		b[i][0] = &p[i];
	}
	/* Init Rows with pieces seperately */
	for(i = 0; i < 8; i++){
		b[i][1] = &p[i+8];
	}

	for(i = 0; i < 8; i++){
		int j;
		for(j = 2; j < 6; j++ ){
			b[i][j] = NULL;
		}
	}

	for(i = 0; i < 8; i++){
		b[i][6] = &p[i+16];
	}
	
	for(i = 0; i < 8; i++){
		b[i][7] = &p[i+24];
	}

}

