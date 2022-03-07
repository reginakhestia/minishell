#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	int				count;

	ch = (unsigned char)c;
	count = 0;
	str = (unsigned char *)s;
	if (!str)
		*str = 1;
	while (n-- && s)
	{
		if (str[count] == ch)
			return (&str[count]);
		count++;
	}
	return (NULL);
}

/*int		main(void)
{
	const char s[5] = "     ";

	printf("%s\n", memchr(s, 51, 10));
	printf("%s\n", ft_memchr(s, 51, 10));
}*/
