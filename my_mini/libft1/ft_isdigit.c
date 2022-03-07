#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i\n", isdigit(' '));
	printf("%i\n", ft_isdigit(' '));
}*/
