/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:29:33 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:23:58 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	index = 0;
	len = len + 1;
	str = (char*)malloc(len);
	if (str != 0)
	{
		while (index < len - 1)
		{
			str[index] = s[index + start];
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
