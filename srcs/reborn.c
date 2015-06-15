/*
** reborn.c for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 22:39:02 2015 danilov dimitri
** Last update Mon Jun 15 23:42:32 2015 danilov dimitri
*/

#include "reborn.h"

int		play(t_game *game)
{
  SDL_Event	event;
  char		finish;

  finish = 1;
  while (finish)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	finish = 0;
      aff_screen(game);
    }
  exit(0);
}
