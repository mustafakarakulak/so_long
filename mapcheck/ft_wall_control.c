/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:13 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/04 14:04:45 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	top_left_wall_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mat_y)
	{
		if (data->map[i][0] != '1')
		{
			ft_printf("Sol duvarda hata var!");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->mat_x)
	{
		if (data->map[0][i] != '1')
		{
			ft_printf("Üst duvarda hata var!");
			exit(1);
		}
		i++;
	}
}

void	right_bottom_wall_control(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mat_y)
	{
		if (data->map[i][data->mat_x - 1] != '1')
		{
			ft_printf("Sağ duvarda hata var!");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->mat_x)
	{
		if (data->map[data->mat_y - 1][i] != '1')
		{
			ft_printf("Alt duvarda hata var!");
			exit(1);
		}
		i++;
	}
}

void	playable_control(t_data *data)
{
	if (data->collectnum < 1 || data->exit != 1)
	{
		ft_printf("Harita oynanabilir değil!");
		exit(1);
	}
}
