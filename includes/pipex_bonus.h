/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:57:16 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/12 16:24:56 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define READ 0
# define WRITE 1
# define ARG_MAX 4096

typedef struct t_pipex
{
	int		infile;
	char	*cmd[ARG_MAX];
	int		outfile;
	char	**envp;
	int		argc;
	int		total_args;
	char	*delimiter;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
int		child_process(t_pipex *pipex, int fd[], int in_fd, int i);
void	execute_command(char *cmd, char **envp);
int		save_pipex(t_pipex	*pipex, char	**argv, char **envp, int argc);
void	free_command(char **args, char *cmd_path);

#endif