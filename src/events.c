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

void	move(t_axis *axis, int direction)
{
	axis->max += 0.1 * (double)direction;
	axis->min += 0.1 * (double)direction;
}

void	scale(t_fractol *f, double factor)
{
	f->x.max *= factor;
	f->x.min *= factor;
	f->y.max *= factor;
	f->y.min *= factor;
}

int	handle_key(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	else if (keysym == XK_Left)
		move(&(f->x), -1);
	else if (keysym == XK_Right)
		move(&(f->x), 1);
	else if (keysym == XK_Up)
		move(&(f->y), -1);
	else if (keysym == XK_Down)
		move(&(f->y), 1);
	else
		return (0);
	render_fractal(f);
	return (0);
}

int	handle_mouse(int e, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (e == 4)
		scale(f, 0.5);
	else if (e == 5)
		scale(f, 2);
	else
		return (0);
	render_fractal(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	free_and_exit(f, 0);
	return (0);
}

void	listen_events(t_fractol *f)
{
	mlx_hook(f->win_ptr, 17, 0, close_window, &f->mlx_ptr);
	mlx_key_hook(f->win_ptr, handle_key, &f->mlx_ptr);
	mlx_mouse_hook(f->win_ptr, handle_mouse, &f->mlx_ptr);
}
