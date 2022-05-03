/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:33:54 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/02 10:33:56 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_strchr(const char *str, int c)
{
	int	len;

	len = 0;
	while(str[len] != '\0' && str[len] != c)
		len++;
	write(1, str, len);
	// write(1, "\n", 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	len = 0;
	while (fmt[len] != '\0')
	{
		if (fmt[len] != '%')
			len += print_strchr(&fmt[len], '%');
		else
			return (len);
	}
	va_end(ap);
	return (len);
}

int	main()
{
	printf("%d\n", ft_printf(""));
	printf("%d\n", printf(""));
}