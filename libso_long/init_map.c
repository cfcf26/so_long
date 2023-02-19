/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:03:38 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:14:06 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_valid_argument(int argc, char *argv[])
{
	if (argc != 2)
		ft_error("The number of arguments is not insffucient.");
	if (is_valid_file_extension(argv[1]))
		ft_error("The file extension is not valid.");
}

t_map	*init_map(int argc, char *argv[])
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	is_valid_argument(argc, argv);
	read_map_into_array(argv[1], map);
	validate_map(map);
	return (map);
}
