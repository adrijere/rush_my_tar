/*
** my_archive.c for my_archive in /home/mathon_j/rendu/rush_my_tar/etape_1
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Nov 29 20:55:14 2013 Jérémy MATHON
** Last update Fri Nov 29 21:17:00 2013 Jérémy MATHON
*/

#include <stdio.h>
#include <stdarg.h>

int		my_archive(char *format, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, format);
  i = 0;
  while (format[i] != 0)
    {
    }
  va_end(ap);
}

int	main(int ac, char **av)
{
  my_archive(av);
}
