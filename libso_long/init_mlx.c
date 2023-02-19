/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:16:00 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 16:36:15 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*init_mlx(t_map **map)
{
	t_mlx	*mlx;
	int		height;
	int		width;

	mlx = malloc(sizeof(t_mlx));
	mlx->map = (*map);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, (*map)->width * 64, \
	((*map)->map_size / (*map)->width) * 64, "so_long");
	mlx->ground = mlx_xpm_file_to_image(mlx->mlx, "img/ground.xpm", \
	&width, &height);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, "img/wall.xpm", \
	&width, &height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "img/player.xpm", \
	&width, &height);
	mlx->collation = mlx_xpm_file_to_image(mlx->mlx, "img/collation.xpm", \
	&width, &height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "img/door.xpm", \
	&width, &height);
	mlx->move_count = 1;
	return (mlx);
}
