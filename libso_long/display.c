/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:25:38 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:13:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_img(t_mlx *mlx, char object, int x, int y)
{
	if (object == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall, y, x);
	else if (object == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, y, x);
	else if (object == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collation, y, x);
	else if (object == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, y, x);
	else if (object == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ground, y, x);
}

void	display_map(t_mlx *mlx, int width, int height, int flag)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			display_img(mlx, '0', y * 64, x * 64);
			if (mlx->map->map[y * width + x] == '1')
				display_img(mlx, '1', y * 64, x * 64);
			else if (mlx->map->map[y * width + x] == 'E' && flag == 0)
			{
				display_img(mlx, 'E', y * 64, x * 64);
				display_img(mlx, 'P', y * 64, x * 64);
			}
			else if (mlx->map->map[y * width + x] == 'E')
				display_img(mlx, 'E', y * 64, x * 64);
			else if (mlx->map->map[y * width + x] == 'C')
				display_img(mlx, 'C', y * 64, x * 64);
			else if (mlx->map->map[y * width + x] == 'P' && flag != 0)
				display_img(mlx, 'P', y * 64, x * 64);
		}
	}
}
