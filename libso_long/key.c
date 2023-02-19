/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:30:21 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:14:35 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	player_index_for_key(t_mlx **mlx, char key)
{
	int	old_index;
	int	new_index;
	int	width;

	width = (*mlx)->map->width;
	old_index = (*mlx)->map->player_index;
	new_index = 0;
	if (key == 'w')
		new_index = old_index - width;
	else if (key == 'a')
		new_index = old_index - 1;
	else if (key == 's')
		new_index = old_index + width;
	else if (key == 'd')
		new_index = old_index + 1;
	return (new_index);
}

static void	move_player(t_mlx **mlx, char direction)
{
	int	new_index;

	new_index = player_index_for_key(mlx, direction);
	if ((*mlx)->map->map[new_index] == '1')
		return ;
	else if (new_index == (*mlx)->map->exit_index \
	&& (*mlx)->map->collation_count == 0)
		exit(0);
	else if ((*mlx)->map->map[new_index] == 'C')
		(*mlx)->map->collation_count--;
	ft_printf("count : %d\n", (*mlx)->move_count);
	(*mlx)->move_count++;
	(*mlx)->map->map[new_index] = 'P';
	(*mlx)->map->map[(*mlx)->map->player_index] = '0';
	(*mlx)->map->map[(*mlx)->map->exit_index] = 'E';
	(*mlx)->map->player_index = new_index;
	mlx_clear_window((*mlx)->mlx, (*mlx)->win);
	display_map(*mlx, (*mlx)->map->width, (*mlx)->map->map_size / \
	(*mlx)->map->width, (*mlx)->map->exit_index - new_index);
}

int	key_press(int key, t_mlx **mlx)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		move_player(mlx, 'w');
	else if (key == KEY_A)
		move_player(mlx, 'a');
	else if (key == KEY_S)
		move_player(mlx, 's');
	else if (key == KEY_D)
		move_player(mlx, 'd');
	return (0);
}

int	exit_game(t_mlx **mlx)
{
	free((*mlx)->map->map);
	free((*mlx)->map);
	free(*mlx);
	exit(0);
}
