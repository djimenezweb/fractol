/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:15:06 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 09:15:10 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
XK_Home     
XK_Left       Move left, left arrow
XK_Up         Move up, up arrow
XK_Right      Move right, right arrow
XK_Down       Move down, down arrow
XK_Prior      Prior, previous
XK_Page_Up  
XK_Next       Next
XK_Page_Down
XK_End        EOL
XK_Begin      BOL

XK_KP_Add
XK_KP_Space
XK_KP_Subtract                   0xffad
 */

void	scale(t_fractol *f, double factor)
{
	f->x_max *= factor;
	f->x_min *= factor;
	f->y_max *= factor;
	f->y_min *= factor;
	f->scale_x = (f->x_max - f->x_min) / WIDTH;
	f->scale_y = (f->y_min - f->y_max) / HEIGHT;
}

int	handle_key(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	if (keysym == XK_Left)
		scale(f, 0.5);
	if (keysym == XK_Right)
		scale(f, 2);
	render_fractal(f);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

int	handle_mouse(int e, t_fractol *f)
{
	if (e == 4)
	{
		ft_printf("Mouse event %d\n", e);
		scale(f, 0.5);
		render_fractal(f);
	}
	if (e == 5)
	{
		ft_printf("Mouse event %d\n", e);
		scale(f, 2);
		render_fractal(f);
	}
	return (0);
}

void	listen_events(t_fractol *f)
{
	mlx_key_hook(f->win_ptr, handle_key, &f->mlx_ptr);
	mlx_mouse_hook(f->win_ptr, handle_mouse, &f->mlx_ptr);
}
