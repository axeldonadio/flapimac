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

void foo ( char *line, int buffer[MAX], int *count ) {
    int num, i = 0, len;
    while ( sscanf( line, "%d%n", &num, &len ) == 1 ) {
        //printf( "Number %d is %d\n", i, num );
        buffer[i] = num;
        line += len;    // step past the number we found
        i++;            // increment our count of the number of values found
    }
    *count = i;
}

void initializeWorld(Player p, Enemies e, Walls w){
	FILE *map;
	map = fopen("map.ppm","r");
	if( map != NULL){
		int buffer[MAX];
		char line[MAX];
		int count, i;
		while( fgets( line, MAX, map ) != NULL ){
			//printf("%s", buffer);
			foo( line, buffer, &count );
			for(i = 0; i < count; i++){
				printf("%d ", buffer[i]);
			}
			printf("\n");
		}
	}
}