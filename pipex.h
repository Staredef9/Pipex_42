/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:06:08 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/12 12:04:14 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "./Libft/libft.h"

char	*command_retrieve(char *argv, char *envp[]);
char	**args_retrieve(char *argv);
char	**paths_retrieve(char **envp);
int		child(char **argv, char **envp, int *fd);
int		father(int file_2, char **argv, char **envp, int *fd);
#endif
