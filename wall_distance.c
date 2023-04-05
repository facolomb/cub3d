
#include "test.h"
#include "parsing.h"

double wallDistance(t_player *player, int x, int y)
{
	double a;
	double b;
	double c;

	a = x - player->pos_x;
	b = y - player->pos_y;
	c = sqrt(pow(a, 2) + pow(b, 2));
	return (c);
}
