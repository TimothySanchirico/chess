#ifndef PIECE_H
#define PIECE_H


#include <stdio.h>

#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6
#define WHITE 1
#define BLACK 0


/*  */
typedef struct piece_t {
	unsigned int type;
	unsigned int team; /*1: WHITE, 0: BLACK*/
	unsigned int dead;
	unsigned int x;
	unsigned int y;
	unsigned int emp_flag;
	unsigned int killed;
} piece;

void init_pawn(piece * p);

void init_pieces(piece * p);

int check_reachability(int turn, unsigned int r, unsigned int c, unsigned int type, piece * team, piece *** b);

void move_piece(piece*** b, piece * move, unsigned int r, unsigned int c);

int space_occupied(int x, int y, piece * team);

int check_check(piece ***b, piece * p, piece * myteam, piece * enemy);

int check_coord(piece ***b, piece * dummy, piece * enemy);

int killed_piece(piece *** b, int r, int c, piece * all);

#endif


