/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:57:16 by jaimesan          #+#    #+#             */
/*   Updated: 2024/11/12 12:52:44 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define READ 0
# define WRITE 1

typedef struct t_pipex
{
	int		infile;
	char	*cmd1;
	char	*cmd2;
	int		outfile;
	char	**envp;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
int		first_child(t_pipex *pipex, int fd[]);
int		second_child(t_pipex *pipex, int fd[]);
void	execute_command(char *cmd, char **envp);
int		save_pipex(t_pipex	*pipex, char	**argv, char **envp);
void	free_command(char **args, char *cmd_path);

#endif