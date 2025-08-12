/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 10:51:25 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"
#include <stdio.h>

void	free_and_exit(t_mlx *mlx, int status)
{
	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	exit(status);
}

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		free_and_exit(mlx, EXIT_SUCCESS);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	bad_arguments()
{
	ft_printf("To do: Bad arguments\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_image	img;

	if (argc < 2 || argc > 4)
		bad_arguments();
	if (argv[1][0] != 'M' && argv[1][0] != 'J')
		bad_arguments();
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		free_and_exit(&mlx, 1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "HD test");
	if (!mlx.win_ptr)
		free_and_exit(&mlx, 1);
	img.img = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.ratio = WIDTH / HEIGHT;
	img.x_max = 1.2;
	img.x_min = -img.x_max;
	img.y_max = img.x_max * HEIGHT / WIDTH;
	img.y_min = img.x_min * HEIGHT / WIDTH;
	img.scale = ((img.x_max - img.x_min) / WIDTH);
	if (argv[1][0] == 'M')
		print_mandelbrot(&img);
	if (argv[1][0] == 'J')
	{
		printf("initial (main): %f,%f\n", ft_atof(argv[2]), ft_atof(argv[3]));
		print_julia(&img, ft_atof(argv[2]), ft_atof(argv[3]));
	}
	print_crosshair(&img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img, 0, 0);
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx.mlx_ptr);
	mlx_loop(mlx.mlx_ptr);
	// Free stuff ??
	return (0);
}
