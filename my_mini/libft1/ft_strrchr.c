#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	ch = (char)c;
	while (i && str[i] != ch)
		i--;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}

/*int		main(void)
{
	const char	s[5] = "1212";

	printf("%s\n", strrchr(s, '2'));
	printf("%s\n", ft_strrchr(s, '2'));
}*/
