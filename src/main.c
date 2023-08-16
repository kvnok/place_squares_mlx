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

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		return 1;
	map_parser(argv[1], &data.map);
	data.map_w = int_strlen(data.map[0]);
	data.map_h = map_height(data.map);
	data.mlx = mlx_init(data.map_w * TS, data.map_h * TS, "2D_GAME", false);
	if (!data.mlx)
		clean_memory(&data, 0);
	load_pngs(&data);
	convert_textures(&data);
	create_map_images(&data);
	// mlx_key_hook(data.mlx, &key_activation, &data);
	mlx_loop(data.mlx);
	clean_memory(&data, 2);
	return 0;
}

/*
change TS to 32 and pngs to 32 aswell
put print statements to DEBUG
MLX42: LodePNG: failed to open file for reading
*/
