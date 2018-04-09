#include "spaceship.h"
#include "world.h"

Player allocPlayer(int x, int y){
	Player p;
	p.Pmin.x = x;
	p.Pmin.y = y;
	p.Pmax.x = x + 1;
	p.Pmax.y = y + 1;
	return p;
}