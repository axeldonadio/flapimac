#include <stdio.h>
#include <stdlib.h>
#include "spaceship.h"

Enemies allocSpaceship(int x, int y, int red, int green, int blue){
	Enemies e;
	e = malloc(sizeof(Spaceship));
	if( e != NULL){
		e->Pmin.x = x;
		e->Pmin.y = y;
		e->Pmax.x = x + 1;
		e->Pmax.y = y + 1;

		e->c.red = red;
		e->c.green = green;
		e->c.blue = blue;
		e->next = NULL;
	}
	return e;
}

void addSpaceship(Enemies *e, int x, int y, int red, int green, int blue){
	if(*e == NULL){
		*e = allocSpaceship(x, y, red, green, blue);
	}
	else{
		addSpaceship(&(*e)->next, x, y, red, green, blue);
	}
}