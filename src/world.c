#include <stdio.h>
#include <stdlib.h>
#include "world.h"


#define MAX 10000

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

int initializeWorld(Player p, Enemies e, Walls w){
	FILE *map;
	map = fopen("map.ppm","r");
	if( map != NULL){
		char buffer[MAX];
		while( fgets( buffer, MAX, map ) != NULL ){
			printf("%s", buffer);
		}
	}
	else{
		return 0;
	}
}