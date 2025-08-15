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

void	reframe(t_fractol *f, int x, int y)
{
	double	scale_x;

	scale_x = (f->x.max - f->x.min) / WIDTH;
	ft_printf("Mouse: (%d,%d) -> (%d,%d)\n", x, y, x - (WIDTH / 2), y - (HEIGHT / 2));
	f->x.max = f->x.max + ((double)x - (WIDTH / 2)) * scale_x;
	f->x.min = f->x.min + ((double)x - (WIDTH / 2)) * scale_x;
	f->y.max = f->y.max + ((double)y - (HEIGHT / 2)) * scale_x;
	f->y.min = f->y.min + ((double)y - (HEIGHT / 2)) * scale_x;
	//scale(f, 0.5);
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
	{
		//reframe(f, x, y);
		scale(f, 0.5);
	}
	else if (e == 5)
	{
		//reframe(f, x, y);
		scale(f, 2);
	}
	else
		return (0);
	render_fractal(f);
	return (0);
}

/* Hooks into:
- Close button event (`x_event = 17`)
- Keyboard events
- Mouse events */
void	listen_events(t_fractol *f)
{
	mlx_hook(f->win_ptr, 17, 0, close_window, &f->mlx_ptr);
	mlx_key_hook(f->win_ptr, handle_key, &f->mlx_ptr);
	mlx_mouse_hook(f->win_ptr, handle_mouse, &f->mlx_ptr);
}
