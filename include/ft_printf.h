/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:32:51 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/02 15:32:52 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

//
int		ft_printf(const char *fmt, ...);
//check_printable_len.c
bool	check_printable_len(int *len, size_t put_len);
//convert.c
char	*convert(size_t num, int base);
//ft_calloc.c
void	*ft_calloc(size_t count, size_t size);
//ft_memset.c
void	*ft_memset(void *buf, int ch, size_t n);
//ft_bzero.c
void	ft_bzero(void *s, size_t n);
//ft_strlen_chr.c
size_t	ft_strlen_chr(const char *str, int c);
//ft_strlen.c
size_t	ft_strlen(const char *str);
//ft_strchr.c
char	*ft_strchr_null(const char *str, int c);
//print_c_s_p_per.c
void	print_char(const char **fmt, va_list *ap, int *len);
void	print_s(va_list *ap, int *len);
void	print_p(va_list *ap, int *len);
//print_id_u_x_p.c
void	print_i_d(va_list *ap, int *len);
void	print_u_x(const char **fmt, va_list *ap, int *len, int base);
//toupper_str.c
void	toupper_str(char *str);

#endif
