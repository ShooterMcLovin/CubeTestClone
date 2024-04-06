#include "Cub3D.h"

void	check_hit(t_player *player, t_frame *frame)
{
	while (frame->hit == 0)
	{
		if (frame->sideDistX < frame->sideDistY)
		{
			frame->sideDistX += frame->deltaDistX;
			player->mapx += frame->stepX;
			frame->side = 0;
		}
		else
		{
			frame->sideDistY += frame->deltaDistY;
			player->mapy += frame->stepY;
			frame->side = 1;
		}
		if (player->data->real_map[player->mapx][player->mapy] > '0')
			frame->hit = 1;
	}
}

void	get_step(t_player *player, t_frame *frame)
{
	if (frame->rayDirX < 0)
	{
		frame->stepX = -1;
		frame->sideDistX = (player->posX - player->mapx) * frame->deltaDistX;
	}
	else
	{
		frame->stepX = 1;
		frame->sideDistX = (player->mapx + 1.0 - player->posX)
			* frame->deltaDistX;
	}
	if (frame->rayDirY < 0)
	{
		frame->stepY = -1;
		frame->sideDistY = (player->posY - player->mapy) * frame->deltaDistY;
	}
	else
	{
		frame->stepY = 1;
		frame->sideDistY = (player->mapy + 1.0 - player->posY)
			* frame->deltaDistY;
	}
}

void	init_frame(t_player *player, t_frame *frame)
{
	frame->cameraX = 2 * frame->x / (double)WIDTH - 1;
	frame->rayDirX = player->dirX + player->planeX * frame->cameraX;
	frame->rayDirY = player->dirY + player->planeY * frame->cameraX;
	player->mapx = (int)player->posX;
	player->mapy = (int)player->posY;
	frame->deltaDistX = fabs(1 / frame->rayDirX);
	frame->deltaDistY = fabs(1 / frame->rayDirY);
	frame->hit = 0;
	get_step(player, frame);
	check_hit(player, frame);
}

void	game(void *param)
{
	t_player	*player;
	t_frame		frame;

	player = param;
	reset_img(player->p_image);
	frame.x = 0;
	while (frame.x < WIDTH)
	{
		init_frame(player, &frame);
		if (frame.side == 0)
			frame.perpWallDist = (frame.sideDistX - frame.deltaDistX);
		else
			frame.perpWallDist = (frame.sideDistY - frame.deltaDistY);
		frame.lineHeight = (int)(HEIGHT / frame.perpWallDist);
		frame.drawStart = -frame.lineHeight / 2 + HEIGHT / 2;
		if (frame.drawStart < 0)
			frame.drawStart = 0;
		frame.drawEnd = frame.lineHeight / 2 + HEIGHT / 2;
		if (frame.drawEnd >= HEIGHT)
			frame.drawEnd = HEIGHT - 1;
		draw_line(player, frame.side, frame.drawStart, frame.drawEnd, frame.x);
		
		frame.x++;
	}
	player->oldTime = player->time;
	player->time = get_time();
}
