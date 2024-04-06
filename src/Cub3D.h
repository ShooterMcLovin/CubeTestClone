
#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define WIDTH 750
# define HEIGHT 500
# define MSPEED 100
#define texWidth 64
#define texHeight 64

typedef struct s_player
{
	mlx_t			*mlx;
	mlx_image_t		*p_image;
	char			startDirection;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	int				mapx;
	int				mapy;

	double			time;
	double			oldTime;
	double			planeX;
	double			planeY;

	double			frameTime;
	double			moveSpeed;
	double			rot_speed;

	int				**map;
	xpm_t			*wall;
	mlx_image_t		*wall_im;
	xpm_t			*wall2;
	mlx_image_t		*wall2_im;
	struct s_data	*data;
	int texture[2];

}					t_player;

typedef struct s_frame
{
	int				x;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	double			cameraX;
	int				hit;
	int				side;

}					t_frame;

typedef struct s_point
{
	int				y;
	int				x;

}					t_point;

typedef struct s_data
{
	char			**map;
	char			**real_map;
	int				playeri;
	int				playerj;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*F;
	char			*C;
	unsigned		C_R;
	unsigned		C_G;
	unsigned		C_B;
	unsigned		F_R;
	unsigned		F_G;
	unsigned		F_B;
	int				maxj;
	char			**area;
	char			*line;

	int				start_map;

}					t_data;

void				free_map(char **map);
int					chekup_character(char **map);
int					ft_mapchekup(char **map);
char				**make_area(char **zone, int _x);
int					flood_fill(char **tab, t_point size, t_point begin);
int					contchar(char **map, int np);
int					flood_fill_main(char **map, int i, int j);
char				*ft_strjoing(char *s1, char *s2);
char				*ft_freestash(char *stash);
char				*ft_get_line(char *stash);
char				*ft_read(int fd, char *stash);
char				*get_next_line(int fd);
int					ft_strlen(char *str);
int					ft_strlenj(char **str);
char				*ft_strchr(char *str, int c);
void				*ft_calloc(size_t nitems, size_t size);
void				*ft_free(char *str);
char				**extract_map(char *mapname, int i, int j);
int					chekup_cub(char *namemap);
int					found_player(char **map, int *npj, int *npi);
t_data				*get_data(void);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				print_maptest(char **map);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2);
int					extract_rgb(void);
int					chekup_f_and_c(void);
int					chekup_rgb(void);
int					chekup_and_extract_texture(char **map);

void				draw_line(t_player *player, int side, int drawStart,
						int drawEnd, int x);
void				game(void *param);
double				get_time(void);
int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void				reset_img(mlx_image_t *img);
void				move(void *param);
void				rotate_east(t_player *player);
void				move_bkwd(t_player *player);
void				move_fwd(t_player *player);
void				rotate_west(t_player *player);
void				move_left(t_player *player);
void				move_right(t_player *player);

void				error(void);
#endif // CUB3D_H

/*

*/