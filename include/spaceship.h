#ifndef SPACESHIP_H
#define SPACESHIP_H

	#include "player.h"

	typedef struct spaceship {
		Coord Pmin;
		Coord Pmax;
		struct spaceship *next;
	} Spaceship, *Enemies;

#endif