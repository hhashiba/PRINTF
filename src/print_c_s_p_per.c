/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s_p_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:45:41 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/21 22:45:43 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_char(const char **fmt, va_list *ap, int *len)
{
	unsigned char	c;

	if (**fmt == '%')
		c = '%';
	else
		c = va_arg(*ap, int);
	if (check_printable_len(len, 1))
		(*len) += write(1, &c, 1);
	else
		(*len) = -1;
}

void	print_s(va_list *ap, int *len)
{
	const char	*str;
	size_t		str_len;

	str = va_arg(*ap, const char *);
	if (str == NULL)
	{
		if (check_printable_len(len, 6))
			(*len) += write(1, "(null)", 6);
		else
			(*len) = -1;
		return ;
	}
	str_len = ft_strlen_chr(str, '\0');
	if (check_printable_len(len, str_len))
		(*len) += write(1, str, str_len);
	else
		(*len) = -1;
}

void	print_p(va_list *ap, int *len)
{
	size_t		num;
	char		*str;
	size_t		str_len;

	num = va_arg(*ap, size_t);
	str = convert(num, 16);
	str_len = ft_strlen(str);
	if (check_printable_len(len, str_len + 2))
		(*len) += write(1, "0x", 2) + write(1, str, str_len);
	else
		(*len) = -1;
	if (num != 0)
		free(str);
}
