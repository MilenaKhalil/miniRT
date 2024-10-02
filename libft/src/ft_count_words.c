/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 16:08:51 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/04/25 18:35:41 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		++i;
	if (s[i])
		++count;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			++count;
		++i;
	}
	return (count);
}
