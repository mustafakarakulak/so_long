#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main()
{
	t_param param;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 1024, 768, "Example");

	mlx_key_hook(param.win, close_window, &param);
	mlx_string_put(param.mlx, param.win, 4, 10, 0x00FFFFFF, "Adim sayısı: ");
	mlx_loop(param.mlx);

	return (0);
}
