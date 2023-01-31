/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:45 by macos             #+#    #+#             */
/*   Updated: 2023/01/16 13:49:30 by bsamli           ###   ########.fr       */
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
			ft_printf("Map length error!");
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
				ft_printf("Unreachable coin. Coordinate : x = %d, \
                    y = %d", j, i);
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
		ft_printf("There are exit more than one!");
		exit(1);
	}
}
