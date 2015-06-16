/*
** load_map.c for load_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 20:58:23 2015 danilov dimitri
** Last update Tue Jun 16 15:57:06 2015 danilov dimitri
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

void	load_sprites(int fd, t_game *game)
{
  char  *str;
  int   nbr;
  int	i;

  i = -1;
  while ((str = get_next_line(fd)) && str[0] != 0)
    {
      nbr = atoi(str);
      if (nbr == DARIEN)
	{
	  while (++i != NUMBER_SPRITE && (str = get_next_line(fd)) != NULL)
	    game->darien.darien.sprites[i] = IMG_Load(str);
	  game->darien.darien.pos.x = 0;
	  game->darien.darien.pos.y = 0;
	  game->darien.darien.sprite_pos = NUMBER_SPRITE - 1;
	}
    }
}

int	load_map(t_game *game)
{
  int	fd;

  fd = open("saves/map", O_RDONLY);
  load_texture(fd, game);
  load_sprites(fd, game);
  str_to_tab(game, fd);
  play(game);
  return (0);
}
