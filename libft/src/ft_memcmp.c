/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:45:19 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/07 15:34:41 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_tmp = (const unsigned char *)s1;
	s2_tmp = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1_tmp[i] != s2_tmp[i])
			return (s1_tmp[i] - s2_tmp[i]);
		++i;
	}
	return (0);
}
