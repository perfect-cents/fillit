#include "fillit.h"

t_point	**top_left_minos(t_point **minos)
{
	int	i;
	int	j;
	int	x_off;
	int	y_off;

	i = 0;
	while (minos[i])
	{
		x_off = 8008135;
		y_off = 8008135;
		j = 0;
		while (j < 4)
		{
			x_off = minos[i][j].x < x_off ? minos[i][j].x : x_off;
			y_off = minos[i][j].y < y_off ? minos[i][j].y : y_off;
			j++;
		}
		j = 0;
		while (j < 4)
		{
			minos[i][j].x -= x_off;
			minos[i][j].y -= y_off;
			j++;
		}
		i++;
	}
	return (minos);
}
