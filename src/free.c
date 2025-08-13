/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:34:55 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 20:34:55 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	free_and_exit(f, 0);
	return (0);
}

void	free_and_exit(t_fractol *f, int status)
{
	if (!f)
		exit(status);
	if (f->img)
		mlx_destroy_image(f->mlx_ptr, f->img);
	if (f->mlx_ptr && f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(status);
}
