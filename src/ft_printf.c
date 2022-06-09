/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:33:17 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/21 10:33:19 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_until_per(const char **fmt, int *len)
{
	size_t	tmp_len;

	tmp_len = ft_strlen_chr(*fmt, '%');
	if (check_printable_len(len, tmp_len))
	{
		(*len) += write(1, *fmt, tmp_len);
		if (errno != 0)
		{
			(*len) = -1;
			return ;
		}
		(*fmt) = ft_strchr_null(*fmt, '%');
	}
	else
		(*len) = -1;
}

void	print_per_case(const char **fmt, va_list *ap, int *len)
{
	if (**fmt == 'i' || **fmt == 'd')
		print_i_d(ap, len);
	else if (**fmt == 'c' || **fmt == '%')
		print_char(fmt, ap, len);
	else if (**fmt == 's')
		print_s(ap, len);
	else if (**fmt == 'u')
		print_u_x(fmt, ap, len, 10);
	else if (**fmt == 'x' || **fmt == 'X')
		print_u_x(fmt, ap, len, 16);
	else if (**fmt == 'p')
		print_p(ap, len);
	else
	{
		(*len) = -1;
		return ;
	}
	(*fmt)++;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	len = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			print_per_case(&fmt, &ap, &len);
		}
		else
			print_until_per(&fmt, &len);
		if (len == -1)
			break ;
	}
	va_end(ap);
	return (len);
}
