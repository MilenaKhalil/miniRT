/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrfree.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: milena <milena@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 15:32:59 by milena        #+#    #+#                 */
/*   Updated: 2024/09/08 18:15:35 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_arrfree(char **arr)
{
	int	size;
	int	i;

	size = ft_arrlen((const char **)arr);
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}
