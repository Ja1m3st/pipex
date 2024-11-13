/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:37:45 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/13 13:07:45 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(char **args, char *cmd_path)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	if (cmd_path)
		free(cmd_path);
}

int	save_pipex(t_pipex	*pipex, char	**argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (perror("Error: no se puede abrir infile\n"), 0);
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		return (perror("Error: no se puede abrir outfile\n"), 0);
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->envp = envp;
	return (1);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (!args)
		return (perror("Error\n"), exit(EXIT_FAILURE));
	cmd_path = ft_strjoin("/usr/bin/", args[0]);
	if (!cmd_path)
		return (free_command(args, NULL), exit(EXIT_FAILURE));
	execve(&cmd_path[0], args, envp);
	perror("Error: execve falló");
	free_command(args, cmd_path);
	exit(EXIT_FAILURE);
}

int	first_child(t_pipex *pipex, int fd[])
{
	if (dup2(pipex->infile, STDIN_FILENO) == -1
		|| dup2(fd[WRITE], STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fd[READ]);
	close(fd[WRITE]);
	close(pipex->infile);
	close(pipex->outfile);
	execute_command(pipex->cmd1, pipex->envp);
	return (1);
}

int	second_child(t_pipex *pipex, int fd[])
{
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1
		|| dup2(fd[READ], STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fd[READ]);
	close(fd[WRITE]);
	close(pipex->infile);
	close(pipex->outfile);
	execute_command(pipex->cmd2, pipex->envp);
	return (1);
}
