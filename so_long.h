#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <unistd.h>

#define PLYR "xpms/player.xpm"
#define GR "xpms/ground.xpm"
#define BLC "xpms/block.xpm"
#define COIN "xpms/coin.xpm"
#define DOR "xpms/exit.xpm"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct
{
	void *mlx;
	void *win;
	int *ground;
	int *block;
	int *player;
	int *coin;
	int *exit;
} t_param;


//functions
int move_change(int key, t_param *param);
int render_next_frame(void *YourStruct);
int map_name_checker(char *argv);
int ft_strlen(char *str);
int map_put(t_param *param);
int map_put2(t_param *param);
int move_right(t_param *param);
#endif
