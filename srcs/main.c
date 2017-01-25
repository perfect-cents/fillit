#include "fillit.h"

static void	error_msg(void)
{
	write(2, "error\n", 6);
}

static void	fillit(const char *path)
{
	t_point	**minos;
	int		mino_nbr;
	//t_point	**board;

	if ((minos = initialize_minos(path, &mino_nbr)) == NULL)
	{
		error_msg();
		return ;
	}
	putboard(minos, 4);
	/*if ((board = solver(pieces)) == NULL)
	{
		error_msg();
		return ;
	}
	else
	{
		puttab(board);
	}*/
}

int	main(int ac, const char *av[])
{
	int	i;

	if (ac <= 1)
		return (0);
	else
	{
		i = 1;
		while (i < ac)
		{
			fillit(av[i]);
			i++;
		}
	}
	return (0);
}
