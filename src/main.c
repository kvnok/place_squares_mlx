#include "stuff.h"

int		map_height(char **arr)
{
	int i;

	i = 0;
	while(arr[i] != NULL)
	{
		i++;
	}
	return i;
}

/*
listening for key input
*/
void	key_activation(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			clean_memory(data, 2);
	}
	//there should be a way for this to be more smooth
	//like a way for the player to start moving straight away
	//no delay, nothing, nil, nada
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->image_player->instances[0].y -= (TS / 4);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->image_player->instances[0].x -= (TS / 4);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->image_player->instances[0].y += (TS / 4);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->image_player->instances[0].x += (TS / 4);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		return 1;
	if (map_parser(argv[1], &data) == 1)
	{
		printf("map_parser ERROR\n");
		return 1;
	}
	data.map_w = int_strlen(data.map[0]);
	data.map_h = map_height(data.map);
	data.mlx = mlx_init(data.map_w * TS, data.map_h * TS, "2D_GAME", false);
	if (!data.mlx)
		clean_memory(&data, 0);
	load_pngs(&data);
	convert_textures(&data);
	create_map_images(&data);
	mlx_key_hook(data.mlx, &key_activation, &data);
	mlx_loop(data.mlx);
	clean_memory(&data, 2);
	return 0;
}

/*
change TS to 32 and pngs to 32 aswell
*/
