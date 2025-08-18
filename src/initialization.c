/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:55:02 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:53:03 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* - Initializes MLX instance
- Creates new window
- Creates new image
- Sets starting `x` and `y` coordinate values
- Exits program on error */
void	initialize(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		free_and_exit(f, EXIT_FAILURE);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win_ptr)
		free_and_exit(f, EXIT_FAILURE);
	f->img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img)
		free_and_exit(f, EXIT_FAILURE);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	f->y = init_axis(-1.6, 1.6);
	if (f->mode == MANDELBROT)
		f->x = init_axis(-2.2, 1.0);
	else
		f->x = init_axis(-1.6, 1.6);
}
