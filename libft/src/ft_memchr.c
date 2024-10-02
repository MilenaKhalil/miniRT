/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:27:03 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/23 13:19:59 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	tmp = (const unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)(tmp + i));
		++i;
	}
	return (NULL);
}
