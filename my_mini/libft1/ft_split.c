#include "libft.h"
//#include <stdio.h>

static int	ft_count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[count])
	{
		while (s[count] == c)
			count++;
		if (!s[count])
			break ;
		while (s[count] != c && s[count])
			count++;
		i++;
	}
	return (i);
}

static int	ft_count_char(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_full_tab(char *tab, const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		tab[count] = s[i];
		i++;
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

static char	**ft_if_null(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count_word;
	int		i;
	int		num;

	if (!s)
		return (NULL);
	count_word = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!tab)
		return (NULL);
	i = -1;
	num = 0;
	while (++i < count_word && s[num])
	{
		while (s[num] == c)
			num++;
		tab[i] = (char *)malloc(sizeof(char) * (ft_count_char(&s[num], c) + 1));
		if (!tab[i])
			return (ft_if_null(tab, i));
		tab[i] = ft_full_tab(tab[i], &s[num], c);
		num = num + ft_count_char(&s[num], c);
	}
	tab[i] = NULL;
	return (tab);
}

/*int		main(void)
{
	ft_split("tripouille", 0);
}*/
