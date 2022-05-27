/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:45:16 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/23 16:45:18 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

void	toupper_str(char *str)
{
	while (*str != '\0')
	{
		if (ft_islower(*str))
			*str -= 32;
		str++;
	}
}
