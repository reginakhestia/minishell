#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *s, const char *c, size_t len)
{
	int		i;
	int		n;
	char	*str;
	int		res;

	str = (char *)s;
	res = 1;
	n = 0;
	i = 0;
	if (ft_strlen(c) == 0)
		return (str);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (len >= ft_strlen(c) && str[i])
	{
		res = ft_memcmp(&str[i], c, ft_strlen(c));
		if (res == 0)
			break ;
		len--;
		i++;
	}
	if (res == 0)
		return (&str[i]);
	return (NULL);
}

/*int		main(void)
{
	const char s[14] = "AAAAAAAAAAAAA";
	//const char c[5] = s;;

	printf("%s\n", strnstr(s, s, 13));
	printf("%s\n", ft_strnstr(s, s, 13));
}*/
