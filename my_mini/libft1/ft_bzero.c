#include "libft.h"
//#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*s1;
	int		count;

	count = 0;
	s1 = s;
	while (n)
	{
		s1[count] = '\0';
		count++;
		n--;
	}
	s = s1;
}

/*int		main(void)
{
	bzero(NULL, 5);
	ft_bzero(NULL, 5);
}*/
