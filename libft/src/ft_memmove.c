/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:44:25 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/03 18:32:00 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;
	int			i;

	if (dst && src)
	{
		dst_tmp = (char *)dst;
		src_tmp = (const char *)src;
		if (dst_tmp < src_tmp)
		{
			ft_memcpy(dst, src, len);
		}
		else
		{
			i = len - 1;
			while (i >= 0)
			{
				dst_tmp[i] = src_tmp[i];
				--i;
			}
		}
	}
	return (dst);
}
