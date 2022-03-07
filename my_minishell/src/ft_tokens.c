/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:11 by khestia           #+#    #+#             */
/*   Updated: 2022/03/07 14:43:54 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tokens(t_mini *shell, int *i)
{
	if (shell->input[*i] == '|')
	{
		if (shell->input[*i + 1] == '|')
			return (ft_or(shell, i));
		return (ft_pipe(shell, i));
	}
}