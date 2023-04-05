
#include "test.h"

int key_hook(int keycode, t_player *p)
{
	if (keycode == 13)
		p_xup(p);
	else if (keycode == 1)
		p_xdown(p);
	else if (keycode == 0)
		p_ydown(p);
	else if (keycode == 2)
		p_yup(p);
	else if (keycode == 123)
		p_dirup(p);
	else if (keycode == 124)
		p_dirdown(p);
	else
		return (0);
	//TO DO : refresh affichage
	return (0);
}
