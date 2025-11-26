/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:09:32 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/26 00:04:35 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "src/libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

void	check_args(int ac, char **av, char **env);
void	read_process(char **av, char **env, int *fd_pp);
void	write_process(char **av, char **env, int *fd_pp);
void	execute_command(char *av, char **env);
void	getcmd_freepaths(char **paths, char **cmd, char **path);
void	exit_error(char **array, char *str, int err);
void	exit_parent(int *fd, pid_t	*pid);

#endif