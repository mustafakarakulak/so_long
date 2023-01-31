/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_map_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamli <bsamli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:40:38 by macos             #+#    #+#             */
/*   Updated: 2023/01/20 18:29:45 by bsamli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	recursive_control(t_data *data, int x, int y)
{
	start_control(data, x, y);
	second_control(data, x, y);
	third_control(data, x, y);
	fourth_control(data, x, y);
}

void	start_control(t_data *data, int x, int y)
{
	if (data->controlmap[y + 1][x] != '.' &&
		data->controlmap[y + 1][x] != '1')
	{
		y++;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, x, y);
		y--;
	}
}

void	second_control(t_data *data, int x, int y)
{
	if (data->controlmap[y][x + 1] != '.' &&
		data->controlmap[y][x + 1] != '1')
	{
		x++;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, x, y);
		x--;
	}
}

void	third_control(t_data *data, int x, int y)
{
	if (data->controlmap[y - 1][x] != '.' &&
		data->controlmap[y - 1][x] != '1')
	{
		y--;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, x, y);
		y++;
	}
}

void	fourth_control(t_data *data, int x, int y)
{
	if (data->controlmap[y][x - 1] != '.' &&
		data->controlmap[y][x - 1] != '1')
	{
		x--;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, x, y);
		x++;
	}
}
