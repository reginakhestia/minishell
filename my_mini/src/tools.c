/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:17:45 by khestia           #+#    #+#             */
/*   Updated: 2022/03/04 18:22:30 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini(t_mini *shell, char **argv, int argc)
{
	shell = (t_mini *)malloc(sizeof(t_mini));
	if (!shell)
		exit(0);
	shell->argc = argc;
	shell->argv = argv;
	shell->environment = NULL;
	shell->exit_status = 0;
	shell->apps = NULL;
	shell->launch_method = 0;
}

void	ft_controlc(int sig)
{
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	errno = 1; // ??
}

void	ft_signal(void)
{
	signal(SIGINT, ft_controlc);
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	ft_clear_input(t_mini *shell)
{
	int		i;
	char	*inp;

	i = 0;
	while (shell->input[i] == ' ' || shell->input == '\t')
		i++;
	if (shell->input[i] == '|' || shell->input[i] == '&')
	{
		if (shell->input[i] == shell->input[i + 1])
		{
			printf("minishell: syntax error near unexpected token `%c%c'\n",
				shell->input[i]);
			return (1);
		}
		printf("minishell: syntax error near unexpected token `%c'\n",
			shell->input[i]);
		return (1);
	}
	inp = NULL;
	if (shell->input[i])
		inp = ft_strdup(&shell->input[i]);
	free(shell->input);
	shell->input = inp;
	return (0);
}

int	ft_error_syntax(t_mini *shell, char *s, int len)
{
	write(2, "minishell: ", 11);
	write(2, "syntax error near unexpected token `", 36);
	write(2, s, len);
	write(2, "'\n", 2);
	shell->exit_status = 258;
	return (1);
}
