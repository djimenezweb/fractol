/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:15:06 by danielji          #+#    #+#             */
/*   Updated: 2025/08/17 10:56:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* - Exits program when `Esc` is pressed
- Calls `move` when arrow keys are pressed
- Renders a new image */
int	handle_key(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	else if (keysym == XK_Left)
		move(&(f->x), MV_LEFT);
	else if (keysym == XK_Right)
		move(&(f->x), MV_RIGHT);
	else if (keysym == XK_Up)
		move(&(f->y), MV_UP);
	else if (keysym == XK_Down)
		move(&(f->y), MV_DOWN);
	else
		return (0);
	render_fractal(f);
	return (0);
}

/* - Calls `scale` when scrolling the wheel mouse up or down
- Renders a new image */
int	handle_mouse(int e, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (e == SCROLL_UP)
		scale(f, 0.5);
	else if (e == SCROLL_DOWN)
		scale(f, 2);
	else
		return (0);
	render_fractal(f);
	return (0);
}

/* Hooks into:
- Close button event
- Keyboard events
- Mouse events */
void	listen_events(t_fractol *f)
{
	mlx_hook(f->win_ptr, CLOSE_BTN, 0, close_window, &f->mlx_ptr);
	mlx_key_hook(f->win_ptr, handle_key, &f->mlx_ptr);
	mlx_mouse_hook(f->win_ptr, handle_mouse, &f->mlx_ptr);
}
