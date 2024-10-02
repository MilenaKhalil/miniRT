/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:59:22 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/03 18:32:00 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (!haystack || !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (start < len && haystack[start])
	{
		i = 0;
		while (needle[i] && haystack[start + i] && start + i < len)
		{
			if (haystack[start + i] == needle[i])
				++i;
			else
				break ;
		}
		if (needle[i] == '\0')
			return ((char *)haystack + start);
		else
			++start;
	}
	return (NULL);
}
