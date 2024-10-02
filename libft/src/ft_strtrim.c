/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:24:43 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/03 18:32:00 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static int	is_in_set(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

static size_t	trimmed_len(char const *s1, char const *set)
{
	int	end;
	int	start;

	end = ft_strlen(s1) - 1;
	start = 0;
	while (start < end && is_in_set(s1[start], set))
		++start;
	while (end >= 0 && is_in_set(s1[end], set))
		--end;
	if (end < start)
		return (0);
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	start;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = trimmed_len(s1, set);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	start = 0;
	while (is_in_set(s1[start], set))
		++start;
	i = 0;
	while (i < len)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
