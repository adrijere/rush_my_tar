/*
** my_archive.c for my_archive in /home/mathon_j/rendu/rush_my_tar/etape_1
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Nov 29 20:55:14 2013 Jérémy MATHON
** Last update Sun Dec  1 18:49:13 2013 Jérémy MATHON
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

int		my_header(char **av,int i, int x)
{
  struct stat	header;
  int		y;

  stat(av[i], &header);
  write(x, av, 100);
  write(x, &header.st_mode, 8);
  write(x, &header.st_uid, 8);
  write(x, &header.st_size, 12);
  write(x, &header.st_mtime, 12);
  if ((y = open(av[i], O_RDONLY)) == -1)
    {
      perror("ERROR ");
      exit(EXIT_FAILURE);
    }
  return (y);
}

int		my_archive(int ac, char **av)
{
  int		i;
  int		x;
  int		y;

  i = 1;
  if ((av[1] == NULL) || (ac < 3))
    {
      printf("./my archive [File_archive] [File ... FileN]\n");
      return (0);
    }
  creat (av[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if ((x = open(av[1], O_WRONLY)) == -1)
    {
      perror("ERROR ");
      exit(EXIT_FAILURE);
    }
  while (av[++i] != 0)
    {
      y = my_header(av, i, x);
      my_put_in_tar(x, y);
    }
}

int	main(int ac, char **av)
{
  my_archive(ac, av);
}
