/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:17:17 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/19 10:17:20 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*convert(size_t num, int base)
{
	size_t			tmp;
	int				size;
	char			*str;

	if (num == 0)
		return ("0");
	tmp = num;
	size = 0;
	while (tmp != 0)
	{
		tmp /= base;
		size++;
	}
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str += size;
	while (num != 0)
	{
		*--str = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (str);
}
