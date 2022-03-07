#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i\n", isalnum('5'));
	printf("%i\n", ft_isalnum('5'));
}*/
