/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:20:57 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/05 12:53:36 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envv, int *pipe_fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		sys_error("Error with open file in child process");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		sys_error("Error with duplicate pipe 'in' into STDOUT in child proc");
	if (dup2(file_in, STDIN_FILENO) == -1)
		sys_error("Error with duplicate file_in into STDIN in child proccess");
	close(pipe_fd[0]);
	execute(argv[2], envv);
}

void	parent_process(char **argv, char **envv, int *pipe_fd)
{
	int	file_out;

	file_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_out == -1)
		sys_error("Error with open file in parent process");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		sys_error("Error with duplicate pipe 'in' into STDIN in parent proc");
	if (dup2(file_out, STDOUT_FILENO) == -1)
		sys_error("Error with duplicate file_out into STDOUT in child proc");
	close(pipe_fd[1]);
	execute(argv[3], envv);
}

int	main(int argc, char **argv, char **envv)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		log_error("Number of arguments is not equal 4");
	if (pipe(pipe_fd) == -1)
		sys_error("Error with making pipe");
	pid = fork();
	if (pid == -1)
		sys_error("Error with forking");
	else if (pid == 0)
		child_process(argv, envv, pipe_fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envv, pipe_fd);
	return (0);
}
