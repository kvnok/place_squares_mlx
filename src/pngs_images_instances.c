/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pngs_images_instances.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/09 17:35:59 by kkroon        #+#    #+#                 */
/*   Updated: 2023/08/18 19:04:14 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stuff.h"

//try to load all the png files and store the 'textures'
void	load_pngs(t_data *data)
{
	data->texture_floor = mlx_load_png("./pngs/floor.png");
	if (!data->texture_floor)
		clean_memory(data, 2);
	data->texture_wall = mlx_load_png("./pngs/wall.png");
	if (!data->texture_wall)
		clean_memory(data, 2);
	data->texture_player = mlx_load_png("./pngs/player.png");
	if (!data->texture_player)
		clean_memory(data, 2);
}

//make images from textures
void	convert_textures(t_data *data)
{
	data->image_floor = mlx_texture_to_image(data->mlx, data->texture_floor);
	if (!data->image_floor)
		clean_memory(data, 2);
	data->image_wall = mlx_texture_to_image(data->mlx, data->texture_wall);
	if (!data->image_wall)
		clean_memory(data, 2);
	data->image_player = mlx_texture_to_image(data->mlx, data->texture_player);
	if (!data->image_player)
		clean_memory(data, 2);
}

//creating new instances
void	helper_image_creator(t_data *data, int y, int x)
{
	if ((mlx_image_to_window(data->mlx, data->image_floor, x * TS, y * TS)) < 0)
		clean_memory(data, 2);
	if (data->map[y][x] == '1')
		if ((mlx_image_to_window(data->mlx, data->image_wall, x * TS, y * TS)) < 0)
			clean_memory(data, 2);
}

//looping through map
void	create_map_images(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			helper_image_creator(data, y, x);
			if (data->map[y][x] == 'P')
			{
				data->p_y = y;
				data->p_x = x;
			}
			x++;
		}
		y++;
	}
	if ((mlx_image_to_window(data->mlx, data->image_player, data->p_x * TS, data->p_y * TS)) < 0)
		clean_memory(data, 2);
}
