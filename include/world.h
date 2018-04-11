#ifndef WORLD_H
#define WORLD_H
	
	#include "player.h"
	#include "spaceship.h"

	typedef struct obstacle {
		Coord Pmin;
		Coord Pmax;
		struct obstacle *next;
	} Obstacle, *Walls;

	void initializeWorld(Player p, Enemies e, Walls w);
	// Fonction qui récupère un fichier .ppm et dessine un monde.

#endif