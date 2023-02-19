/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:43:08 by ekwak             #+#    #+#             */
/*   Updated: 2022/09/20 14:18:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_FORMAT "cspdiuxX%"
# define NUM "0123456789"
# define S_HEX "0123456789abcdef"
# define L_HEX "0123456789ABCDEF"
# include <stdarg.h> //va_start, va_arg, va_copy, va_end
# include <stdlib.h> //malloc, free
# include <unistd.h> //write
/*libftprintf*/
int		ft_printf(const char *input, ...);
/*format c ~ X*/
int		ft_print_c(int c); // %c
int		ft_print_s(char *str); // %s
int		ft_print_i(int integer); // %d %i
int		ft_print_p(unsigned long long integer); // %p
int		ft_print_u(unsigned int integer); // %u
int		ft_print_x(unsigned int input, char size); // %x %X
/*input to string*/
char	*ft_itoa(int n);
char	*ft_itobase(unsigned long long n, char *base, int base_idx);
/*libft*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
void	ft_rev_char_tab(char *tab, int size);
#endif
