#include "fillit.h"

static void	puttab(char **board)
{
	if (!board)
		return ;
	while (*board)
	{
		ft_putstr(*board);
		ft_putchar('\n');
		board++;
	}
}

static void	**putboard_cleanup(char **tab, int i)
{
	while (i-- > 0)
		ft_memfree(tab[i]);
	return (ft_memfree(tab));
}

void		*putboard(t_point **minos, int size)
{
	char	**tab;
	int		i;

	if ((tab = (char **)malloc(sizeof(*tab) * (size + 1))) == NULL)
		return (ft_memfree(tab));
	i = 0;
	while (i < size)
	{
		if ((tab[i] = ft_memset((char *)malloc(sizeof(**tab) * (size + 1)), \
		'.', size)) == NULL)
			return (putboard_cleanup(tab, i));
		tab[i][size] = '\0';
		i++;
	}
	tab[size] = NULL;
	i = 0;
	while (minos[i])
	{
		tab[minos[i][0].y][minos[i][0].x] = i + 'A';
		tab[minos[i][1].y][minos[i][1].x] = i + 'A';
		tab[minos[i][2].y][minos[i][2].x] = i + 'A';
		tab[minos[i][3].y][minos[i][3].x] = i + 'A';
		i++;
	}
	puttab(tab);
	return (putboard_cleanup(tab, size));
}
