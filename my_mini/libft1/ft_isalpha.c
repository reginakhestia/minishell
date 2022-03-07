#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i\n", isalpha(''));
	printf("%i\n", ft_isalpha(''));
}*/
