/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:28:14 by khestia           #+#    #+#             */
/*   Updated: 2022/02/27 10:34:28 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*ft_new_env(char *s)
{
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	if (!new)
		return (NULL);
	new->key = s[0];
	new->value = s[1];
	new->next = NULL;
	new->prev = NULL;
	return (env);
}

t_envp	*ft_prev_env(t_envp *env)
{
	t_envp	*t;

	t = env;
	while (t->next)
		t = t->next;
	return (t);
}

void	ft_full_env(t_envp **env, t_envp *new)
{
	t_envp	*prev;

	if (!*env)
	{
		*env = new;
		return ;
	}
	prev = ft_prev_env(*env);
	new->prev = prev;
	prev->next = new;
}

void	get_env(t_mini *shell, char **envp)
{
	char	**s;
	int		i;

	i = 0;
	while (envp[i])
	{
		s = ft_split(envp[i], '=');
		ft_full_env(shell->environment, ft_new_env(s));
		i++;
		free(s);
	}
}
