/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/08 11:14:45 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	//print_sq_diagonal(&img);
	//print_diagonal(&img);
	//print_frame(&img);
	//print_fill_rectangle(&img, 110, 220, 310, 410);
	//print_rectangle(&img, 100, 200, 300, 400);
	//print_circle(&img, (double)960, (double)540, (double)100);
	print_mandelbrot(&img, 400);
	print_crosshair(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	// Free stuff
	return (0);
}
