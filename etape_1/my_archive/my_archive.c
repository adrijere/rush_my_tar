/*
** my_archive.c for my_archive in /home/mathon_j/rendu/rush_my_tar/etape_1
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Nov 29 20:55:14 2013 Jérémy MATHON
** Last update Sat Nov 30 18:05:47 2013 Jérémy MATHON
*/

#include	<stdio.h>
#include	<stdarg.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<errno.h>
#include	<sys/stat.h>
#include	"my_tar.h"

void		my_put_in_tar(int x, int y)
{
  unsigned char buffer[SIZE_BUFFER];
  unsigned int	nb;

  while ((nb = read(y, buffer, SIZE_BUFFER)) != 0)
    {
      write(x, buffer, nb);
      my_put_in_tar(x, y);
    }
}
void		my_header(char *av, int x)
{
  struct stat	header;

  stat(av, &header);
  write(x, av, 100);
  write(x, &header.st_mode, 8);
  write(x, &header.st_uid, sizeof(header.st_uid));
  write(x, &header.st_size, 12);
  write(x, &header.st_mtime, 12);
}

int		my_archive(char **av)
{
  int		i;
  int		x;
  int		y;
  i = 2;
  creat (av[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  while (av[i] != NULL)
    {
      if ((x = open(av[i], O_WRONLY)) == -1)
	{
	  perror("ERROR ");
	  exit(EXIT_FAILURE);
	}
      if ((y = open(av[i], O_RDONLY)) == -1)
	{
	  perror("ERROR ");
	  exit(EXIT_FAILURE);
	}
      my_header(av[i], x);
      my_put_in_tar(x, y);
    }
}

int	main(int ac, char **av)
{
  my_archive(av);
}
