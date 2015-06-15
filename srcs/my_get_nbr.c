/*
** my_get_nbr.c for get_next_line in /home/danilo_d/rendu/MUL_2014_fdf
**
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
**
** Started on  Wed Dec  3 11:04:17 2014 Danilov Dimitri
** Last update Mon Jun 15 22:37:59 2015 danilov dimitri
*/

#include <string.h>

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}

int	is_neg(char *str)
{
  int	i;
  int	counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	counter = counter + 1;
      i = i + 1;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}
int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  return (0);
}

int	my_getnbr(char *str, int *i)
{
  int	nbr;

  if (*i > my_strlen(str))
    return (-1);
  nbr = 0;
  if (!str)
    return (0);
  while (is_num(str[*i]) == 1)
    {
      nbr = ((nbr * 10) + (str[*i] - 48));
      *i = *i + 1;
    }
  return (nbr);
}
