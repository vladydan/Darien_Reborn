/*
** main.c for main in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 15:16:30 2015 danilov dimitri
** Last update Wed Jun 17 15:37:47 2015 danilov dimitri
*/

#include "reborn.h"

int		which_button(SDL_Event event)
{
  int		x;
  int		y;

  x = event.button.x;
  y = event.button.y;
  if (check_button(106, 678, 71, 200, x, y) == 1)
    return (PLAY);
  if (check_button(606, 942, 342, 482, x, y) == 1)
    return (LOAD);
  if (check_button(1041, 1334, 638, 758, x, y) == 1)
    return (EXIT);
  return (-1);
}

int		menu(t_game *game)
{
  SDL_Surface	*menu;
  SDL_Rect	pos;
  SDL_Event	event;
  char		finish;
  int		button;
  FMOD_SOUND	*music;
  FMOD_CHANNELGROUP *canal;

  finish = 1;
  pos.x = 0;
  pos.y = 0;
  menu = IMG_Load("sprites/menu.jpeg");
  SDL_BlitSurface(menu, NULL, game->sdl.screen,
		  &pos);
  FMOD_System_CreateSound(game->sdl.system, "sprites/menu.mp3", FMOD_SOFTWARE |
			  FMOD_2D | FMOD_CREATESTREAM, 0, &music);
  FMOD_Sound_SetLoopCount(music, -1);
  FMOD_System_PlaySound(game->sdl.system, FMOD_CHANNEL_FREE, music, 0, NULL);
  SDL_Flip(game->sdl.screen);
  FMOD_System_GetMasterChannelGroup(game->sdl.system, &canal);
  while (finish)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	finish = 0;
      if (event.type == SDL_MOUSEBUTTONUP)
	button = which_button(event);
      if (button == PLAY)
	{
	  FMOD_ChannelGroup_Stop(canal);
	  load_map(game);
	}
      if (button == EXIT)
	exit(0);
    }
  return (0);
}

int		main(void)
{
  t_game	*game;

  game = xmalloc(sizeof(t_game));
  SDL_Init(SDL_INIT_VIDEO);
  FMOD_System_Create(&game->sdl.system);
  FMOD_System_Init(game->sdl.system, 2, FMOD_INIT_NORMAL, NULL);
  game->sdl.screen = SDL_SetVideoMode(LENGH, HEIGH, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  menu(game);
  return (EXIT_SUCCESS);
}
