/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:38:03 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/12 11:38:04 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strchr_null(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			break ;
		str++;
	}
	return ((char *)str);
}
