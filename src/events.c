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
	axis->max = axis->max + (direction * (axis->max / 10));
	axis->min = axis->min + (direction * (axis->min / 10));
}

void	scale(t_fractol *f, double factor)
{
	f->x.max *= factor;
	f->x.min *= factor;
	f->y.max *= factor;
	f->y.min *= factor;
	f->scale_x = (f->x.max - f->x.min) / WIDTH;
	f->scale_y = (f->y.min - f->y.max) / HEIGHT;
}

int	handle_key(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	if (keysym == XK_Left)
		move(&(f->x), 1);
	if (keysym == XK_Right)
		move(&(f->x), -1);
	if (keysym == XK_Up)
		move(&(f->y), 1);
	if (keysym == XK_Down)
		move(&(f->y), -1);
	render_fractal(f);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

int	handle_mouse(int e, int x, int y, t_fractol *f)
{
	ft_printf("Mouse event %d: %d,%d\n", e, x, y);
	if (e == 4)
		scale(f, 0.5);
	if (e == 5)
		scale(f, 2);
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
