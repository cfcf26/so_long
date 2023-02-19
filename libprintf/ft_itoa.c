/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:00:39 by ekwak             #+#    #+#             */
/*   Updated: 2022/09/21 11:46:25 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_2(unsigned int n, int flag);

char	*ft_itoa(int n)
{
	int		flag;

	flag = 0;
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else if (n < 0)
	{
		n *= -1;
		flag = 1;
	}
	return (ft_itoa_2((unsigned int)n, flag));
}

static char	*ft_itoa_2(unsigned int n, int flag)
{
	char	str[12];
	int		i;
	char	*dup;

	i = 0;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (flag == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	ft_rev_char_tab(str, i);
	dup = ft_strdup(str);
	return (dup);
}
