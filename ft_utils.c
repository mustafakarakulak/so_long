/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:02:48 by bsamli            #+#    #+#             */
/*   Updated: 2023/01/31 16:25:57 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int key, t_data *data)
{
	(void)data;
	if (key == 53)
		exit(0);
	return (0);
}

int	mouse(int button, int x, int y, t_data *data)
{
	int	z;

	z = x + y + button;
	(void)z;
	(void)data;
	return (0);
}

void	can_go_exit(t_data *data)
{
	char	*coin;
	char	*step;

	step = ft_itoa(data->step);
	coin = ft_itoa(data->coin);
	mlx_string_put(data->mlx, data->mlx_window, 5, 15, 00000000,
		"Adim Sayisi: ");
	mlx_string_put(data->mlx, data->mlx_window, 92, 15, 00000000, step);
	mlx_string_put(data->mlx, data->mlx_window, 5, 35, 00000000,
		"Gul Sayisi: ");
	mlx_string_put(data->mlx, data->mlx_window, 92, 35, 00000000, coin);
	free(coin);
	if (data->coin == 0)
	{
		mlx_string_put(data->mlx, data->mlx_window, 5, 55, 0xFF0000,
			"Oyunu tamamlamak icin sevgiline gitmelisin.");
	}
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->controlmap[i])
	{
		j = 0;
		while (data->controlmap[i][j])
		{
			if (data->controlmap[i][j] == 'P')
			{
				recursive_control(data, j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_keyboard(int keyhook, t_data *data)
{
	ft_putimages(data);
	if (keyhook == 53)
	{
		ft_printf("Oyun başarıyla kapatıldı!");
		exit(0);
	}
	if (data->coin == 0 && (((keyhook == 2 || keyhook == 124)
				&& data->map[data->position_y][data->position_x + 1] == 'E') \
			|| ((keyhook == 125 || keyhook == 1) && data->map[data->position_y
				+ 1][data->position_x] == 'E') ||
					((keyhook == 0 || keyhook == 123)
				&& data->map[data->position_y][data->position_x - 1] == 'E')
			|| ((keyhook == 13 || keyhook == 126) && data->map[data->position_y
				- 1][data->position_x] == 'E')))
	{
		ft_printf("Adım Sayısı: %d\n", data->step + 1);
		ft_printf("Tebrikler! Sevgiline ulaştın!\n");
		free(data->img);
		exit(1);
	}
	ft_key_hook(keyhook, data);
	hookles(data);
	return (0);
}
