#ifndef STUFF_H
# define STUFF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

#define BUFFER_SIZE 100
#define TS 64

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_player;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_player;
	char			**map;
	int				map_w;
	int				map_h;
	int				p_x;
	int				p_y;
	int				player_i;
}	t_data;

//ft_split.c
char	**free_strings(char **strings);
char	**ft_split(char const *s, char c);

//utils.c
int		int_strlen(char *s);
void	*ok_calloc(int count, int size);
void	cleanup(char **line, char **buffer);
void	print_arr(char **arr);

//reading.c
char	*strjoin_free(char **s1, char **s2);
int		reading(int fd, char **buffer, char **line);
int		player_check(t_data *data, char *line);
int		map_parser(char *str, t_data *data);

//cleaning.c
void	free_maps(t_data *data);
void	clean_memory(t_data *data, int flag);

//pngs_images_instances.c
void	load_pngs(t_data *data);
void	convert_textures(t_data *data);
void	helper_image_creator(t_data *data, int y, int x);
void	create_map_images(t_data *data);

#endif
