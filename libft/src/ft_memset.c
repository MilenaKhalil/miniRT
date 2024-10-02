/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:26:55 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/06 18:25:42 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned int	i;

	if (!b)
		return (NULL);
	i = 0;
	tmp = b;
	while (i < len)
	{
		tmp[i] = c;
		++i;
	}
	return (b);
}
