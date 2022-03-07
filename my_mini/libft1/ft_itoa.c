#include "libft.h"
//#include <stdio.h>

static int	ft_count_ch(int n)
{
	int	n1;
	int	i;

	i = 0;
	n1 = n;
	if (n1 == 0)
		return (1);
	if (n1 < 0)
		i++;
	while (n1 != 0)
	{
		i++;
		n1 = n1 / 10;
	}
	return (i);
}

static char	*ft_mini_itoa(char *s, int i, int j, int n)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
		j = 1;
	}
	s[i] = '\0';
	while (i > j)
	{
		s[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = ft_count_ch(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	else
		s = ft_mini_itoa(s, i, j, n);
	return (s);
}

/*int		main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
}*/
