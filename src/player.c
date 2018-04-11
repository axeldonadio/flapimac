#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "player.h"

/*
*   allocates memory to the player
*   parameters are : x : position y
*                    y : position y
*                    red : color rgb
*                    green : color rgb
*                    blue : color rgb
*   @return Player
*/
Player allocPlayer(int x, int y, int red, int green, int blue ) {
	Player p;
	p.Pmin.x = x;
	p.Pmin.y = y;
	p.Pmax.x = x + 1;
	p.Pmax.y = y + 1;
    
    p.c.red = red;
    p.c.green = green;
    p.c.blue = blue;
	return p;
}

/*  
*   draw a square which represents the player
*/
void drawPlayer(Player p){
    glColor3ub(p.c.red, p.c.green, p.c.blue);
    glBegin(GL_QUADS);
		glVertex2f(p.Pmax.x-1, p.Pmax.y);
		glVertex2f(p.Pmax.x, p.Pmax.y);
        glVertex2f(p.Pmin.x+1, p.Pmin.y);
		glVertex2f(p.Pmin.x, p.Pmin.y);
	glEnd();
}

/*  
*   Takes in parameters the player and the action : 0 or 1
*   1 : player goes up
*   0 : player goes down
*/
void movePlayer(Player p, int action){
    if (action == 1){
        p.Pmin.y++;
        p.Pmax.y++;
        printf("up\n");
    }
    else{
        p.Pmin.y--;
        p.Pmax.y--;
        printf("down\n");
    }
}