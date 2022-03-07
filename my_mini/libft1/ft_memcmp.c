#include "libft.h"
//#include <string.h>
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && str1[i] == str2[i])
		i++;
	if (str1[i] == str2[i] || n == 0)
		return (0);
	else
		return (str1[i] - str2[i]);
}

/*int		main(void)
{
	const char	s1[6] = "12925";
	const char	s2[6] = "12345";

	printf("%i\n", memcmp(s1, s2, 3));
	printf("%i\n", ft_memcmp(s1, s2, 3));
}*/
