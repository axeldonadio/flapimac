#ifndef PLAYER_H
#define PLAYER_H

	typedef struct coord {
		int x;
		int y;
	} Coord;

	typedef struct player {
		Coord Pmin;
		Coord Pmax;
	} Player;

#endif