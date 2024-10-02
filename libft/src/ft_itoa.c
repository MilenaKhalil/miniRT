/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 17:46:44 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/03 18:32:00 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static int	char_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	size = char_count(n) + sign;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	res[0] = '-';
	while (size >= sign)
	{
		res[size] = n % 10 + '0';
		n /= 10;
		--size;
	}
	return (res);
}
