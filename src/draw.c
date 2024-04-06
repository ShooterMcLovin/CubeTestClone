#include "Cub3D.h"


void	draw_line(t_player *player, int side, int drawStart, int drawEnd, int x)
{
	t_data		*data;
	uint32_t	color;
	// int			y;
	

	data = get_data();
	// y = 0;
	if (data->real_map[player->mapx][player->mapy] == '1')
		color = ft_pixel(0, 255, 0, 255);
	if (data->real_map[player->mapx][player->mapy] == 'N')
		player->data->real_map[player->mapx][player->mapy] = '0';
	if (side == 1)
	{
		color = color / 2;
	}
	// y = drawStart;
		// player->p_image = mlx_texture_to_image(player->mlx,&player->wall->texture);
	int rP = 255;
	int gP = 0;
	int bP = 0;
	uint32_t clr = ft_pixel(rP, gP, bP, 255);
	for(int y = drawStart; y < drawEnd; y++)
      {
	
			// clr = ft_pixel(rP % -rP, gP % -gP, bP % -gP, 255);
		
		mlx_put_pixel(player->p_image,x,y, color);
	// if (x % 100 == 0)
	// 	mlx_put_pixel(player->p_image,x,y, clr);
	// if (y % 100 == 0)
	// 	mlx_put_pixel(player->p_image,x,y, clr);
		// printf("%x\n", color);

		// mlx_image_to_window(player->mlx,player->wall_im,x,drawStart);

        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        // int texY = (int)texPos & (texHeight - 1);
        // texPos += get_step();
        // uint32_t color = texture[texNum][texHeight * texY + texX];
        // //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        // if(side == 1) color = (color >> 1) & 8355711;
        // buffer[y][x] = color;
      }
	mlx_put_pixel(player->p_image,x,drawStart, clr);
	mlx_put_pixel(player->p_image,x,drawEnd, clr);
	// mlx_put_pixel(player->p_image,x,x, clr);
	// mlx_put_pixel(player->p_image,x,x, clr);
	// mlx_put_pixel(player->p_image,x,x, clr);

	}


