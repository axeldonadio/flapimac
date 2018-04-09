#ifndef SPACESHIP_H
#define SPACESHIP_H

	#include "world.h"

	typedef struct spaceship {
		Coord Pmin;
		Coord Pmax;
		struct spaceship *next;
	} Spaceship, *Enemies;

#endif