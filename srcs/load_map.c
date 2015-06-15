/*
** load_map.c for load_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 20:58:23 2015 danilov dimitri
** Last update Mon Jun 15 23:52:19 2015 danilov dimitri
*/

#include "reborn.h"

void	load_texture(int fd, t_game *game)
{
  char	*str;
  int	nbr;

  while ((str = get_next_line(fd)) && str[0] != 0)
    {
      nbr = atoi(str);
      if (&str[2] != NULL)
	game->map.sprites[nbr] = IMG_Load(&str[2]);
    }
}

int	load_map(t_game *game)
{
  int	fd;

  fd = open("saves/map", O_RDONLY);
  load_texture(fd, game);
  str_to_tab(game, fd);
  play(game);
  return (0);
}
