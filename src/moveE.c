#include "Cub3D.h"

void	rotate_east(t_player *player)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dirX;
	player->dirX = player->dirX * cos(-player->rot_speed) - player->dirY
		* sin(-player->rot_speed);
	player->dirY = old_dirx * sin(-player->rot_speed) + player->dirY
		* cos(-player->rot_speed);
	old_planex = player->planeX;
	player->planeX = player->planeX * cos(-player->rot_speed) - player->planeY
		* sin(-player->rot_speed);
	player->planeY = old_planex * sin(-player->rot_speed) + player->planeY
		* cos(-player->rot_speed);
}

void	move_right(t_player *player)
{
	t_data	*data;

	data = get_data();
	if (data->real_map[(int)(player->posX + player->dirY
			* player->moveSpeed)][(int)(player->posY)] == '0')
		player->posX += player->dirY * player->moveSpeed;
	if (data->real_map[(int)(player->posX)][(int)(player->posY - player->dirX
			* player->moveSpeed)] == '0')
		player->posY -= player->dirX * player->moveSpeed;
}
