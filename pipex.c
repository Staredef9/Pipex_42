/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:05:59 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/12 12:03:26 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		id;
	int		file_2;

	if (argc != 5)
		return (0);
	file_2 = open(argv[4], O_CREAT | O_WRONLY, 0664);
	pipe(fd);
	if (fd[0] == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (4);
	if (id == 0)
	{
		child(argv, envp, fd);
	}
	else
	{
		waitpid(id, NULL, 0);
		father(file_2, argv, envp, fd);
	}
	return (0);
}

char	**args_retrieve(char *argv)
{
	char	**args_to_return;

	args_to_return = ft_split(argv, ' ');
	return (args_to_return);
}

char	**paths_retrieve(char **envp)
{
	char	**paths_to_return;

	while (*envp != NULL)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
		{
			paths_to_return = ft_split(*envp + 5, ':');
			break ;
		}
		envp++;
	}
	return (paths_to_return);
}

char	*command_retrieve(char *argv, char **command_paths)
{
	char	*path;
	char	*temp;

	while (*command_paths != NULL)
	{
		temp = ft_strjoin(command_paths[0], "/");
		path = ft_strjoin(temp, argv);
		if (access(path, X_OK) == 0)
		{
			free(temp);
			return (path);
		}
		else
		{
			free(path);
			free(temp);
			command_paths ++;
		}
	}
	ft_printf("Command not found\n");
	return (NULL);
}
