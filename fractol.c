/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/06 12:13:20 by danielji         ###   ########.fr       */
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
	int	x = x_start;
	while (x_start <= w)
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00a6f4);
		my_mlx_pixel_put(img, x_start, h, 0x00a6f4);
		x_start++;
	}
	x_start = x;
	while (y_start <= h)
	{
		my_mlx_pixel_put(img, x_start, y_start, 0x00a6f4);
		my_mlx_pixel_put(img, w, y_start, 0x00a6f4);
		y_start++;
	}
}

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
	print_rectangle(&img, 192, 66, 1357, 687);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
