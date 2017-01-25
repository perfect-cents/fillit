#include "fillit.h"

t_point		*make_mino(const char buf[])
{
	t_point	*pnts;
	int		i;
	int		j;

	if ((pnts = (t_point *)ft_memalloc(sizeof(*pnts) * 4)) == NULL)
		return (ft_memfree(pnts));
	i = 0;
	j = 0;
	while (i < 20 && j < 4)
	{
		if (buf[i] == '#')
		{
			pnts[j].x = i % 5;
			pnts[j].y = i / 5;
			j++;
		}
		i++;
	}
	return (pnts);
}
