#include "fillit.h"

int		file_len(const char *path)
{
	int		fd;
	char	buf;
	int		len;
	int		status;

	fd = open(path, O_RDONLY);
	if (fd == -1 || (status = read(fd, &buf, 1)) < 0)
	{
		return (-1);
	}
	close(fd);
	fd = open(path, O_RDONLY);
	len = 0;
	while ((status = read(fd, &buf, 1)) > 0)
	{
		len++;
	}
	close(fd);
	return (status != 0 ? -1 : len);
}
