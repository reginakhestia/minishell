/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:16:22 by khestia           #+#    #+#             */
/*   Updated: 2022/03/07 14:39:46 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser(t_mini *shell, int *i)
{
	if (shell->input[*i] == '$')
		return (ft_dollar(shell, i));
	else if (shell->input[*i] == '\'')
		return (ft_single_quote(shell, i));
	else if (shell->input[*i] == '\"')
		return (ft_double_quote(shell, i));
	else if (shell->input[*i] == ' '
		|| shell->input[*i] == '\t' || !shell->input[*i])
		return (ft_space(shell, i));
	else if (ft_tokens(shell, i))
		retern (1);
	
}

int	ft_preparser(t_mini *shell)
{
	int	i;

	i = 0;
	if (ft_clear_input(shell) || !shell->input)
		return (0);
	// application
	while (shell->input)
	{
		if (ft_parser(shell, &i))
			return (0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	*shell;

	init_mini(shell, argv, argc);
	get_env(shell, envp);
	rl_outstream = stderr; // что это
	ft_signal();
	while (1)
	{
		shell->input = readline("minishell");
		if (!shell->input)
		{
			write(2, "exit\n", 5);
			exit(0);
		}
		if (!ft_strlen(shell->input))
		{
			free (shell->input);
			continue ;
		}
		add_history(shell->input);
		ft_preparser(shell);
	}
}
