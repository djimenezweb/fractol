/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/07 11:14:37 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_sq_diagonal(t_data *img)
{
	int	i;

	i = 0;
	while (i <= HEIGHT)
	{
		my_mlx_pixel_put(img, i, i, 0x7ccf00);
		i++;
	}
}

void	print_diagonal(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		y = x / 1.777;
		my_mlx_pixel_put(img, x, y, 0xff2056);
		x++;
	}
}

void	print_frame(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		my_mlx_pixel_put(img, x, 0, 0xfd9a00);
		my_mlx_pixel_put(img, x, (HEIGHT - 1), 0xfd9a00);
		x++;
	}
	while (y <= HEIGHT)
	{
		my_mlx_pixel_put(img, 0, y, 0xfd9a00);
		my_mlx_pixel_put(img, (WIDTH - 1), y, 0xfd9a00);
		y++;
	}
}

void	print_rectangle(t_data *img, int x_start, int y_start, int w, int h)
{
	int	color = 0xffffff;
	int	x = x_start;
	int y = y_start;
	while (x_start <= (w + x))
	{
		my_mlx_pixel_put(img, x_start, y_start, color);
		my_mlx_pixel_put(img, x_start, y_start + h, color);
		x_start++;
	}
	x_start = x;
	while (y_start <= (h + y))
	{
		my_mlx_pixel_put(img, x_start, y_start, color);
		my_mlx_pixel_put(img, x_start + w, y_start, color);
		y_start++;
	}
}

void	print_crosshair(t_data *img)
{
	int	x;
	int	y;
	int	color;

	x = (WIDTH / 2) - 12;
	y = (HEIGHT / 2) - 12;
	color = 0xffff00;
	while(x < (WIDTH / 2) + 12)
	{
		my_mlx_pixel_put(img, x, (HEIGHT / 2), color);
		x++;
	}
	while(y < (HEIGHT / 2) + 12)
	{
		my_mlx_pixel_put(img, (WIDTH / 2), y, color);
		y++;
	}
}

void	print_fill_rectangle(t_data *img, int x_start, int y_start, int w, int h)
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
					my_mlx_pixel_put(img, x, y, fill);
				y++;
			}
		}
		x++;
	}
}

void	print_circle(t_data *img, double x0, double y0, double r)
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
						my_mlx_pixel_put(img, (int)x, (int)y, fill);
				}
				y++;
			}
		}
		x++;
	}
}

/* void	print_mandelbrot(t_data *img, double z, double c)
{
	double	x;
	double	y;
	int		fill;

	x = 0;
	fill = 0x009966;
	while (x <= WIDTH)
	{
		if (x >= 0)
		{
			y = 0;
			while (y <= HEIGHT)
			{
				if (y >= 0)
				{
					if (x && y)
						my_mlx_pixel_put(img, (int)x, (int)y, fill);
				}
				y++;
			}
		}
		x++;
	}
} */

int	main(void)
{
	void	*mlx;
	void	*mlx_win;	
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "HD test");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_sq_diagonal(&img);
	print_diagonal(&img);
	print_frame(&img);
	print_fill_rectangle(&img, 110, 220, 310, 410);
	print_rectangle(&img, 100, 200, 300, 400);
	print_circle(&img, (double)960, (double)540, (double)100);
	print_crosshair(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	// Free stuff
	return (0);
}
