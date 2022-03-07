#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memcpy (void *s2, const void *s1, size_t n)
{
	char		*result;
	const char	*sourse;
	int			count;

	count = 0;
	result = (char *)s2;
	sourse = (const char *)s1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (n--)
	{
		result[count] = sourse[count];
		count++;
	}
	return (result);
}

/*int		main(void)
{
	char	s2[5] = {'1', '2', '3', '4'};
	const char s1[4] = "abc";

	printf("%s\n", memcpy(s2, s1, 0));
	printf("%s\n", ft_memcpy(s2, s1, 0));
}*/
