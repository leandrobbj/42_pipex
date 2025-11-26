/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/25 23:59:54 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd_pp[2];
	pid_t	pid[2];

	check_args(ac, av, env);
	if (pipe(fd_pp) == -1)
		exit_error(NULL, "pipe", -1);
	pid[0] = fork();
	if (pid[0] == -1)
		exit_error(NULL, "pid0", -1);
	else if (!pid[0])
		read_process(av, env, fd_pp);
	pid[1] = fork();
	if (pid[1] == -1)
		exit_error(NULL, "pid1", -1);
	else if (!pid[1])
		write_process(av, env, fd_pp);
	exit_parent(fd_pp, pid);
}

void	exit_error(char **array, char *str, int err)
{
	if (array)
		ft_freecharray(array);
	if (err == -1)
		perror(str);
	else if (err > 0)
		ft_putendl_fd(str, STDERR_FILENO);
	if (err == 127)
		exit(127);
	exit(1);
}

void	exit_parent(int *fd_pp, pid_t *pid)
{
	int	ext;

	close(fd_pp[0]);
	close(fd_pp[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &ext, 0);
	if (WIFEXITED(ext))
		exit(WEXITSTATUS(ext));
	exit(0);
}
