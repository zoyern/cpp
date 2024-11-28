/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:55:54 by marvin            #+#    #+#             */
/*   Updated: 2024/11/23 05:55:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *s)
{
	int	i = -1;
	if (!s)
		ft_putstr(fd, "(null)");
	while (s[++i])
		ft_putchar(fd, s[i]);
}

int	exec_fork_child(char **argv, int index, int pipefd[2], int pipe_in, char **envp)
{
	int	ret = 0;

	if (pipe_in)
	{
    	if (dup2(pipe_in, 0) < 0)
			return (ft_putstr(2, "error: fatal"), -1);
		close(pipe_in);
	}
	if (argv[index] && !strcmp(argv[index], "|"))
	{
        if (dup2(pipefd[1], 1) < 0)
			return (ft_putstr(2, "error: fatal"), -1);
		close(pipefd[1]);
	}
	if (pipefd[0])
		close(pipefd[0]);
	argv[index] = NULL;
	ret = execve(argv[0], argv, envp);
	close(pipe_in);
	close(pipefd[1]);
	ft_putstr(2, "error: cannot execute ");
	ft_putstr(2, argv[0]);
	ft_putchar(2, '\n');
	return (ret);
}

int ft_exec(char **argv, int index, char **envp, int *pipe_in, int pipefd[2])
{
	if (argv[index] && !strcmp(argv[index], "|"))
        if (pipe(pipefd) < 0)
			return (ft_putstr(2, "error: fatal"), -1);
	int pid = fork();
	if (pid < 0)
		return (ft_putstr(2, "error: fatal"), -1);
	if (!pid)
		exit (exec_fork_child(argv, index, pipefd, *pipe_in, envp));
	if (*pipe_in)
		close(*pipe_in);
	if (argv[index] && !strcmp(argv[index], "|"))
		return (close(pipefd[1]), *pipe_in = pipefd[0], 0);
	return (0);
}

int	ft_cd(char **argv, int start, int index)
{
    if (argv[start] && !strcmp(argv[start], "cd"))
    {
        if (index - start != 2)
            return (ft_putstr(2, "error: cd: bad arguments\n"), 0);
        if (chdir(argv[start + 1]) != 0)
            return (ft_putstr(2, "error: cd: cannot change directory to "), ft_putstr(2, argv[start + 1]), ft_putchar(2, '\n'), 0);
        return (1);
    }
	return (0);
}

int	ft_wait()
{
	int	status = 0;
	int	ret = 0;

	while (waitpid(-1, &status, 0) != -1)
		if (WIFEXITED(status) && status)
			ret = WEXITSTATUS(status);
	return (ret);
}

int main(int argc, char **argv, char **envp)
{
	int pipefd[2] = {0, 1}, pipe_in = 0, status = 0, index = 0;

	if (argc < 2)
		return (0);
	while (argv[index] && argv[++index]) {
        int start = index;
        while (argv[index] && strcmp(argv[index], ";") && strcmp(argv[index], "|"))
            index++;
		status = ft_cd(argv, start, index);
        if (!status) { status = ft_exec(argv + start, index - start, envp, &pipe_in, pipefd); if (status < 0) return (1);}
		else return (!status);
		if ((argv[index] && !strcmp(argv[index], ";"))) { status = ft_wait(); close(pipe_in); pipe_in = 0;}
	}
	status = ft_wait();
	if (pipe_in)
		close(pipe_in);
    return (status);
}