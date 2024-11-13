/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:37:45 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/13 13:07:55 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_command(char **args, char *cmd_path)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i] != NULL)
			free(args[i++]);
		free(args);
	}
	if (cmd_path)
		free(cmd_path);
}

int	put_here_doc(t_pipex *pipex, char **argv, char **envp, int argc)
{
	char	*line;
	int		temp_fd;

	pipex->delimiter = argv[2];
	pipex->infile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile < 0)
		return (perror("Error: no se puede abrir infile"), 0);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(line, pipex->delimiter, ft_strlen(pipex->delimiter)))
			break ;
		write(pipex->infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(pipex->infile);
	pipex->infile = open(argv[2], O_RDONLY);
	if (pipex->infile < 0)
		return (perror("Error al abrir here_doc file"), 0);
	return (3);
}

int	save_pipex(t_pipex *pipex, char **argv, char **envp, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	pipex->argc = argc - 1;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		j = put_here_doc(pipex, argv, envp, argc);
	else
	{
		if (access(argv[1], F_OK) == -1)
			return (perror("Error: no se puede encontrar infile"), 0);
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			return (perror("Error: no se puede abrir infile"), 0);
	}
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		return (perror("Error: no se puede abrir outfile"), 0);
	while (j < argc - 1)
		pipex->cmd[i++] = argv[j++];
	pipex->envp = envp;
	pipex->total_args = i;
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

int	child_process(t_pipex *pipex, int fd[], int in_fd, int i)
{
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(fd[WRITE], STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fd[READ]);
	close(fd[WRITE]);
	close(in_fd);
	close(pipex->outfile);
	execute_command(pipex->cmd[i], pipex->envp);
	return (1);
}
