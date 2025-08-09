/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:19:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/09 10:10:45 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	print_sq_diagonal(t_image *img)
{
	int	i;

	i = 0;
	while (i <= HEIGHT)
	{
		image_pixel_put(img, i, i, 0x7ccf00);
		i++;
	}
}

void	print_diagonal(t_image *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		y = x / 1.777;
		image_pixel_put(img, x, y, 0xff2056);
		x++;
	}
}

void	print_frame(t_image *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		image_pixel_put(img, x, 0, 0xfd9a00);
		image_pixel_put(img, x, (HEIGHT - 1), 0xfd9a00);
		x++;
	}
	while (y <= HEIGHT)
	{
		image_pixel_put(img, 0, y, 0xfd9a00);
		image_pixel_put(img, (WIDTH - 1), y, 0xfd9a00);
		y++;
	}
}

void	print_rectangle(t_image *img, int x_start, int y_start, int w, int h)
{
	int	color = 0xffffff;
	int	x = x_start;
	int y = y_start;
	while (x_start <= (w + x))
	{
		image_pixel_put(img, x_start, y_start, color);
		image_pixel_put(img, x_start, y_start + h, color);
		x_start++;
	}
	x_start = x;
	while (y_start <= (h + y))
	{
		image_pixel_put(img, x_start, y_start, color);
		image_pixel_put(img, x_start + w, y_start, color);
		y_start++;
	}
}

void	print_crosshair(t_image *img)
{
	int	x;
	int	y;
	int	color;

	x = (WIDTH / 2) - 12;
	y = (HEIGHT / 2) - 12;
	color = 0xffff00;
	while(x < (WIDTH / 2) + 12)
	{
		image_pixel_put(img, x, (HEIGHT / 2), color);
		x++;
	}
	while(y < (HEIGHT / 2) + 12)
	{
		image_pixel_put(img, (WIDTH / 2), y, color);
		y++;
	}
}

void	print_fill_rectangle(t_image *img, int x_start, int y_start, int w, int h)
{
	int	x;
	int	y;
	int	fill;

	x = 0;
	fill = 0x9810fa;
	while (x <= WIDTH)
	{
		if (x >= x_start && x <= (w + x_start))
		{
			y = 0;
			while (y <= HEIGHT)
			{
				if (y >= y_start && y <= (h + y_start))
					image_pixel_put(img, x, y, fill);
				y++;
			}
		}
		x++;
	}
}

void	print_circle(t_image *img, double x0, double y0, double r)
{
	double	x;
	double	y;
	int		fill;

	x = 0;
	fill = 0x009966;
	while (x <= WIDTH)
	{
		if ((x >= (x0 - r)) && (x <= (x0 + r)))
		{
			y = 0;
			while (y <= HEIGHT)
			{
				if ((y >= (y0 - r)) && (y <= (y0 + r)))
				{
					// Si (x,y) está a la distancia r de (x0,y0)
					if (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) <= r)
						image_pixel_put(img, (int)x, (int)y, fill);
				}
				y++;
			}
		}
		x++;
	}
}
