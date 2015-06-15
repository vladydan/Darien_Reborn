/*
** xmalloc.c for xmalloc in /home/danilo_d/rendu/MUL_2014_fdf/lib/my
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Sat Dec  6 20:01:09 2014 Danilov Dimitri
** Last update Mon Jun 15 15:59:39 2015 danilov dimitri
*/

#include <stdlib.h>
#include <stdio.h>

void	*xmalloc(int nbr)
{
  void	*ret;

  ret = malloc(nbr);
  if (ret == NULL)
    {
      printf("Malloc failed\n");
      exit(1);
    }
  return (ret);
}
