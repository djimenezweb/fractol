/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:23:39 by danielji          #+#    #+#             */
/*   Updated: 2025/08/07 13:12:43 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"
#include <stdio.h>

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

/* 

Conjunto de Mandelbrot: Son aquellos números complejos que cumplen con la función

	f(z) = z² + c		->		

Por ejemplo, queremos comprobar si el número complejo (5, 2i) cumple con la función.
La función se hace en varias iteraciones. Si ¿no sé qué? a infinito entonces no cumple.

Primera iteración	z = 0		0² + c					->		(5, 2i)
Segunda iteración	z = 1		(5 + 2i)² + (5, 2i)		->		(26, 22i)

¿Cómo se resuelve (5 + 2i)²?

	(5 + 2i)² = (5+2i) * (5+2i) = 5² + 10i + 10i + 4i² = 25 + 20i -4 = 21 + 20i

	parte real			=	(5 * 5) - (2 * 2)
	parte imaginaria	=	2 * (5 * 2)
*/

t_complex	equation(t_complex z, t_complex c)
{
	//double		r_temp;
	t_complex	result;

	//r_temp = z.r;
	result.r = ((z.r * z.r) - (z.i * z.i)) + c.r;
	result.i = (2 * (z.r * z.i)) + c.i;
	return (result);
}

void	is_mandelbrot_set(double r, double i)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.r = 0;
	z.i = 0;
	c.r = r;
	c.i = i;
	while (iter < ITERATIONS)
	{
		z = equation(z, c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			printf("Escape at %d\n", iter);
			break ;
		}
		printf("%d: (%fr, %fi)\n", iter, z.r, z.i);
		iter++;
	}
}

int	main(void)
{
	is_mandelbrot_set(-0.758, 0.252);
	return (0);
}