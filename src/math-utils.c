/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:50:10 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:36:08 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double r, double i)
{
	t_complex	c;

	c.r = r;
	c.i = i;
	return (c);
}

t_axis	init_axis(double min, double max)
{
	t_axis	a;

	a.min = min;
	a.max = max;
	return (a);
}

/* Returns the absolute value of a double floating number `n` */
double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/* Solves `f(z) = z² + c` and returns the result as a complex number */
t_complex	quadratic_map(t_complex z, t_complex c)
{
	t_complex	result;

	result.r = ((z.r * z.r) - (z.i * z.i)) + c.r;
	result.i = (2 * (z.r * z.i)) + c.i;
	return (result);
}
