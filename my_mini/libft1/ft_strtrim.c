#include "libft.h"
//#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		n;
	int		z;

	i = 0;
	z = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	n = ft_strlen(s1);
	while (n > i && ft_strchr(set, s1[n - 1]))
		n--;
	s = (char *)malloc(sizeof(char) * (n - i + 1));
	if (!s)
		return (NULL);
	while (i < n)
		s[z++] = s1[i++];
	s[z] = '\0';
	return (s);
}

/*int		main(void)
{
	printf("%s\n", ft_strtrim("  \t \t \n   \n\n\n\t", ""));
}*/
