/*
** reborn.h for reborn in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 14:59:05 2015 danilov dimitri
** Last update Fri Jun 19 18:18:22 2015 danilov dimitri
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
# define SENS_UP	2
# define SENS_RIGHT	1500
# define SENS_DOWN	2
# define SENS_LEFT	3
# define STAT_STOP	8
# define STAT_WALK	1500
# define GREEN		0x00FF00

typedef struct		s_anim
{
  int			frame_start;
  int			nbframes;
  int			delay;
}			t_anim;

typedef	struct		s_charset
{
  SDL_Surface		*sprite;
  int			nbx;
  int			nby;
  int			w;
  int			h;
}			t_charset;

typedef struct		s_sprite
{
  t_charset		*sprite;
  t_anim		anim;
  SDL_Rect		pos;
  int			sens;
  int			status;
}			t_sprite;

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
  t_charset		charset;
  t_sprite		sprite;
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
void			SetAnim(t_anim *A, int framedepart, int nbframes, int delay);
int			physics(t_entity *entity, t_game *game);
int			case_overflow(t_game *game, t_entity *entity);

#endif /* !REBORN_H_ */
