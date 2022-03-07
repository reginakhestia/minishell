#include "libft.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;
	int		n;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	else
	{
		i = -1;
		while (s1[++i])
		{
			s[i] = s1[i];
		}
		i = 0;
		n = ft_strlen(s1);
		while (s2[i])
			s[n++] = s2[i++];
		s[n] = '\0';
		return (s);
	}
}

/*int		main(void)
{
	printf("%s\n", ft_strjoin("", ""));
}*/
