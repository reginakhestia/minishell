#include "libft.h"
//#include <string.h>
//#include <stdio.h>

static int	ft_atatoi(const char *str, int s, int i)
{
	long long int		num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num == 214748364 && s == -1 && str[i] == '8')
			return (-2147483648);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * s);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;

	i = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t'
		   || str[i] == '\n' || str[i] == '\v'
		   || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			s = 1;
		else
			s = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	else
		return (ft_atatoi(str, s, i));
}

/*int	main(void)
{
	printf("%i\n", atoi("9223372036854775808"));
	printf("%i\n", ft_atoi("9223372036854775808"));
}*/
