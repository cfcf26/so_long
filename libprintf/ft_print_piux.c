/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_piux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:25:38 by ekwak             #+#    #+#             */
/*   Updated: 2022/09/21 11:46:23 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long long input)
{
	int		i;
	char	*str;

	str = ft_itobase(input, S_HEX, 16);
	if (str == NULL)
		return (-1);
	i = ft_print_s("0x");
	i += ft_print_s(str);
	free(str);
	return (i);
}

int	ft_print_i(int input)
{
	int		i;
	char	*str;

	str = ft_itoa(input);
	if (str == NULL)
		return (-1);
	i = ft_print_s(str);
	free(str);
	return (i);
}

int	ft_print_u(unsigned int input)
{
	int		i;
	char	*str;

	str = ft_itobase((unsigned long long)input, NUM, 10);
	if (str == NULL)
		return (-1);
	i = ft_print_s(str);
	free(str);
	return (i);
}

int	ft_print_x(unsigned int input, char size)
{
	int		i;
	char	*str;

	if (size == 'x')
	{
		str = ft_itobase((unsigned long long)input, S_HEX, 16);
		if (str == NULL)
			return (-1);
		i = ft_print_s(str);
		free(str);
		return (i);
	}
	else
	{
		str = ft_itobase((unsigned long long)input, L_HEX, 16);
		if (str == NULL)
			return (-1);
		i = ft_print_s(str);
		free(str);
		return (i);
	}
}
