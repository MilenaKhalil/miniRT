/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:01:23 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/03 18:32:00 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
