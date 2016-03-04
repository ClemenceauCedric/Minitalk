/*
** server.c for minitalk_server in /home/clemen_j/Work/PSU/PSU_2015_minitalk
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb  1 18:51:07 2016 Clémenceau Cedric
** Last update Sat Feb 20 17:08:58 2016 Clémenceau Cedric
*/

#include <struct.h>

int		fill_pid(int sig)
{
  static int	pos_pid = 0;
  static int	pid_client = 0;

  if (pos_pid == 0)
    pid_client = 0;
  if (sig == SIGUSR1)
    pid_client |= (0 << pos_pid);
  else
    pid_client |= (1 << pos_pid);
  pos_pid++;
  if (pos_pid == 32)
    {
      pos_pid = 0;
      return (pid_client);
    }
  return (0);
}

void			getsigusr(int sig)
{
  static unsigned char	set_bit = 0;
  static int		pos = 0;
  static int		pid_client = 0;
  static int		count = 0;

  if (count != 32 && ((pid_client = fill_pid(sig)) >= 0))
    count++;
  else
    {
      if (sig == SIGUSR1)
        set_bit |= (0 << pos);
      else
        set_bit |= (1 << pos);
      pos++;
      if (pos == 8)
        {
	  if (set_bit == 4)
	    count = 0;
	  else
	    write(1, &set_bit, 1);
	  set_bit = 0;
          pos = 0;
	}
      kill(pid_client, SIGUSR1);
    }
}

int		main()
{
  pid_t		pid;

  pid = getpid();
  my_put_nbr(pid);
  write(1, "\n", 1);
  signal(SIGUSR1, getsigusr);
  signal(SIGUSR2, getsigusr);
  while (1);
  return (0);
}
