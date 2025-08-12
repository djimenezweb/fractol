/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:16:12 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_and_exit(t_fractol *f, int status)
{
	if (f->mlx_ptr && f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
		mlx_destroy_display(f->mlx_ptr);
	exit(status);
}

int	handle_input(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

void	image_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	t_fractol	f;

	parse_args(argc, argv);
	initialize(&f);
	init_configuration(&f);
	set_mode(&f, argv);
	render_fractal(&f);
	print_crosshair(&f);
	mlx_put_image_to_window(f.mlx_ptr, f.win_ptr, f.img, 0, 0);
	mlx_key_hook(f.win_ptr, handle_input, &f.mlx_ptr);
	mlx_loop(f.mlx_ptr);
	return (0);
}
