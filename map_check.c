#include "so_long.h"

int	map_name_checker(char *argv)
{
	int	i = ft_strlen(argv);

	if (argv[i - 1] != 'r')
		return(1);
	else if (argv[i - 2] != 'e')
		return (1);
	else if (argv[i - 3] != 'b')
		return (1);
	else if (argv[i - 4] != '.')
		return(1);
	else if (argv[i - 5] == '\0')
		return(1);
	else
		return(0);
}

int	map_put(t_param *param)
{
	int x = 0;
	int y = 0;
	int	i = 0;
	int k = 0;

while(k <= 6)
{
	while(i <= 12)
	{
		mlx_put_image_to_window(param->mlx, param->win, param->block, x, y);
		i++;
		x += 64;
	}
	x = 0;
	y += 64;
	k++;
	i = 0;
	mlx_put_image_to_window(param->mlx, param->win, param->ground, x, y);
	mlx_put_image_to_window(param->mlx, param->win, param->player, 16, 0);
}
	mlx_string_put(param->mlx, param->win, 4, 10, 0x00FFFFFF, "Adim sayisi: ");
	return (0);		
}

int map_put2(t_param *param)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int k = 0;

	while (k <= 6)
	{
	while (i <= 12)
	{
		mlx_put_image_to_window(param->mlx, param->win, param->ground, x, y);
		i++;
		x += 64;
	}
	x = 0;
	y += 64;
	k++;
	i = 0;
	mlx_put_image_to_window(param->mlx, param->win, param->block, x, y);
	}
	mlx_string_put(param->mlx, param->win, 4, 10, 0x00FFFFFF, "Adim sayisi: ");
	return (0);
}

int	move_right(t_param *param)
{
	static int x = 0;
	mlx_clear_window((*param).mlx, (*param).win);
	mlx_put_image_to_window(param->mlx, param->win, param->player, x + 80, 0);
	return(0);
}