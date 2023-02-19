/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:20:45 by ekwak             #+#    #+#             */
/*   Updated: 2022/09/21 11:46:24 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itobase(unsigned long long n, char *base, int base_idx)
{
	char	str[21];
	int		i;
	char	*dup;

	i = 0;
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	while (n > 0)
	{
		str[i] = base[n % base_idx];
		n = n / base_idx;
		i++;
	}
	str[i] = '\0';
	ft_rev_char_tab(str, i);
	dup = ft_strdup(str);
	return (dup);
}
