/*
** client.c for client in /home/clemen_j/Work/PSU/PSU_2015_minitalk/src
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb  1 18:47:44 2016 Clémenceau Cedric
** Last update Sun Feb 21 20:26:00 2016 Clémenceau Cedric
*/

#include <struct.h>

void	getusr1(int sig)
{
  return ;
}

int		count_bit(int pid, char c)
{
  int		i;
  unsigned char	bit;

  i = 0;
  bit = c;
  while (i < 8)
    {
      if ((bit >> i) % 2 == 0)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      usleep(1000);
      i++;
    }
  return (0);
}

void		send_pid(int pid)
{
  int		i;
  pid_t		my_pid;

  i = 0;
  my_pid = getpid();
  while (i < 32)
    {
      if (((my_pid >> i) % 2) == 0)
      	kill(pid, SIGUSR1);
      else
      	kill(pid, SIGUSR2);
      usleep(10000);
      i++;
    }
}

int		main(int ac, char **av, char **ae)
{
  int		i;
  int		pid;

  i = 0;
  if (ae == NULL)
    return (-1);
  if (ac != 3)
    return (-1);
  if ((pid = my_getnbr(av[1])) < 1)
    return (-1);
  send_pid(pid);
  signal(SIGUSR1, getusr1);
  while (av[2][i])
    count_bit(pid, av[2][i++]);
  count_bit(pid, 4);
}
