#include <stdio.h>
#include <stdlib.h>
#include "spaceship.h"

Enemies allocSpaceship(int x, int y){
	Enemies e;
	e = malloc(sizeof(Enemies));
	if( e != NULL){
		e->Pmin.x = x;
		e->Pmin.y = y;
		e->Pmax.x = x + 1;
		e->Pmax.y = y + 1;
		e->next = NULL;
		return e;
	}
	return NULL;
}