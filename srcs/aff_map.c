/*
** aff_map.c for aff_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:38:37 2015 danilov dimitri
** Last update Tue Jun 16 18:43:59 2015 danilov dimitri
*/

#include	"reborn.h"

int		aff_sprite(t_game *game, SDL_Rect pos)
{
  SDL_Rect	tmp;

  tmp.x = pos.x + game->darien.darien.pos.x;
  tmp.y = pos.y + game->darien.darien.pos.y - 10;
  SDL_SetColorKey(game->darien.darien.sprites[game->darien.darien.sprite_pos],
		  SDL_SRCCOLORKEY, SDL_MapRGB(game->darien.darien.sprites
					      [game->darien.darien.sprite_pos]->format, 0, 255, 0));
  SDL_BlitSurface(game->darien.darien.sprites[game->darien.darien.sprite_pos], NULL, game->sdl.screen,
		  &tmp);
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
  while (++i != 16)
    {
      pos.x = 0;
      j = -1;
      while (++j != 15)
	{
	  if (game->map.map[i][j] == 1)
	    SDL_BlitSurface(game->map.sprites[1], NULL, game->sdl.screen,
			    &pos);
	  else if ((game->map.map[i][j] == 0 || game->map.map[i][j] == 2))
	    aff_background(game, pos);
	  if (game->map.map[i][j] == 2)
	    aff_sprite(game, pos);
	  pos.x += 100;
	}
      pos.y += 52;
    }
  SDL_Flip(game->sdl.screen);
  return (0);
}
