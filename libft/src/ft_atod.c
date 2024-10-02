/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/30 16:48:28 by pyevtush      #+#    #+#                 */
/*   Updated: 2024/09/08 18:19:45 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	get_num_after_dot(const char	*str)
{
	int		i;
	int		len;
	double	multiplier;

	multiplier = 1;
	len = ft_strlen(str);
	i = 0;
	while (i++ < len)
		multiplier *= 0.1;	
	return (ft_atoi(str) * multiplier);
}

double	ft_atod(const char *str)
{
	int		i;
	int		len;
	char	**arr;
	double	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = -1;
		++i;
	}
	arr = ft_split(str + i, '.');
	if (!arr)
		return (0);
	len = ft_arrlen((const char**)arr);
	if (!len || len > 2)
		return (ft_arrfree(arr), 0);
	res += (double)ft_atoi(arr[0]);
	if (len == 2)
		res += get_num_after_dot(arr[1]);
	return (res * sign);
}
