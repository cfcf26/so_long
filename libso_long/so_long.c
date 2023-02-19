/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:36:17 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:14:57 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int argc, char *argv[])
{
	t_map	*map;
	t_mlx	*mlx;

	map = init_map(argc, argv);
	mlx = init_mlx(&map);
	display_map(mlx, mlx->map->width, mlx->map->map_size / mlx->map->width, \
	1);
	mlx_hook(mlx->win, X_EVENT_KEY_RELEASE, 0, &key_press, &mlx);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &exit_game, &mlx);
	mlx_loop(mlx->mlx);
}
