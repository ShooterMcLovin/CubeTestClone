
#include "Cub3D.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
double	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void load_images(t_player * player)
{
	player->wall = mlx_load_xpm42("./pics/wood.xpm42");
	player->wall2 = mlx_load_xpm42("./pics/redbrick.xpm42");
	if (!player->wall || !player->wall2)
		error();

	// Convert texture to a displayable image
	player->wall_im = mlx_texture_to_image(player->mlx, &player->wall->texture);
	player->wall2_im = mlx_texture_to_image(player->mlx, &player->wall2->texture);
	if (!player->wall_im || !player->wall2_im )
		error();
}

void initPlayerDirection(t_player *player){
	if (player->startDirection == 'N')
	{
	player->dirX = -1;            
	player->dirY = 0;    
	player->planeX = 0;
	player->planeY = 0.66;
	}
	else if (player->startDirection == 'S'){
	player->dirX = 1;            
	player->dirY = 0; 
	player->planeX = 0; 
	player->planeY = -0.66;
	}
	else if (player->startDirection == 'E'){
	player->dirX = 0;      
	player->dirY = 1;
	player->planeX = 0.66;
	player->planeY = 0;
	}
	else if (player->startDirection == 'W'){
	player->dirX = 0;
	player->dirY = -1;
	player->planeX = -0.66;
	player->planeY = 0;
	}
}

void	init_player(t_player *player)
{
	t_data	*data;
	data = get_data();
	player->startDirection = 'N';///////////
	initPlayerDirection(player);
	player->posX = data->playerj + 0.5; 
	player->posY = data->playeri + 0.5; 
	player->time = 0;
	player->oldTime = 0;
	player->frameTime = 0;
	player->moveSpeed = 0;
	player->rot_speed = 0;
	load_images(player);
}

void	reset_img(mlx_image_t *img)
{
	int x = 0;
	int y = 0;
	t_data *data;
	data = get_data();
	while(x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT){
			if (y < HEIGHT / 2)
				mlx_put_pixel(img, x, y, ft_pixel(data->C_R, data->C_G, data->C_B, 255));
			else
				mlx_put_pixel(img, x, y, ft_pixel(data->F_R, data->F_G, data->F_B, 255));
			y++;
		}
		x++;
	}
}

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		data = ft_calloc(1, sizeof(t_data));
		return (data);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_player	P1;

	data = get_data();
	if (argc != 2)
		return  (write(2, "Error\nwrong argc\n", 17) * 0);
	if (chekup_cub(argv[1]) == 0)
		return (0);
	extract_map(argv[1], 0, 0);
	if (ft_mapchekup(data->map) == 0)
		return (0);
	P1.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	init_player(&P1);
	P1.data = data;
	P1.p_image = mlx_new_image(P1.mlx, WIDTH, HEIGHT);
	mlx_loop_hook(P1.mlx, move, &P1);
	mlx_loop_hook(P1.mlx, game, &P1);
	mlx_loop(P1.mlx);
	mlx_terminate(P1.mlx);
	//free
	return (EXIT_SUCCESS);
}
