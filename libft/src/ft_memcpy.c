/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 14:23:51 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/23 14:14:18 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	unsigned int		i;

	if (dst && src)
	{
		tmp_dst = dst;
		tmp_src = src;
		i = 0;
		while (i < n)
		{
			tmp_dst[i] = tmp_src[i];
			++i;
		}
	}
	return (dst);
}
