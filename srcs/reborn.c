/*
** reborn.c for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:39:02 2015 danilov dimitri
** Last update Tue Jun 16 18:47:47 2015 danilov dimitri
*/

#include "reborn.h"

int		case_overflow(t_game *game, t_entity *entity)
{
  if (entity->pos.x > 100)
    {
      game->map.map[entity->tpos.x][entity->tpos.y] = 0;
      entity->pos.x = 0;
      game->map.map[entity->tpos.x][++entity->tpos.y] = 2;
    }
  if (entity->pos.x < -100)
    {
      game->map.map[entity->tpos.x][entity->tpos.y] = 0;
      entity->pos.x = 0;
      game->map.map[entity->tpos.x][--entity->tpos.y] = 2;
    }
  return (0);
}

int		gere_key(t_game *game, SDL_Event event)
{
  if (event.key.keysym.sym == SDLK_RIGHT)
    {
      game->darien.darien.sprite_pos = 1;
      game->darien.darien.pos.x += 10;
    }
  if (event.key.keysym.sym == SDLK_LEFT)
    {
      game->darien.darien.sprite_pos = 0;
      game->darien.darien.pos.x -= 10;
    }
  case_overflow(game, &game->darien.darien);
  return (0);
}

int		play(t_game *game)
{
  SDL_Event	event;
  char		finish;

  finish = 1;
  while (finish)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_KEYDOWN)
	gere_key(game, event);
      if (event.type == SDL_QUIT)
	finish = 0;
      aff_screen(game);
    }
  exit(0);
}
