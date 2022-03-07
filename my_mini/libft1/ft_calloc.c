#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*adres;

	adres = malloc(num * size);
	if (adres)
	{
		ft_memset(adres, 0, num * size);
		return (adres);
	}
	else
		return (NULL);
}

/*int		main(void)
{
	printf("%s\n", calloc(100000, 100000));
	printf("%s\n", ft_calloc(100000, 100000));
}*/
