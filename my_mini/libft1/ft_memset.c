#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memset (void *s, int c, size_t n)
{
	char			*s1;
	int				count;
	unsigned char	ch;

	ch = (unsigned char)c;
	count = 0;
	s1 = (char *)s;
	if (!s1)
		*s1 = 1;
	while (n-- && s)
	{
		s1[count++] = ch;
	}
	return (s);
}

/*int		main(void)
{
	//char s[4] = {'1', '2', '3'};

	//printf("%s\n", memset(NULL, 51, 1));
	printf("%s\n", ft_memset(NULL, 51, 1));
}*/
