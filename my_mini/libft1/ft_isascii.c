#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i\n", isascii(800));
	printf("%i\n", ft_isascii(800));
}*/
