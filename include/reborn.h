/*
** reborn.h for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 14:59:05 2015 danilov dimitri
** Last update Mon Jun 15 23:52:05 2015 danilov dimitri
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
# define HEIGH		844
# define BUFFER_SIZE	2048

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
  t_darien		*darien;
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

#endif /* !REBORN_H_ */
