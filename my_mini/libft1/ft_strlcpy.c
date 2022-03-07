#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	if (dstsize != 0)
	{
		while (dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/*int		main(void)
{
	char	dst[4] = {'1', '2', '3'};
	const char	src[5] = "abcd";

	//printf("%li\n", strlcpy(dst, NULL, 4));
	printf("%li\n", ft_strlcpy(dst, src, 10));
}*/
