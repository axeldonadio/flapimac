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

void drawSpaceship(Spaceship s){
    glColor3ub(s.c.red, s.c.green, s.c.blue);
    glBegin(GL_QUADS);
		glVertex2f(s.Pmax.x-1, s.Pmax.y);
		glVertex2f(s.Pmax.x, s.Pmax.y);
        glVertex2f(s.Pmin.x+1, s.Pmin.y);
		glVertex2f(s.Pmin.x, s.Pmin.y);
	glEnd();
}

void drawEnemies(Enemies e){
	if(e != NULL){
		drawSpaceship(*e);
		drawEnemies(e->next);
	}
}

void addSpaceship(Enemies *e, int x, int y, int red, int green, int blue){
	if(*e == NULL){
		*e = allocSpaceship(x, y, red, green, blue);
	}
	else{
		addSpaceship(&(*e)->next, x, y, red, green, blue);
	}
}

void collisionEnemies(Player *p, Enemies e){
	while(e != NULL){
		if ((int)p->Pmin.x == e->Pmin.x && (int)p->Pmin.y == e->Pmin.y && (int)p->Pmax.x == e->Pmax.x && (int)p->Pmax.y == e->Pmax.y){
	        printf("CRASH\n");
	    }
		e = e->next;
	}
	   
}
