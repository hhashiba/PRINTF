/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id_u_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:46:04 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/21 22:46:06 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_i_d(va_list *ap, int *len)
{
	long int	num;
	int			sign;
	char		*str;
	size_t		str_len;

	num = va_arg(*ap, int);
	sign = 1;
	if (num < 0)
		sign = -1;
	str = convert(num * sign, 10);
	if (num >= 0)
		sign = 0;
	str_len = ft_strlen(str);
	if (check_printable_len(len, str_len + sign))
	{
		if (num < 0)
			(*len) += write(1, "-", 1);
		(*len) += write(1, str, str_len);
	}
	else
		(*len) = -1;
	if (num != 0)
		free(str);
}

void	print_u_x(const char **fmt, va_list *ap, int *len, int base)
{
	unsigned int	num;
	size_t			str_len;
	char			*str;

	num = va_arg(*ap, unsigned int);
	str = convert(num, base);
	if (**fmt == 'X')
		toupper_str(str);
	str_len = ft_strlen(str);
	if (check_printable_len(len, str_len))
		(*len) += write(1, str, str_len);
	else
		(*len) = -1;
	if (num != 0)
		free(str);
}
