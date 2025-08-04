/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devriez <devriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:21:01 by devriez           #+#    #+#             */
/*   Updated: 2025/08/04 23:27:33 by devriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <libft.h>
#include <stdio.h>
#include <fcntl.h> // write
#include <unistd.h> // perror, fork, pipe, dup2, open, access........... close, read,....execv.....unlink
#include <stdlib.h> // exit.......malloc, free

void	sys_error(char *message);
void	free_arr(char **arr);
void	execute(char *cmd_from_input, char **envv)

#endif