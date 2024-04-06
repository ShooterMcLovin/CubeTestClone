#include "Cub3D.h"

void move_fwd(t_player *player)
{
    if(player->data->real_map[(int)(player->posX + player->dirX * player->moveSpeed)][(int)(player->posY)] == '0' || player->data->real_map[(int)(player->posX + player->dirX * player->moveSpeed)][(int)(player->posY)] == 'N') player->posX += player->dirX * player->moveSpeed;
      if(player->data->real_map[(int)(player->posX)][(int)(player->posY + player->dirY * player->moveSpeed)] == '0' || player->data->real_map[(int)(player->posX + player->dirX * player->moveSpeed)][(int)(player->posY)] == 'N') player->posY += player->dirY * player->moveSpeed;
}