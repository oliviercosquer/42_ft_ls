/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:27:05 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:36:20 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int	length;
	int	index;
	char	*new_str;

	length = ft_strlen((char*)str);
	index = 0;
	new_str = (char*)malloc(length);
	new_str[length] = '\0';
	while (index < length)
	{
		new_str[index] = str[index];
		index++;
	}
	return (new_str);
}
