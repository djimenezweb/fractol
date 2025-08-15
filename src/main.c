/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 20:31:15 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* - Parses arguments
- Initializes `t_fractol` structure with configuration
- Renders fractal
- Hooks into mouse and keyboard events */
int	main(int argc, char *argv[])
{
	t_fractol	f;

	parse_args(&f, argc, argv);
	initialize(&f);
	render_fractal(&f);
	listen_events(&f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
