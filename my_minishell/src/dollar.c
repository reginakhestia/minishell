/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:16:36 by khestia           #+#    #+#             */
/*   Updated: 2022/02/27 10:27:38 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(t_envp *env, char *key)
{
	t_envp	*i;

	i = env;
	while (i)
	{
		if (ft_strcmp(key, i->key) == 0)
			return (i->value);
		i = i->next;
	}
	return (NULL);
}

int	ft_dollar_status(t_mini *shell, int *i)
{
	char	*s1;
	char	*s2;
	char	*status;
	char	*result;
	int		len;

	s1 = ft_substr(shell->input, 0, i - 1);
	s2 = ft_strdup(&shell->input[*i + 1]);
	status = ft_itoa(shell->exit_status);
	len = ft_strlen(status);
	result = ft_strjoin_free(s1, status);
	result = ft_strjoin_free(result, s2);
	free(shell->input);
	shell->input = result;
	*i += len - 2;
	return (0);
}

int	dollar_quote(t_mini *shell, int *i)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = ft_substr(shell->input, 0, i - 1);
	s2 = ft_strdup(&shell->input[*i]);
	result = ft_strjoin_free(s1, s2);
	free(shell->input);
	shell->input = result;
	*i -= 2;
	return (0);
}

int	dollar_env(t_mini *shell, int *i, int start)
{
	char	*value;
	char	*key;
	char	*s;
	char	*result;

	while (ft_isalnum(shell->input[*i]) || shell->input == '_')
		*i += 1;
	key = ft_substr(shell->input, start + 1, *i - start - 1);
	value = ft_get_value(shell->environment, key);
	s = ft_substr(shell->input, 0, start);
	result = ft_strdup(&shell->input[*i]);
	*i += ft_strlen(value) - ft_strlen(result) - 2;
	free(key);
	key = ft_strjoin(value, result);
	free(result);
	result = ft_strjoin_free(s, key);
	if (!ft_strlen(result))
	{
		free(result);
		result = NULL;
	}
	free(shell->input);
	shell->input = result;
	return (0);
}

int	ft_dollar(t_mini *shell, int *i)
{
	int	start;

	*i += 1;
	start = *i - 1;
	if (shell->input[*i] == '?')
		return (ft_dollar_status(shell, i));
	else if (shell->input[*i] == '\'' || shell->input[*i] == '\"')
		return (dollar_quote(shell, i));
	else if (shell->input[*i] == ' ' || shell->input[*i] == '\t'
		|| shell->input[*i] == '\0')
	{
		*i--;
		return (0);
	}
	else
		return (dollar_env(shell, i, start));
}
