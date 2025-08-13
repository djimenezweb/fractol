/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 09:15:10 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

void	free_and_exit(t_fractol *f, int status)
{
	if (!f)
		exit(status);
	if (f->img)
		mlx_destroy_image(f->mlx_ptr, f->img);
	if (f->mlx_ptr && f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(status);
}

int	main(int argc, char *argv[])
{
	t_fractol	f;

	parse_args(&f, argc, argv);
	initialize(&f);
	init_configuration(&f);
	render_fractal(&f);
	listen_events(&f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
