/*
** collision.c for collision in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Fri Jun 19 18:04:55 2015 danilov dimitri
** Last update Fri Jun 19 18:43:29 2015 danilov dimitri
*/

#include	"reborn.h"

int		physics(t_entity *entity, t_game *game)
{
  if (game->map.map[entity->tpos.x + 1][entity->tpos.y] != 1)
    {
      entity->sprite.pos.y += 5;
      case_overflow(game, entity);
      return (1);
    }
  return (0);
}
