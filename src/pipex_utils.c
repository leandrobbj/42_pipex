/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/25 23:57:04 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int ac, char **av, char **env)
{
	if (ac != 5)
		exit_error(NULL, "argc", 1);
	if (!av[2][0] || !av[3][0])
		exit_error(NULL, "empty", 2);
	if (!ft_getenv("PATH", env))
		exit_error(NULL, "env", 3);
}

void	read_process(char **av, char **env, int *fd_pp)
{
	int	input;

	close(fd_pp[0]);
	input = open(av[1], O_RDONLY);
	if (input == -1)
		exit_error(NULL, "file", -1);
	dup2(input, STDIN_FILENO);
	dup2(fd_pp[1], STDOUT_FILENO);
	close(fd_pp[1]);
	close(input);
	execute_command(av[2], env);
}

void	write_process(char **av, char **env, int *fd_pp)
{
	int	output;

	close(fd_pp[1]);
	output = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
		exit_error(NULL, "file", -1);
	dup2(fd_pp[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(fd_pp[0]);
	close(output);
	execute_command(av[3], env);
}

void	execute_command(char *av, char **env)
{
	char	**cmd;
	char	*path;
	char	**paths;

	cmd = ft_split(av, ' ');
	path = ft_getenv("PATH", env);
	paths = ft_split(path, ':');
	if (!paths)
		exit_error(cmd, "malloc", 4);
	getcmd_freepaths(paths, cmd, &path);
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		exit_error(cmd, "execve", -1);
	}
}

void	getcmd_freepaths(char **paths, char **cmd, char **path)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		ft_strjoinfree(paths + i, "/");
		ft_strjoinfree(paths + i, cmd[0]);
		if (!access(paths[i], F_OK | X_OK))
		{
			*path = ft_strdup(paths[i]);
			ft_freecharray(paths);
			return ;
		}
		i++;
	}
	ft_freecharray(paths);
	exit_error(cmd, "command not found", 127);
}
