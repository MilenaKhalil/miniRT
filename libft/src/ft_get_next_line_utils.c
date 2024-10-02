/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line_utils.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 13:53:49 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/07 16:22:27 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_strjoin_get_line(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		res[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

char	*reset_str(char *str)
{
	int		index;
	char	*res;

	index = new_line_index(str) + 1;
	res = ft_strdup(str + index);
	free(str);
	return (res);
}

int	new_line_index(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		++i;
	return (i);
}
