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

void	initialize(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		free_and_exit(f, 1);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win_ptr)
		free_and_exit(f, 1);
}

void	init_configuration(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	f->ratio = WIDTH / HEIGHT;
	f->scale = 1.0;
	f->x_max = 1.6 / f->scale;
	f->x_min = -1.6 / f->scale;
	f->y_max = 1.6 / f->scale;
	f->y_min = -1.6 / f->scale;
	// c->y_max = ((c->x_max - c->x_min) / 2) * HEIGHT / WIDTH ;
	// c->y_min = -1 * ((c->x_max - c->x_min) / 2) * HEIGHT / WIDTH ;
	f->scale_x = (f->x_max - f->x_min) / WIDTH;
	f->scale_y = (f->y_min - f->y_max) / HEIGHT;
}

void	set_mode(t_fractol *f, char *argv[])
{
	if (argv[1][0] == 'M')
		f->mode = MANDELBROT;
	if (argv[1][0] == 'J')
	{
		f->mode = JULIA;
		f->c.r = ft_atod(argv[2]);
		if (!argv[3])
			f->c.i = ft_atod(argv[2]);
		else
			f->c.i = ft_atod(argv[3]);
	}
}
