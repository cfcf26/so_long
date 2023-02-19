/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_into_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:51:10 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:14:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	convert_newline_to_null(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		ft_error("Error: Invalid string format. \
String must not contain newline characters.");
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (i - 1);
}

void	read_map_into_array(char *file_name, t_map *map_info)
{
	const int	fd = open(file_name, O_RDONLY);
	int			width;
	char		*line;
	char		*temp;

	if (fd == -1)
		ft_error("Error: Failed to open file.");
	map_info->map = get_next_line(fd);
	if (map_info->map == NULL)
		ft_error("Error: Failed to read file.");
	width = ft_strlen(map_info->map) - 1;
	map_info->map[width] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((convert_newline_to_null(line) != width))
			ft_error("Error: Invalid string format. \
String must not contain newline characters.");
		temp = map_info->map;
		map_info->map = ft_strjoin_so_long(temp, line);
	}
	close(fd);
	map_info->width = width;
	map_info->map_size = ft_strlen(map_info->map);
}
