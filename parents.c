/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parents.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:05:50 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/12 12:10:30 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(char **command_paths, char **command_args)
{
	int	i;

	i = 0;
	while (command_paths[i] != NULL)
	{
		free(command_paths[i]);
		i++;
	}
	free(command_paths);
	i = 0;
	while (command_args[i] != NULL)
	{
		free(command_args[i]);
		i++;
	}
	free(command_args);
}

int	ft_file_check(int file, char **argv)
{
	if (file == -1)
	{
		ft_printf("No such file or directory: %s\n", argv[1]);
		return (-1);
	}
	return (1);
}

int	ft_check_command(char *command, char **command_paths, char **command_args)
{
	if (command == NULL)
	{
		ft_free_all(command_paths, command_args);
		return (-1);
	}
	return (1);
}

int	child(char **argv, char **envp, int *fd)
{
	int		file;
	char	*command;
	char	**command_paths;
	char	**command_args;

	close(fd[0]);
	file = open(argv[1], O_RDONLY);
	if (ft_file_check(file, argv) == -1)
		return (-1);
	command_paths = paths_retrieve(envp);
	command_args = args_retrieve(argv[2]);
	command = command_retrieve(command_args[0], command_paths);
	if (ft_check_command(command, command_paths, command_args) == -1)
		return (-2);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(file);
	if (execve(command, command_args, envp) == -1)
	{
		ft_free_all(command_paths, command_args);
		ft_printf("Could not execute\n");
		return (2);
	}
	return (0);
}

int	father( int file_2, char **argv, char **envp, int *fd)
{
	char	*command;
	char	**command_paths;
	char	**command_args;

	close(fd[1]);
	command_paths = paths_retrieve(envp);
	command_args = args_retrieve(argv[3]);
	command = command_retrieve(command_args[0], command_paths);
	if (ft_check_command(command, command_paths, command_args) == -1)
		return (-2);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_2, STDOUT_FILENO);
	close(fd[0]);
	close(file_2);
	if (execve(command, command_args, envp) == -1)
	{
		ft_printf("Could not execute\n");
		ft_free_all(command_paths, command_args);
		return (3);
	}
	return (0);
}
