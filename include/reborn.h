/*
** reborn.h for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 14:59:05 2015 danilov dimitri
** Last update Wed Jun 17 16:01:57 2015 danilov dimitri
*/

#ifndef REBORN_H_
# define REBORN_H_

# include               <SDL/SDL.h>
# include               <SDL/SDL_ttf.h>
# include		<SDL/SDL_image.h>
# include		<fmodex/fmod.h>
# include		<stdlib.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>

# define PLAY		1
# define LOAD		2
# define EXIT		3
# define LENGH		1500
# define HEIGH		832
# define BUFFER_SIZE	2048
# define NUMBER_SPRITE	6
# define DARIEN		2

typedef struct		s_item
{
  int			item;
  struct s_item		*next;
  struct s_item		*back;
}			t_item;

typedef struct		s_entity
{
  int			life;
  int			strengh;
  int			agility;
  int			intellect;
  int			sprite_pos;
  SDL_Rect		tpos;
  SDL_Surface		*sprites[NUMBER_SPRITE];
  SDL_Rect		pos;
}			t_entity;

typedef struct		s_darien
{
  t_entity		darien;
  t_item		*list;
}			t_darien;

typedef struct		s_sdl
{
  SDL_Event		event;
  SDL_Surface		*screen;
  SDL_Surface		*menu;
  FMOD_SYSTEM		*system;
}			t_sdl;

typedef struct		s_map
{
  char			**map;
  SDL_Surface		*sprites[100];
}			t_map;

typedef struct		s_game
{
  t_sdl			sdl;
  t_darien		darien;
  t_map			map;
}			t_game;

void			*xmalloc(int);
int			check_button(int, int, int, int, int, int);
char			*get_next_line(int);
int			load_map(t_game *);
char			str_to_tab(t_game *, int);
int			my_getnbr(char *, int *);
int			aff_screen(t_game *);
int			play(t_game *);
Uint32			getpixel(SDL_Surface *, int, int);
void			putpixel(SDL_Surface *, int, int, Uint32);
FMOD_CHANNELGROUP	*music(t_game *game, char *music_title);

#endif /* !REBORN_H_ */
