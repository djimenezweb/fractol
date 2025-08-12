/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 16:10:03 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	free_and_exit(t_config *c, int status)
{
	if (c->mlx_ptr && c->win_ptr)
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
	if (c->mlx_ptr)
		mlx_destroy_display(c->mlx_ptr);
	exit(status);
}

int	handle_input(int keysym, t_config *c)
{
	if (keysym == XK_Escape)
		free_and_exit(c, EXIT_SUCCESS);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

void	image_pixel_put(t_config *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bad_arguments(void)
{
	ft_printf("TO DO: Bad arguments\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_config	config;

	if (argc < 2 || argc > 4)
		bad_arguments();
	if (argv[1][0] != 'M' && argv[1][0] != 'J')
		bad_arguments();
	initialize(&config);
	init_configuration(&config);
	if (argv[1][0] == 'M')
		print_mandelbrot(&config);
	if (argv[1][0] == 'J')
	{
		ft_printf("TO DO: Print Julia");
		// print_julia(&img, ft_atod(argv[2]), ft_atod(argv[3]));
	}
	print_crosshair(&config);
	mlx_put_image_to_window(config.mlx_ptr, config.win_ptr, config.img, 0, 0);
	mlx_key_hook(config.win_ptr, handle_input, &config.mlx_ptr);
	mlx_loop(config.mlx_ptr);
	// Free stuff ??
	return (0);
}
