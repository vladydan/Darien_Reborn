/*
** music.c for music in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Wed Jun 17 14:12:44 2015 danilov dimitri
** Last update Wed Jun 17 14:24:35 2015 danilov dimitri
*/

#include "reborn.h"

FMOD_CHANNELGROUP	*music(t_game *game, char *music_title)
{
  FMOD_SOUND		*music;
  FMOD_CHANNELGROUP	*canal;

  FMOD_System_CreateSound(game->sdl.system, music_title, FMOD_SOFTWARE |
			  FMOD_2D | FMOD_CREATESTREAM, 0, &music);
  FMOD_Sound_SetLoopCount(music, -1);
  FMOD_System_PlaySound(game->sdl.system, FMOD_CHANNEL_FREE, music, 0, NULL);
  FMOD_System_GetMasterChannelGroup(game->sdl.system, &canal);
  return (canal);
}
