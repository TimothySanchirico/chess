#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "piece.h"

typedef piece*** board;

/* Prints the ASCII Board */
void print_board(board b);

/* Prints The Piece at the particular square */
void print_piece(board b, int x, int y);

/* Initializes the board to the starting config */
void init_board(board b, piece * p);

void * parse_cmnd(char * cm, int n,unsigned int *r,unsigned int *c,unsigned int * type);

#endif

