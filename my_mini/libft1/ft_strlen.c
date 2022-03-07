#include "libft.h"
//#include <string.h>
//#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

/*int		main(void)
{
	printf("%li\n", strlen(""));
	printf("%li\n", ft_strlen(""));
}*/
