/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:52:51 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:14:19 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file_extension(char *file_name)
{
	int		i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 4)
	{
		ft_printf("Error : Wrong file extension (1)\n");
		return (1);
	}
	if (file_name[i - 4] != '.' || file_name[i - 3] != 'b' \
	|| file_name[i - 2] != 'e' || file_name[i - 1] != 'r')
	{
		ft_printf("Error : Wrong file extension (1)\n");
		return (1);
	}
	return (0);
}
