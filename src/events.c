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

/* TO DO
This function is supposed to scale and move the image
according to the mouse position
DOES NOT WORK */
void	reframe(t_fractol *f, int x, int y)
{
	double	scale;

	scale = (ft_abs(f->x.max) + ft_abs(f->x.min)) / WIDTH;
	//ft_printf("Mouse: (%d,%d) -> (%d,%d)\n", x, y, x - (WIDTH / 2), y - (HEIGHT / 2));
	f->x.max = f->x.max + ((double)x - (WIDTH / 2)) * scale;
	f->x.min = f->x.min + ((double)x - (WIDTH / 2)) * scale;
	f->y.max = f->y.max + ((double)y - (HEIGHT / 2)) * scale;
	f->y.min = f->y.min + ((double)y - (HEIGHT / 2)) * scale;
	//scale(f, 0.5);
}

/* Sets new coordinate values according to scaling `factor` */
void	scale(t_fractol *f, double factor)
{
	f->x.max *= factor;
	f->x.min *= factor;
	f->y.max *= factor;
	f->y.min *= factor;
}

/* Sets new `min` and `max` values for a single axis (`x` or `y`),
effectively reframing the image in just one axis */
void	move(t_axis *axis, int direction)
{
	axis->max += 0.1 * (double)direction;
	axis->min += 0.1 * (double)direction;
}

/* - Exits program when `Esc` is pressed
- Calls `move` when arrow keys are pressed
- Renders a new image */
int	handle_key(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	else if (keysym == XK_Left)
		move(&(f->x), -1);
	else if (keysym == XK_Right)
		move(&(f->x), 1);
	else if (keysym == XK_Up)
		move(&(f->y), 1);
	else if (keysym == XK_Down)
		move(&(f->y), -1);
	else
		return (0);
	render_fractal(f);
	return (0);
}

/* - Calls `scale` when scrolling the wheel mouse up (`4`) or down (`5`)
- Renders a new image */
int	handle_mouse(int e, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (e == SCROLL_UP)
	{
		//reframe(f, x, y);
		scale(f, 0.5);
	}
	else if (e == SCROLL_DOWN)
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
