#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	if (n == 0)
		return (0);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && s11[i] == s22[i] && s11[i] && s22[i])
		i++;
	if (s11[i] == s22[i])
		return (0);
	 else
		return (s11[i] - s22[i]);
}

/*int	main(void)
{
	const char s1[4] = "129";
	const char s2[4] = "123";

	printf("%i\n", strncmp(s1, s2, 3));
	printf("%i\n", ft_strncmp(s1, s2, 3));
}*/
