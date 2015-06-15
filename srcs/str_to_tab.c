/*
** str_to_tab.c for str_to_tab in /home/danilo_d/rendu/MUL_2014_fdf
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Sun Dec  7 11:45:34 2014 Danilov Dimitri
** Last update Mon Jun 15 23:51:46 2015 danilov dimitri
*/

#include <stdlib.h>
#include "reborn.h"

int		nbr_int(char *str)
{
  int		nbr_int;
  int		j;

  j = 0;
  nbr_int = 0;
  while (str[j] != '\0')
    {
      if (str[j] == ' ')
	{
	  while (str[j] == ' ')
	    j++;
	  nbr_int++;
	}
      j = j + 1;
    }
  return (nbr_int + 1);
}

char		str_to_tab(t_game *game, int fd)
{
  int		i;
  char		*line;
  int		a;
  int		j;
  int		pos;

  i = 0;
  game->map.map = xmalloc(sizeof(char *) * 20);
  while ((line = get_next_line(fd)))
    {
      j = -1;
      a = nbr_int(line);
      game->map.map[i] = xmalloc(a + 1);
      pos = 0;
      while (++j < a)
	{
	  game->map.map[i][j] = my_getnbr(line, &pos);
	  pos++;
	}
      i++;
    }
  return (0);
}
