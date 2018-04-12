#include <stdio.h>
#include <stdlib.h>
#include "world.h"


#define MAX 10000

Walls allocObstacle(int x, int y, int red, int green, int blue){
	Walls w;
	w = malloc(sizeof(Obstacle));
	if( w != NULL){
		w->Pmin.x = x;
		w->Pmin.y = y;
		w->Pmax.x = x + 1;
		w->Pmax.y = y + 1;
		
		w->c.red = red;
		w->c.green = green;
		w->c.blue = blue;
		w->next = NULL;
	}
	return w;	
}

void addObstacle(Walls w, int x, int y, int red, int green, int blue){
	//printf("x : %d, y : %d, r : %d, v : %d, b : %d\n", x , y, red, green, blue);
	//fflush(stdout);
	if(w == NULL){
		w = allocObstacle(x, y, red, green, blue);
		printf(" x :%d , y :%d \n", x, y);
	}
	else{
		addObstacle(w->next, x, y, red, green, blue);

	}
}

void foo ( char *line, int buffer[MAX], int *count ) {
    int num, i = 0, len;
    while ( sscanf( line, "%d%n", &num, &len ) == 1 ) {
        buffer[i] = num;
        line += len;    // step past the number we found
        i++;            // increment our count of the number of values found
    }
    *count = i;
}

void initializeWorld(Player *p, Enemies e, Walls w){
	FILE *map;
	map = fopen("map.ppm","r");
	if( map != NULL){
		int buffer[MAX];
		char line[MAX];
		int count;
		int i = 0;
		int j = 0;
		int r, v, b;
		while( fgets( line, MAX, map ) != NULL ){
			foo( line, buffer, &count );
			while(j < count){
				
				r = buffer[j++];
				v = buffer[j++];
				b = buffer[j++];
				printf("%d ", r);
				printf("%d ", v);
				printf("%d ", b);
				if(v == 255){
					//enemies
					//addSpaceship(e, i, j, 0, 255, 0);
				}
				else if( r == 255 ){
					//obstacle
					addObstacle(w, (j/3)-1, i, 255, 0, 0);
				}
				else if( r == 248 && v == 254 && b == 14){
					//player
					*p = allocPlayer((j/3)-1, i, 248, 254, 14 );
				}
				//printf("%d", j);
			}
			printf("\n");
			j = 0;
			i++;
		}
	}
}