/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:50:06 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/05 12:53:47 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_from_env(char **envv)
{
	int	i;

	i = 0;
	while (envv[i])
	{
		if (ft_strnstr(envv[i], "PATH", 4) == envv[i])
			return (envv[i] + ft_strlen("PATH="));
		i ++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd_name, char **envv)
{
	char	**paths;
	char	*full_path;
	char	*path_with_slash;
	int		i;

	i = 0;
	paths = ft_split(get_path_from_env(envv), ':');
	while (paths[i])
	{
		path_with_slash = ft_strjoin(paths[i], "/");
		if (!path_with_slash)
			return (NULL);
		full_path = ft_strjoin(path_with_slash, cmd_name);
		free(path_with_slash);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
		{
			free_arr(paths);
			return (full_path);
		}
		free(full_path);
		i ++;
	}
	return (free_arr(paths), NULL);
}

void	execute(char *cmd_from_input, char **envv)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(cmd_from_input, ' ');
	cmd_path = get_cmd_path(cmd[0], envv);
	if (!cmd_path)
	{
		free_arr(cmd);
		log_error("command is not executable");
	}
	if (execve(cmd_path, cmd, envv) == -1)
	{
		free(cmd_path);
		free_arr(cmd);
		sys_error("Error with execve");
	}
}
