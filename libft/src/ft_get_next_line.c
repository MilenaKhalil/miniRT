/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 15:08:03 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/07 16:21:45 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	is_newline_exist(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*extract_str(char *s)
{
	int		size;
	int		i;
	char	*res;

	size = new_line_index(s) + 1;
	res = (char *) malloc ((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*return_line(char **str)
{
	char		*line;

	line = NULL;
	if (is_newline_exist(*str))
	{
		line = extract_str(*str);
		if (!line)
			return (free(*str), *str = NULL, NULL);
		*str = reset_str(*str);
	}
	else if (ft_strlen(*str))
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*read_from_file(int fd, char *str)
{
	int			bytes;
	char		*buffer;

	bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(str), NULL);
	while (!is_newline_exist(str) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[bytes] = '\0';
		str = ft_strjoin_get_line(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_from_file(fd, str);
	if (!str)
		return (NULL);
	line = return_line(&str);
	return (line);
}
