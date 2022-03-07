#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2)
	{
		i = 0;
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}

/*int		main(void)
{
	printf("%s\n", strdup(NULL));
	printf("%s\n", ft_strdup(NULL));
}*/
