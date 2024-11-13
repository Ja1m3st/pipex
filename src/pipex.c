/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:56:34 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/13 13:07:40 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_pipex(t_pipex	*pipex)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return (perror("Pipe creation failed\n"), 0);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Error first fork\n"), close(fd[0]), close(fd[1]), 0);
	if (pid1 == 0)
		first_child(pipex, fd);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Error second fork\n"), close(fd[0]), close(fd[1]), 0);
	if (pid2 == 0)
		second_child(pipex, fd);
	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Error\n"), 0);
	if (!save_pipex(&pipex, argv, envp))
		return (close(pipex.infile), close(pipex.outfile), 1);
	if (!read_pipex(&pipex))
		return (close(pipex.infile), close(pipex.outfile), 1);
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}
