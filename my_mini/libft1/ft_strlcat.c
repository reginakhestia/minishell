#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	result;
	size_t	i;
	size_t	n;

	if (dstsize > ft_strlen(dst))
		result = ft_strlen(dst) + ft_strlen(src);
	else
		result = dstsize + ft_strlen(src);
	i = ft_strlen(dst);
	n = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[n])
		{
			dst[i] = src[n];
			i++;
			n++;
		}
		dst[i] = '\0';
	}
	return (result);
}

/*int		main(void)
{
	char	dst[2] = {'1'};
	const char	src[6] = "abcde";

	printf("%li\n", strlcat(dst, NULL, 1));
	printf("%li\n", ft_strlcat(dst, NULL, 1));
}*/
