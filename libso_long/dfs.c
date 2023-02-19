/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:24 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:13:31 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(char *map, int p_i, char target, t_map *m_i)
{
	int	target_i;

	if (p_i < 0 || p_i >= m_i->map_size)
		return (-1);
	if (map[p_i] == target)
		return (p_i);
	if (map[p_i] == '1')
		return (-1);
	map[p_i] = '1';
	target_i = dfs(map, p_i + 1, target, m_i);
	if (target_i != -1)
		return (target_i);
	target_i = dfs(map, p_i - 1, target, m_i);
	if (target_i != -1)
		return (target_i);
	target_i = dfs(map, p_i + m_i->width, target, m_i);
	if (target_i != -1)
		return (target_i);
	target_i = dfs(map, p_i - m_i->width, target, m_i);
	if (target_i != -1)
		return (target_i);
	return (-1);
}
