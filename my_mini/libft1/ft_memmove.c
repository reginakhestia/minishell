#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s2;
	const char	*s1;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	s2 = (char *)dst;
	s1 = (const char *)src;
	if (src < dst)
	{
		while (len--)
			s2[len] = s1[len];
	}
	else
	{
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dst);
}

/*int		main(void)
{
	//char dst[4] = {'1', '1', '1'};
	//const char src[4] = "222";

	printf("%s\n", memmove(NULL, NULL, 5));
	printf("%s\n", ft_memmove(NULL, NULL, 5));
}*/
