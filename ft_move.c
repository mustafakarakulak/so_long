/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:39:16 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/01 23:32:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->position_y - 1][data->position_x] == 'C')
			data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y - 1][data->position_x] = 'P';
	data->position_y--;
	data->player_c = 3;
	data->step++;
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->position_y + 1][data->position_x] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y + 1][data->position_x] = 'P';
	data->position_y++;
	data->player_c = 0;
	data->step++;
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->position_y][data->position_x - 1] == 'C')
			data->coin--;
		data->map[data->position_y][data->position_x] = '0';
		data->map[data->position_y][data->position_x - 1] = 'P';
		data->step++;
		data->player_c = 1;
		data->position_x--;
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->position_y][data->position_x + 1] == 'C')
		data->coin--;
	data->map[data->position_y][data->position_x] = '0';
	data->map[data->position_y][data->position_x + 1] = 'P';
	data->step++;
	data->player_c = 2;
	data->position_x++;
}

void	map_is_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->x[i])
	{
		if (data->x[i + 1] && (data->x[i] == '\n' && data->x[i + 1] == '\n'))
		{
			ft_printf("Boşluk var!");
			exit(1);
		}
		i++;
	}
}
