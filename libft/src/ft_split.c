/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:56:29 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/07 16:15:26 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (len < n)
		n = len;
	res = (char *) malloc ((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

static void	free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

static char	**fill_arr(char **arr, char const *s, size_t words_count, char c)
{
	size_t			word_num;
	size_t			i;
	size_t			len;

	i = 0;
	word_num = 0;
	while (word_num < words_count)
	{
		len = 0;
		while (s[i] == c)
			++i;
		while (s[i] != c && s[i])
		{
			++i;
			++len;
		}
		arr[word_num++] = ft_strndup(&s[i - len], len);
		if (!arr[word_num - 1])
		{
			free_arr(arr, word_num - 1);
			return (NULL);
		}
	}
	arr[word_num] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	size_t			words_count;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	res = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_arr(res, s, words_count, c));
}
