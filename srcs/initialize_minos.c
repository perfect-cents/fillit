#include "fillit.h"

static void		*filetominos_cleanup(t_point **minos, int i)
{
	while (i-- > 0)
		ft_memfree(minos[i]);
	return (ft_memfree(minos));
}

static t_point	**filetominos(int fd, int mino_nbr)
{
	t_point	**minos;
	int		status;
	char	buf[21];
	int		i;

	if ((minos = (t_point **)malloc(sizeof(*minos) * (mino_nbr + 1))) == NULL)
		return (ft_memfree(minos));
	status = 0;
	i = 0;
	while ((status = read(fd, buf, 21)) > 20)
	{
		if (!valid_buf(buf, 0) || (minos[i] = make_mino(buf)) == NULL)
			return (filetominos_cleanup(minos, i));
		i++;
	}
	if (status != 20 || !valid_buf(buf, 1) \
	|| (minos[i] = make_mino(buf)) == NULL)
	{
		return (filetominos_cleanup(minos, i));
	}
	minos[i + 1] = NULL;
	return (top_left_minos(minos));
}

t_point			**initialize_minos(const char *path, int *mino_nbr)
{
	int		len;
	int		fd;
	t_point	**minos;

	if ((len = file_len(path)) <= 0 || (len + 1) % 21)
		return (NULL);
	*mino_nbr = ((len + 1) / 21) + 1;
	fd = open(path, O_RDONLY);
	minos = filetominos(fd, *mino_nbr);
	close(fd);
	return (minos);
}
