/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:56:34 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/13 12:39:16 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_redirects(int in_fd, int pipe_fd[], int i, t_pipex *pipex)
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (i < pipex->total_args - 1)
	{
		if (dup2(pipe_fd[WRITE], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	}
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
	close(in_fd);
	execute_command(pipex->cmd[i], pipex->envp);
	return (1);
}

int	read_pipex(t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;
	int		in_fd;
	int		i;

	i = -1;
	in_fd = pipex->infile;
	while (++i < pipex->total_args)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			return (perror("Pipe or Fork falló\n"), EXIT_FAILURE);
		if (pid == 0)
			return (ft_redirects(in_fd, fd, i, pipex));
		close(fd[WRITE]);
		if (in_fd != pipex->infile)
			close(in_fd);
		in_fd = fd[READ];
	}
	while (i-- > 0)
		waitpid(pid, NULL, 0);
	close(pipex->infile);
	close(pipex->outfile);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (!save_pipex(&pipex, argv, envp, argc))
		return (close(pipex.infile), close(pipex.outfile), 1);
	if (!read_pipex(&pipex))
		return (close(pipex.infile), close(pipex.outfile), 1);
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}
