#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	ch = (char)c;
	while (i != ft_strlen(str) + 1 && str[i] != ch && str[i])
		i++;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}

/*int		main(void)
{
	const char	s[4] = "123";

	printf("%s\n", strchr(s, '5'));
	printf("%s\n", ft_strchr(s, '5'));
}*/
