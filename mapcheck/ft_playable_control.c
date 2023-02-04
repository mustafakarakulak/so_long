/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:45 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/04 14:04:52 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	line_control(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (data->map[0][j])
		j++;
	flag = j;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != flag)
		{
			ft_printf("Harita uzunluk hatası!");
			exit(1);
		}
		i++;
	}
}

void	collectable_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C' && data->controlmap[i][j] != '.')
			{
				ft_printf("Koordinatı: x = %d, y = %d", i + 1, j + 1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	door_control(t_data *data)
{
	if (data->exit > 1)
	{
		ft_printf("Birden fazla çıkış var!");
		exit(1);
	}
/* 	else if (data->position_x + 1 || data->position_x - 1 == 'E')
	{
		ft_printf("Kapı yüzünden token'a ulaşılamıyor\n");
		exit(1);
	}
	else if (data->position_y + 1 || data->position_y - 1 == 'E')
	{
		ft_printf("Kapı yüzünden token'a ulaşılamıyor\n");
		exit(1);
	} */
}
