/*
** aff_map.c for aff_map in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:38:37 2015 danilov dimitri
** Last update Tue Jun 16 00:22:57 2015 danilov dimitri
*/

#include	"reborn.h"
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int bpp = surface->format->BytesPerPixel;
  /* Here p is the address to the pixel we want to set */
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

  switch(bpp) {
  case 1:
    *p = pixel;
    break;

  case 2:
    *(Uint16 *)p = pixel;
    break;

  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
      p[0] = (pixel >> 16) & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = pixel & 0xff;
    } else {
      p[0] = pixel & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = (pixel >> 16) & 0xff;
    }
    break;

  case 4:
    *(Uint32 *)p = pixel;
    break;
  }
}

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
  int bpp = surface->format->BytesPerPixel;
  /* Here p is the address to the pixel we want to retrieve */
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

  switch(bpp) {
  case 1:
    return *p;
    break;

  case 2:
    return *(Uint16 *)p;
    break;

  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return p[0] << 16 | p[1] << 8 | p[2];
    else            return p[0] | p[1] << 8 | p[2] << 16;
    break;

  case 4:
    return *(Uint32 *)p;
    break;

  default:
    return 0;       /* shouldn't happen, but avoids warnings */
  }
}



int		aff_background(t_game *game, SDL_Rect pos)
{
  Uint32	color;
  int		i = -1;
  int		j;

  while (++i != 53)
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
      while (++j != 20)
	{
	  if (game->map.map[i][j] == 0)
	    aff_background(game, pos);
	  if (game->map.map[i][j] == 1)
	      SDL_BlitSurface(game->map.sprites[1], NULL, game->sdl.screen,
			      &pos);
	  pos.x += 100;
	}
      pos.y += 53;
    }
  SDL_Flip(game->sdl.screen);
  return (0);
}
