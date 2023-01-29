/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:34:22 by mkarakul          #+#    #+#             */
/*   Updated: 2023/01/29 18:28:58 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	//char	**map;
	t_param	param;
	int width = 0;
	int height = 0;

	if (argc == 2)
	{
		if(map_name_checker(argv[1]) == 0 /* && map_read_checher() */)
		{
			param.mlx = mlx_init();
			param.win = mlx_new_window(param.mlx, 1080, 1080, "so_long");
			mlx_key_hook(param.win, move_change, &param);
			param.player = mlx_xpm_file_to_image(param.mlx, PLYR, &width, &height);
			param.block = mlx_xpm_file_to_image(param.mlx, BLC, &width, &height);
			param.ground = mlx_xpm_file_to_image(param.mlx, GR, &width, &height);
			map_put(&param);
			mlx_string_put(param.mlx, param.win, 4, 10, 0x00FFFFFF, "Adim sayisi: ");
			mlx_loop(param.mlx);
			return (0);
		}
		else
			write(1, "Hatalı map uzantısı!\n", 25);
		return (1);
	}
	else
		write(1, "Hata! Yanlış kullanım!\n", 27);
	return (0);
}
