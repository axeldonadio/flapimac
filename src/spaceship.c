#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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

void drawEnemies(Enemies e){
    glColor3ub(e->c.red, e->c.green, e->c.blue);
    glBegin(GL_QUADS);
		glVertex2f(e->Pmax.x-1, e->Pmax.y);
		glVertex2f(e->Pmax.x, e->Pmax.y);
        glVertex2f(e->Pmin.x+1, e->Pmin.y);
		glVertex2f(e->Pmin.x, e->Pmin.y);
	glEnd();
}