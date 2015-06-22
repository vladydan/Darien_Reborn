/*
** aff_map.c for aff_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:38:37 2015 danilov dimitri
** Last update Mon Jun 22 17:15:45 2015 danilov dimitri
*/

#include	"reborn.h"

void CharsetGetSrcRect(t_charset *C, SDL_Rect *src, int frame)
{
  src->w = (Uint16)C->w;
  src->h = (Uint16)C->h;
  src->x = (Sint16)((frame % C->nbx) * C->w);
  src->y = (Sint16)((frame / C->nbx) * C->h);
}

int AnimGetFrame(t_anim *A)
{
  return (A->frame_start + (SDL_GetTicks() / A->delay) % A->nbframes);
}


int		aff_sprite(t_game *game, SDL_Rect pos, t_sprite *S)
{
  SDL_Rect	tmp;
  SDL_Rect	src;
  int		frame = AnimGetFrame(&S->anim);

  tmp.x = S->pos.x + pos.x;
  tmp.y = S->pos.y + pos.y;
  CharsetGetSrcRect(S->sprite ,&src, frame);
  SDL_BlitSurface(S->sprite->sprite, &src, game->sdl.screen, &tmp);
  return (0);
}

int		aff_background(t_game *game, SDL_Rect pos)
{
  Uint32	color;
  int		i = -1;
  int		j;

  while (++i != 52)
    {
      j = -1;
      while (++j != 100)
	{
	  color = getpixel(game->map.sprites[0], pos.x + j, pos.y + i);
	  putpixel(game->sdl.screen, pos.x + j, pos.y + i, color);
	}
    }
  return (0);
}

int		aff_screen(t_game *game)
{
  SDL_Rect	pos;
  int		i = -1;
  int		j = -1;

  SDL_FillRect(game->sdl.screen, NULL,
	       SDL_MapRGB(game->sdl.screen->format, 255, 255, 255));
  pos.y = 0;
  pos.x = 0;
  SDL_BlitSurface(game->map.sprites[0], NULL, game->sdl.screen,
		  &pos);
  while (++i != 16)
    {
      pos.x = 0;
      j = -1;
      while (++j != 15)
	{
	  if (game->map.map[i][j] == 1)
	    SDL_BlitSurface(game->map.sprites[1], NULL, game->sdl.screen,
			    &pos);
	  if (game->map.map[i][j] == 2)
	    aff_sprite(game, pos, &game->darien.darien.sprite);
	  pos.x += 100;
	}
      pos.y += 52;
    }
  SDL_Flip(game->sdl.screen);
  return (0);
}
