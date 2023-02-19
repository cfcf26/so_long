/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:43:19 by ekwak             #+#    #+#             */
/*   Updated: 2022/09/20 00:19:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_2(char c, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		temp;
	int		result;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			temp = ft_printf_2(*format, ap);
			if (temp == -1)
				return (-1);
			result += temp;
		}
		else
			result += ft_print_c(*format);
		format++;
	}
	va_end(ap);
	return (result);
}

static int	ft_printf_2(char c, va_list ap)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_print_c(va_arg(ap, int));
	else if (c == 's')
		result += ft_print_s(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		result += ft_print_i(va_arg(ap, int));
	else if (c == 'u')
		result += ft_print_u(va_arg(ap, unsigned int));
	else if (c == 'p')
		result += ft_print_p(va_arg(ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		result += ft_print_x(va_arg(ap, unsigned int), c);
	else if (c == '%')
		result += ft_print_c('%');
	else
		result = -1;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int			i;
	char		*src_dup;
	const int	src_len = ft_strlen(src);

	src_dup = malloc(sizeof(char) * (src_len + 1));
	if (src_dup == NULL)
	{
		free(src_dup);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		src_dup[i] = src[i];
		i++;
	}
	src_dup[i] = '\0';
	return (src_dup);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int	i;
	int	rev_tab;

	i = 0;
	while (i < (size / 2))
	{
		rev_tab = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = rev_tab;
		i++;
	}
}
