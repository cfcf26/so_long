/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_so_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:49:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:13:55 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_so_long(char *map, char *line)
{
	char	*temp;

	temp = ft_strjoin(map, line);
	if (temp == NULL)
		ft_error("bash");
	free(map);
	free(line);
	return (temp);
}
