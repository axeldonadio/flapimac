#ifndef WORLD_H
#define WORLD_H

	typedef struct coord {
		int x;
		int y;
	} Coord;

	typedef struct obstacle {
		Coord Pmin;
		Coord Pmax;
		struct obstacle *next;
	} Obstacle, *Walls;

	int drawWorld(Player p, Enemies *e, Walls *w);
	// Fonction qui récupère un fichier .ppm et dessine un monde.

#endif