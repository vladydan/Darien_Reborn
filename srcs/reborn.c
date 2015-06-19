/*
** reborn.c for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:39:02 2015 danilov dimitri
** Last update Fri Jun 19 18:42:29 2015 danilov dimitri
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
  if (entity->sprite.pos.y > 52)
    {
      game->map.map[entity->tpos.x][entity->tpos.y] = 0;
      entity->sprite.pos.y = 0;
      game->map.map[++entity->tpos.x][entity->tpos.y] = 2;
    }
  if (entity->sprite.pos.y < -52)
    {
      game->map.map[entity->tpos.x][entity->tpos.y] = 0;
      entity->sprite.pos.y = 0;
      game->map.map[--entity->tpos.x][entity->tpos.y] = 2;
    }
  return (0);
}

int		gere_key(t_game *game, t_sprite *SP, Uint8 *keys)
{
  int		j;
  int		control[2] = {SDLK_LEFT, SDLK_RIGHT};
  Sint16	vec[2][2] = {{-1,0},{1,0}};
  Sint16	speed = 2;
  int		speedanim = 100;
  int		move;

  j = -1;
  move = 0;
  while (++j < 2)
    {
      if (keys[control[j]])
	{
	  move = 1;
	  if (SP->status == STAT_STOP || SP->sens != j)
	    SetAnim(&SP->anim,0 + SP->sprite->nbx * j, 3 ,speedanim);
	  SP->sens = j;
	  SP->pos.x += speed*vec[j][0];
	  SP->pos.y += speed*vec[j][1];
	  SP->status = STAT_WALK;
	}
    }
  if (SP->status == STAT_WALK && !move)
    {
      SetAnim(&SP->anim, 4, 1, 1);
      SP->status = STAT_STOP;
    }
  case_overflow(game, &game->darien.darien);
  return (0);
}

int		play(t_game *game)
{
  Uint8		*keys;
  int		key;
  char		finish;
  Uint32	timer, elapsed;

  finish = 1;
  music(game, "sprites/demacia.mp3");
  while (finish)
    {
      timer = SDL_GetTicks();
      SDL_FillRect(game->sdl.screen, NULL, 0);
      SDL_PumpEvents();
      keys = SDL_GetKeyState(&key);
      if (physics(&game->darien.darien, game) == 0)
	gere_key(game, &game->darien.darien.sprite, keys);
      aff_screen(game);
      elapsed = SDL_GetTicks() - timer;
      if (elapsed < 20)
	SDL_Delay(20 - elapsed);
      if (keys[SDLK_ESCAPE])
	finish = 0;
    }
  exit(0);
}
