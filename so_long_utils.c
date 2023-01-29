/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:06:45 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/29 20:09:06 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	map_read_checher()
{
	
} */

int move_change(int key, t_param *param)
{
	printf("%d | ", key);
	if (key == 53)
	{
		write(1, "Oyun başarıyla kapatıldı!\n", 31);
		exit(0);
	}
	else if (key == 13)
	{
		mlx_clear_window((*param).mlx, (*param).win);
		map_put2(param);
	}
	else if (key == 0)
	{
		mlx_clear_window((*param).mlx, (*param).win);
		map_put(param);
	}
	else if (key == 1)
	{
		mlx_clear_window((*param).mlx, (*param).win);
		map_put(param);
	}
	else if (key == 2)
	{
		mlx_clear_window((*param).mlx, (*param).win);
		move_right(param);
	}
	return (0);
}

int render_next_frame(void *YourStruct)
{
	return ((int)YourStruct);
}
