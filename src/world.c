#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "player.h"
#include "spaceship.h"

Walls allocObstacle(int x, int y){
	Walls w;
	w = malloc(sizeof(Walls));
	if( w != NULL){
		w->Pmin.x = x;
		w->Pmin.y = y;
		w->Pmax.x = x + 1;
		w->Pmax.y = y + 1;
		w->next = NULL;
		return w;	
	}
	return NULL;
}

int drawWorld(Player p, Enemies *e, Walls *w){

	return 1;
}