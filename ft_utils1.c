/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:07:15 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/04 14:07:19 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_check(char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				return ;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	ft_printf("coin yok");
	exit(1);
}

int	map_width(char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j][i])
		i++;
	return (i);
}

int	map_height(char *map[])
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	return (j);
}

int	find_player_x(char *map[])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j][i])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (i);
			i++;
		}
		j++;
	}
	return (0);
}

int	find_player_y(char *map[])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j][i])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}
