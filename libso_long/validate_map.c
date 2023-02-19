/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:18:26 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:15:11 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_object(char *map, char target)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

static void	validate_map_path(t_map *map_info)
{
	char			*map;
	char			*temp;
	int				target_i;
	int				player_i;
	const int		collation_count_backup = map_info->collation_count;

	player_i = map_info->player_index;
	map = ft_strdup(map_info->map);
	while (map_info->collation_count > 0)
	{
		temp = ft_strdup(map);
		target_i = dfs(temp, player_i, 'C', map_info);
		if (target_i == -1)
			ft_error("There is no path to collect all collectibles.");
		map[target_i] = '0';
		free(temp);
		map_info->collation_count--;
	}
	temp = ft_strdup(map);
	target_i = dfs(temp, player_i, 'E', map_info);
	if (target_i == -1)
		ft_error("There is no path to exit.");
	free(temp);
	free(map);
	map_info->collation_count = collation_count_backup;
}

static void	validate_walled_map(t_map *map_info)
{
	int			i;
	const int	width = map_info->width;
	const int	map_size = map_info->map_size;

	i = 0;
	while (map_info->map[i])
	{
		if (i < width || i >= map_size - width)
		{
			if (map_info->map[i] != '1')
				ft_error("Map must be walled.");
		}
		else if (i % width == 0 || \
		i % width == width - 1)
		{
			if (map_info->map[i] != '1')
				ft_error("Map must be walled.");
		}
		i++;
	}
}

static void	validate_map_rules(t_map *map_info)
{
	int	i;
	int	player_count;
	int	exit_count;
	int	collation_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	collation_count = 0;
	while (map_info->map[i])
	{
		if (map_info->map[i] == 'P')
			player_count++;
		if (map_info->map[i] == 'E')
			exit_count++;
		if (map_info->map[i] == 'C')
			collation_count++;
		i++;
	}
	if (player_count != 1 || exit_count != 1 || collation_count < 1)
		ft_error("Map must have one player, one exit, \
and at least one collectible.");
	map_info->collation_count = collation_count;
}

void	validate_map(t_map *map_info)
{
	int	i;

	i = 0;
	validate_walled_map(map_info);
	validate_map_rules(map_info);
	while (map_info->map[i])
	{
		if (map_info->map[i] != '0' && map_info->map[i] != '1' && \
		map_info->map[i] != 'P' && map_info->map[i] != 'E' && \
		map_info->map[i] != 'C')
			ft_error("Map must contain only 0, 1, P, E, C.");
		i++;
	}
	map_info->player_index = find_object(map_info->map, 'P');
	map_info->exit_index = find_object(map_info->map, 'E');
	validate_map_path(map_info);
}
