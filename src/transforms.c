/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:54:24 by danielji          #+#    #+#             */
/*   Updated: 2025/08/17 10:56:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Finds the center coordinates of an axis */
double	find_center(t_axis a)
{
	return ((a.max + a.min) / 2.0);
}

/* - Finds center and update scaled boundaries so that center stays fixed */
void	scale(t_fractol *f, double magnification)
{
	double	cx;
	double	cy;
	double	half_size;

	cx = find_center(f->x);
	cy = find_center(f->y);
	half_size = (f->x.max - f->x.min) / 2.0;
	f->x.min = cx - (half_size * magnification);
	f->x.max = cx + (half_size * magnification);
	f->y.min = cy - (half_size * magnification);
	f->y.max = cy + (half_size * magnification);
}

/* Sets new `min` and `max` values for a single axis (`x` or `y`),
effectively reframing the image in just one axis */
void	move(t_axis *axis, int direction)
{
	double	step;

	step = (axis->max - axis->min) * 0.1;
	axis->max += step * (double)direction;
	axis->min += step * (double)direction;
}
