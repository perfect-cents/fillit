#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct
{
	int	x;
	int	y;
}		t_point;

int		file_len(const char *path);
void	*putboard(t_point **minos, int size);
int		valid_buf(const char buf[], char f);
void	*make_mino_cleanup(t_point *pnts, int i);
t_point	*make_mino(const char buf[]);
t_point	**top_left_minos(t_point **minos);
t_point	**initialize_minos(const char *path, int *mino_nbr);

#endif
