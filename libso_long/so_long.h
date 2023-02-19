/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:45:29 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/13 10:41:38 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../libprintf/ft_printf.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ENTER 36

typedef enum e_bool {false, true}	t_bool;
typedef struct s_map
{
	char	*map;
	int		map_size;
	int		width;
	int		collation_count;
	int		player_index;
	int		exit_index;
}	t_map;

typedef struct s_mlx
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*ground;
	void	*wall;
	void	*player;
	void	*collation;
	void	*exit;
	int		move_count;
}	t_mlx;

void	*ft_error(const char *call_function_name);
int		is_valid_file_extension(char *file_name);
char	*ft_strjoin_so_long(char *map, char *line);
void	read_map_into_array(char *file_name, t_map *map_info);
void	validate_map(t_map *map_info);
t_map	*init_map(int argc, char *argv[]);
t_mlx	*init_mlx(t_map **map);
int		dfs(char *map, int p_i, char target, t_map *m_i);
void	display_map(t_mlx *mlx, int width, int height, int flag);
int		key_press(int key, t_mlx **mlx);
int		exit_game(t_mlx **mlx);
void	so_long(int argc, char *argv[]);
#endif
