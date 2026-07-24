/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:00:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render/ray/render_ray.h"
#include "render/math/render_math.h"
#include <math.h>

void	render_ray_init_map(t_ray *ray, const t_player *player)
{
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
}

void	render_ray_delta_dist(t_ray *ray)
{
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir.x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir.y);
}

void	render_ray_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

/*
** EXPLICACIÓ GEOMÈTRICA DE SIDE_DIST (Eix X - Cas Positiu):
**
** Basat en l'equació del raig: P + t * ray_dir
** On:
**   - P (player->x, player->y): Posició inicial del jugador.
**   - t (side_dist): Distància/temps fins a la primera frontera
**                    de la cel·la (tile).
**   - ray_dir: Vector de direcció del raig.
**
** EXEMPLE NUMÈRIC:
**   P = (4.0, 5.0)          -> El jugador està a la cel·la 4 (map_x = 4)
**   ray_dir = (12.0, -3.0)  -> El raig avança cap a la dreta (step_x = 1)
**   Frontera X = 5.0        -> La pròxima cel·la comença a map_x + 1.0 (5.0)
**
** DESENVOLUPAMENT MATEMÀTIC EN L'EIX X:
**   Volem trobar 't' perquè el raig arribi a la frontera (X = 5.0):
**   
**   Frontera = P.x + t * ray_dir.x
**   5.0      = 4.0 + t * 12.0
**   5.0 - 4.0 = 12.0 * t
**   1.0       = 12.0 * t
**   t = 1.0 / 12.0          -> t = 0.0833 (Distància en 't' fins a la frontera)
**
** ABSTRACCIÓ A CODI:
**   t = (Frontera - P.x) / ray_dir.x
**   t = ((map_x + 1.0) - player->x) / ray_dir.x
**
** OPTIMITZACIÓ DDA:
**   Com que prèviament hem definit delta_dist_x = |1.0 / ray_dir.x|,
**   podem substituir la divisió per una multiplicació directa més ràpida:
**
**   side_dist_x = ((map_x + 1.0) - player->x) * delta_dist_x
*/

/*
** GEOMETRIC EXPLANATION OF SIDE_DIST (X-Axis - Positive Case):
**
** Based on the ray equation: P + t * ray_dir
** Where:
**   - P (player->x, player->y): Player's starting position.
**   - t (side_dist): Distance/time to the first tile boundary.
**   - ray_dir: Ray direction vector.
**
** NUMERICAL EXAMPLE:
**   P = (4.0, 5.0)          -> Player is inside tile 4 (map_x = 4)
**   ray_dir = (12.0, -3.0)  -> Ray travels to the right (step_x = 1)
**   Boundary X = 5.0        -> The next tile begins at map_x + 1.0 (5.0)
**
** MATHEMATICAL DERIVATION ON THE X-AXIS:
**   We want to find 't' so that the ray reaches the boundary (X = 5.0):
**   
**   Boundary = P.x + t * ray_dir.x
**   5.0      = 4.0 + t * 12.0
**   5.0 - 4.0 = 12.0 * t
**   1.0       = 12.0 * t
**   t = 1.0 / 12.0          -> t = 0.0833 (Distance in 't' to the boundary)
**
** ABSTRACTION TO CODE:
**   t = (Boundary - P.x) / ray_dir.x
**   t = ((map_x + 1.0) - player->x) / ray_dir.x
**
** DDA OPTIMIZATION:
**   Since we previously defined delta_dist_x = |1.0 / ray_dir.x|,
**   we can replace the division with a faster direct multiplication:
**
**   side_dist_x = ((map_x + 1.0) - player->x) * delta_dist_x
*/
void	render_ray_side_dist(t_ray *ray, const t_player *player)
{
	if (ray->step_x < 0)
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	if (ray->step_y < 0)
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
}
