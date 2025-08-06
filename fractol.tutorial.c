/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.tutorial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/06 20:47:56 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/* 

¿Cuál es la raíz cuadrada de -1?
Números imaginarios i² = -1.

Un número complejo se expresa con dos números: uno real y otro imaginario

Conjunto de Mandelbrot: Son aquellos números complejos que cumplen con la función

	f(z) = z² + c		->		

Por ejemplo, queremos comprobar si el número complejo (5, 2i) cumple con la función.
La función se hace en varias iteraciones. Si ¿no sé qué? a infinito entonces no cumple.

Primera iteración	z = 0		0² + c					->		(5, 2i)
Segunda iteración	z = 1		(5 + 2i)² + (5, 2i)		->		(26, 22i)

¿Cómo se resuelve (5 + 2i)²?

	(5 + 2i)² = (5+2i) * (5+2i) = 5² + 10i + 10i + 4i² = 25 + 20i -4 = 21 + 20i


*/

#include "fractol.h"

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;



int	main(void)
{
	t_complex	z;
	t_complex	c;
}
