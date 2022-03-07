#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) + 1 >= len)
		s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (ft_strlen(s) + 1 < len)
		s1 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s1)
		return (NULL);
	else
	{
		while (len && s[start] && start < ft_strlen(s))
		{
			s1[i] = s[start];
			i++;
			len--;
			start++;
		}
		s1[i] = '\0';
		return (s1);
	}
}

/*int	main(void)
{
	printf("%s\n", ft_substr("123456789", 3, 10));
}*/
