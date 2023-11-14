/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:07:15 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/12 18:05:00 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	raycasting(t_data *data)
{
posx player position X = 22
posy player position Y = 12
dirX direction of player X = -1
dirY direction of player Y = 0
camplanX camera plane of player X = 0
camplanY camera plane of player Y = 0.66

cframe current frame time = 0
pframe previous frame time = 0

int x = 0
int w = width of screen in pixel

while (x < w)
{

	DDA (Digital Differential Analysis) algrorithm

Calculating the ray position and direction
camX coordinate of camera X on camplanX = 2 * x / w - 1
RayDirX direction of the raycast X = dirX + camplanX * camX
rayDirY direction of the raucast Y = dirY + camplanY * camX
DeltaDistX distance the ray needs to travel from one x-side to the next x-side = abs(1/RayDirX) 
DeltaDistY distance the ray needs to travel from one y-side to the next y-side = abs(1/RayDirY)
(if RayDir* = 0, DeltaDist* = 1e30)

Calculating the direction of steps and distance till next square
stepX direction to step in X
stepY direction to step in Y
they will be either +1 or -1
SideDistX distance from current posX to the next x-side 
SideDistY distance from current posY to the next y-side 
    if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }

hit variable if a wall is hit 
side variable to know which side of the wall was hit

	    while (hit == 0)
      {
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        if ("map.cub"[mapX][mapY] > 0) hit = 1;
      } 

	Calculate distance projected on camera via camera plan and not player to avoid fisheye effect

	PerpWallDist perpendicular distance from camera plan to wall
	if (side == 0)
		PerpWallDist = (SideDistX - DeltaDistX)
	else
		PerpWallDist = (SideDistY - DeltaDistX)
	

	Calculate the height of the line to draw on screen 

	h the height of the screen in pixel
	LineHeight = (h / PerpWallDist)
	DrawStart = -LineGeight / 2 + h / 2 if < 0 = 0
	DrawEnd = LineHeight / 2 + h / 2 if >= h = h - 1

	

}