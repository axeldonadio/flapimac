#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "player.h"

<<<<<<< HEAD
typedef struct spaceship {
    Coord Pmin;
    Coord Pmax;
    Color c;
    struct spaceship *next;
} Spaceship, *Enemies;

Enemies allocSpaceship(int x, int y, int red, int green, int blue);

void drawEnemies(Enemies e);
=======
	typedef struct spaceship {
		Coord Pmin;
		Coord Pmax;
		Color c;
		struct spaceship *next;
	} Spaceship, *Enemies;
>>>>>>> dev

	Enemies allocSpaceship(int x, int y, int red, int green, int blue);
	void addSpaceship(Enemies *e, int x, int y, int red, int green, int blue);

#endif