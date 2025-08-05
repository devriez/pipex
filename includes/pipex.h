/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:21:01 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/05 13:01:12 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <stdio.h>
# include <fcntl.h> // write
# include <unistd.h> // perror, fork, pipe, dup2, open, access, close, execv
# include <stdlib.h> // exit.......malloc, free
# include <sys/wait.h> //waitpid

//error_and_free
void	sys_error(char *message);
void	log_error(char *message);
void	free_arr(char **arr);

//utils
void	execute(char *cmd_from_input, char **envv);

#endif