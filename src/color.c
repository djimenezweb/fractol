/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:40:36 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 20:31:15 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	set_color(int i)
{
	if (i == 0 || i == ITERATIONS)
		return (BLACK);
	else
		return (((uint8_t)(255 * (double)((double)i / ITERATIONS)) * 0x010101));
}

/* uint32_t	set_color(int i)
{
	if (i == 0)
		return (BACKGROUND);
	else if (i == ITERATIONS)
		return (BLACK);
	else {
		double factor = (double)i / ITERATIONS; // 0.0 to 1.0
		uint8_t r = (uint8_t)(255 * factor);
		uint8_t g = (uint8_t)(255 * factor);
		uint8_t b = 84;
		return (r << 16) | (g << 8) | b;
	}
} */

/* uint32_t set_color(int i)
{
	double	factor;
	
	if (i == ITERATIONS)
		return BLACK;

	factor = (double)i / ITERATIONS;

	uint8_t r1 = (BACKGROUND >> 16) & 0xff;
	uint8_t g1 = (BACKGROUND >> 8) & 0xff;
	uint8_t b1 = BACKGROUND & 0xff;

	uint8_t r2 = (WHITE >> 16) & 0xff;
	uint8_t g2 = (WHITE >> 8) & 0xff;
	uint8_t b2 = WHITE & 0xff;

	uint8_t r = (uint8_t)(r1 + (r2 - r1) * factor);
	uint8_t g = (uint8_t)(g1 + (g2 - g1) * factor);
	uint8_t b = (uint8_t)(b1 + (b2 - b1) * factor);

	return (r << 16) | (g << 8) | b;
} */