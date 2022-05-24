/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printable_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:51:11 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/21 22:51:12 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	check_printable_len(int *len, size_t put_len)
{
	if (put_len > INT_MAX)
		return (false);
	if ((size_t)(*len) > INT_MAX - put_len)
		return (false);
	return (true);
}
