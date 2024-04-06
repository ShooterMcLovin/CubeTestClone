#include "Cub3D.h"

void	move(void *param)
{
	t_player	*player;

	player = param;
	player->frameTime = (player->time - player->oldTime) / 1000.0;
	player->moveSpeed = player->frameTime * 5.0;
	player->rot_speed = player->frameTime * 3.0;
	// player->moveSpeed = 0.25;
	// player->rot_speed = 0.05;
	if (mlx_is_key_down(player->mlx, MLX_KEY_W) || mlx_is_key_down(player->mlx,
			MLX_KEY_UP))
		move_fwd(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_S) || mlx_is_key_down(player->mlx,
			MLX_KEY_DOWN))
		move_bkwd(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
		move_right(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
		rotate_east(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
		move_left(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
		rotate_west(player);
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		exit(0);
	mlx_image_to_window(player->mlx, player->p_image, 0, 0);
	player->p_image->count = 1;
}
