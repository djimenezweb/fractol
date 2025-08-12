/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:19:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 16:11:40 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	print_crosshair(t_config *config)
{
	int	x;
	int	y;
	int	color;

	x = (WIDTH / 2) - 12;
	y = (HEIGHT / 2) - 12;
	color = 0xffff00;
	while (x < (WIDTH / 2) + 12)
	{
		image_pixel_put(config, x, (HEIGHT / 2), color);
		x++;
	}
	while (y < (HEIGHT / 2) + 12)
	{
		image_pixel_put(config, (WIDTH / 2), y, color);
		y++;
	}
}
