#ifndef PIECE_H
#define PIECE_H

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
	unsigned int move_dir;
	unsigned int move_length;
} piece;

void init_pawn(piece * p);

void init_pieces(piece * p);

#endif

