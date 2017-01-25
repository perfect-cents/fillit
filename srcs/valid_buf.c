#include "fillit.h"

int		valid_buf(const char buf[], char f)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			l += (i < 15 && buf[i + 5] == '#') + (buf[i + 1] == '#') + \
			(i > 4 && buf[i - 5] == '#') + (i > 0 && buf[i - 1] == '#');
			j++;
		}
		else if (buf[i] == '\n')
		{
			if ((i + 1) % 5)
				return (0);
		}
		else if (buf[i] != '.')
			return (f);
		i++;
	}
	return (j == 4 && (f ? 1 : buf[i] == '\n') && (l == 6 || l == 8));
}
