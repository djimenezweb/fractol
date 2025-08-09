/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/09 10:23:09 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

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

int	main(void)
{
	t_mlx	mlx;
	t_image	img;
	
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		free_and_exit(&mlx, 1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "HD test");
	if (!mlx.win_ptr)
		free_and_exit(&mlx, 1);
	img.img = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_mandelbrot(&img, 400);
	print_crosshair(&img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img, 0, 0);
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx.mlx_ptr);
	mlx_loop(mlx.mlx_ptr);
	// Free stuff ??
	return (0);
}
