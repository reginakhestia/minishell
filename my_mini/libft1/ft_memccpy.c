#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memccpy(void *s2, const void *s1, int c, size_t n)
{
	unsigned char	*a2;
	unsigned char	*a1;
	unsigned char	ch;
	int				count;

	ch = (unsigned char)c;
	count = 0;
	a2 = (unsigned char *)s2;
	a1 = (unsigned char *)s1;
	if (!n)
		return (NULL);
	while (n)
	{
		a2[count] = a1[count];
		if (a1[count] == ch)
			return (&s2[count + 1]);
		count++;
		n--;
	}
	return (NULL);
}

/*int		main(void)
{
	char	s2[10] = {'1', '1', '1', '1', '1', '1', '1', '1', '1'};

	printf("%s\n", memccpy(s2, "B", 0, 10));
	printf("%s\n", ft_memccpy(s2, "B", 0, 10));
}*/
