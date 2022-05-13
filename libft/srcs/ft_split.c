/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 08:59:57 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/13 17:40:15 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	str_alloc(const char *str, char *charset, int len, char **str_arr)
{
	int		i;
	int		ii;
	int		j;
	int		to_allocate;
	char	buffer[1638954];

	i = 0;
	ii = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(charset, str[i]) == NULL)
				break;
			i++;
		}
		j = 0;
		while (i < len)
		{
			if (ft_strchr(charset, str[i]) != NULL)
				break;
			buffer[j] = str[i]; 
			i++;
			j++;
		}
		if (j > 0)
		{
			buffer[j] = '\0';
			to_allocate = sizeof(char) * (ft_strlen(buffer) + 1);
			str_arr[ii] = malloc(to_allocate);
			ft_strlcpy(str_arr[ii], buffer, ft_strlen(buffer) + 1);
			ii++;
		}
	}
}

char	**ft_split(char const *str, char *charset)
{
	int		len;
	int		count;
	int		i;
	int		j;
	char	**str_arr;

	len = ft_strlen(str);
	count = 0;
	i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(charset, str[i]) == NULL)
				break;
			i++;
		}
		j = i;
		while (i < len)
		{
			if (ft_strchr(charset, str[i]) != NULL)
				break;
			i++;
		}
		if (i > j)
			count += 1;
	}
	str_arr = malloc(sizeof(char *) * count);
	str_alloc(str, charset, len, str_arr);	
	return (str_arr);
}
