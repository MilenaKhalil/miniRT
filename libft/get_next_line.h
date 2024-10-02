/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 15:07:54 by pyevtush      #+#    #+#                 */
/*   Updated: 2023/03/07 16:22:36 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_get_line(char *s1, char const *s2);
char	*reset_str(char *str);
int		new_line_index(char *s);
int		is_newline_exist(char *s);
char	*extract_str(char *s);
char	*return_line(char **str);

#endif