/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:13 by macos             #+#    #+#             */
/*   Updated: 2023/01/16 13:52:23 by bsamli           ###   ########.fr       */
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
			ft_printf("Left wall error");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->mat_x)
	{
		if (data->map[0][i] != '1')
		{
			ft_printf("Top wall error");
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
			ft_printf("Right wall error");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < data->mat_x)
	{
		if (data->map[data->mat_y - 1][i] != '1')
		{
			ft_printf("Under wall error");
			exit(1);
		}
		i++;
	}
}

void	playable_control(t_data *data)
{
	if (data->collectnum < 1 || data->exit != 1)
	{
		ft_printf("Not playable");
		exit(1);
	}
}
