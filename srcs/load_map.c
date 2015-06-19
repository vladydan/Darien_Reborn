/*
** load_map.c for load_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 20:58:23 2015 danilov dimitri
** Last update Fri Jun 19 16:15:15 2015 danilov dimitri
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

  while ((str = get_next_line(fd)) && str[0] != 0)
    {
      nbr = atoi(str);
      if (nbr == DARIEN)
	{
	  if ((str = get_next_line(fd)) != NULL)
	    game->darien.darien.charset.sprite = IMG_Load(str);
	  game->darien.darien.charset.sprite = SDL_DisplayFormat(game->darien.darien.charset.sprite);
	  SDL_SetColorKey(game->darien.darien.charset.sprite, SDL_SRCCOLORKEY, SDL_MapRGB
			  (game->darien.darien.charset.sprite->format, 0, 255, 0));
	  game->darien.darien.charset.nbx = 4;
	  game->darien.darien.charset.nby = 2;
	  game->darien.darien.charset.w = game->darien.darien.charset.sprite->w / 4;
	  game->darien.darien.charset.h = game->darien.darien.charset.sprite->h / 2;
	}
    }
}

void	SetAnim(t_anim *A, int framedepart, int nbframes, int delay)
{
  A->frame_start = framedepart;
  A->nbframes = nbframes;
  A->delay = delay;
}

int	initialise_sprite(t_entity *entity, int first)
{
  entity->sprite.pos.x = 0;
  entity->sprite.pos.y = -30;
  entity->sprite.sprite = &entity->charset;
  SetAnim(&entity->sprite.anim, first, 1, 1);
  entity->sprite.sens = SENS_UP;
  entity->sprite.status = STAT_STOP;
  return (0);
}

int	load_map(t_game *game)
{
  int	fd;

  fd = open("saves/map", O_RDONLY);
  load_texture(fd, game);
  load_sprites(fd, game);
  initialise_sprite(&game->darien.darien, 4);
  str_to_tab(game, fd);
  play(game);
  return (0);
}
