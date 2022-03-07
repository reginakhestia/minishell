/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:34:39 by khestia           #+#    #+#             */
/*   Updated: 2022/02/27 10:35:29 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_single_quote(t_mini *shell, int *i)
{
	int		start;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*result;

	start = *i;
	while (shell->input[++(*i)])
		if (shell->input[*i] == '\'')
			break ;
	if (!shell->input[*i])
		return (ft_error_syntax(shell, &shell->input[*i], 1));
	s1 = ft_substr(shell->input, 0, start);
	s2 = ft_substr(shell->input, start + 1, *i - 1 - start);
	s3 = ft_strdup(&shell->input[*i + 1]);
	result = ft_strjoin_free(s1, s2);
	result = ft_strjoin_free(result, s3);
	free(shell->input);
	shell->input = result;
	*i -= 2;
	return (0);
}

int	ft_double_quotes(t_mini *shell, int *i)
{
	int		start;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*result;

	start = *i;
	while (shell->input[++(*i)])
	{
		if (shell->input[*i] == '\"')
			break ;
		else if (shell->input[*i] == '$' && shell->input[*i + 1] != '\"')
			ft_dollar(shell, i);
	}
	if (!shell->input[*i])
		return (ft_error_syntax(shell, &shell->input[*i], 1));
	s1 = ft_substr(shell->input, 0, start);
	s2 = ft_substr(shell->input, start + 1, *i - 1 - start);
	s3 = ft_strdup(&shell->input[*i + 1]);
	result = ft_strjoin_free(s1, s2);
	result = ft_strjoin_free(result, s3);
	free(shell->input);
	shell->input = result;
	*i -= 2;
	return (0);
}
