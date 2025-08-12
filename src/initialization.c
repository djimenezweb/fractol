/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:55:02 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 13:18:05 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	initialize(t_config *c)
{
	c->mlx_ptr = mlx_init();
	if (!c->mlx_ptr)
		free_and_exit(c, 1);
	c->win_ptr = mlx_new_window(c->mlx_ptr, WIDTH, HEIGHT, "HD test");
	if (!c->win_ptr)
		free_and_exit(c, 1);
}

void	init_configuration(t_config *c)
{
	c->img = mlx_new_image(c->mlx_ptr, WIDTH, HEIGHT);
	c->addr = mlx_get_data_addr(c->img, &c->bits_per_pixel, &c->line_length, &c->endian);
	c->ratio = WIDTH / HEIGHT;
	c->x_max = 4;
	c->x_min = -c->x_max;
	c->y_max = (c->x_max * HEIGHT / WIDTH );
	c->y_min = c->x_min * HEIGHT / WIDTH;
	c->scale = (c->x_max - c->x_min) / WIDTH;
}
