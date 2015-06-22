/*
** collision.c for collision in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Fri Jun 19 18:04:55 2015 danilov dimitri
** Last update Mon Jun 22 17:15:10 2015 danilov dimitri
*/

#include	"reborn.h"
#include	<assert.h>

SDL_Rect	find_pos_screen(int x, int y)
{
  SDL_Rect	pos;

  pos.x = y * SPR_Y;
  pos.y = x * SPR_X;
  return (pos);
}

int		find_ground(t_game *game, t_entity *entity)
{
  int		i;

  i = entity->tpos.x;
  while (game->map.map[i + 1][entity->tpos.y] == 0 && i < game->map.pos.x)
    i++;
  return (i);
}

int		surface_collide(SDL_Surface *as , int ax , int ay,
				SDL_Surface *bs , int bx , int by)
{
  int		ax1 = ax + ((as->w - 1) / 4);
  int		ay1 = ay + ((as->h - 1) / 2);
  int		bx1 = bx + bs->w - 1;
  int		by1 = by + bs->h - 1;
  int		x;
  int		y;

  if ((bx1 < ax) || (ax1 < bx))
    return 0;
  if ((by1 < ay) || (ay1 < by))
    return 0;
  int inter_x0 = SDL_COLLIDE_MAX(ax,bx);
  int inter_x1 = SDL_COLLIDE_MIN(ax1,bx1);
  int inter_y0 = SDL_COLLIDE_MAX(ay,by);
  int inter_y1 = SDL_COLLIDE_MIN(ay1,by1);
  for(y = inter_y0 ; y <= inter_y1 ; y++)
    {
      for(x = inter_x0 ; x <= inter_x1 ; x++)
	{
	  if (getpixel(as , x - ax , y - ay) != GREEN)
	    return (1);
	}
    }
  return (0);
}

int		physics(t_entity *entity, t_game *game)
{
  int		x;
  SDL_Surface	*collide;
  SDL_Rect	pos;
  SDL_Rect	pos2;
  int		ret;

  x = find_ground(game, entity);
  collide = game->map.sprites[1];
  pos2 = find_pos_screen(x + 1, entity->tpos.y);
  pos = find_pos_screen(entity->tpos.x, entity->tpos.y);
  pos.y += entity->sprite.pos.y;
  ret = surface_collide(entity->sprite.sprite->sprite, pos.x,
			pos.y, collide, pos2.x, pos2.y);
  if (ret == 0)
    {
      entity->sprite.pos.y += 5;
      case_overflow(game, entity);
      return (1);
    }
  return (0);
}
