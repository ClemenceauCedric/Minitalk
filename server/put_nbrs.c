/*
** put_nbrs.c for minitalk in /home/clemen_j/Work/PSU/PSU_2015_minitalk/src_server
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Feb 10 01:15:41 2016 Clémenceau Cedric
** Last update Thu Feb 18 14:38:01 2016 Clémenceau Cedric
*/

#include <struct.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

char	*my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (10);
    }
  else if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      i += my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
      return (i + 1);
    }
  else if (nb >= 10)
    i += my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (i);
}
