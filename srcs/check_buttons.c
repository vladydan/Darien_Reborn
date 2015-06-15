/*
** check_bouttons.c for check_bouttons in /home/danilo_d/Darien_Reborn
**
** Made by danilov dimitri
** Login   <danilo_d@epitech.eu>
**
** Started on  Mon Jun 15 16:04:56 2015 danilov dimitri
** Last update Mon Jun 15 16:33:12 2015 danilov dimitri
*/

int	check_button(int x1, int x2, int y1, int y2, int x, int y)
{
  if (x1 < x && x2 > x && y1 < y && y2 > y)
    return (1);
  return (0);
}
