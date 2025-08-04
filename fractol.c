/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/04 19:48:06 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "HD test");
	mlx_pixel_put(mlx, mlx_window, 960, 540, 0x00ff00);
	mlx_loop(mlx);
	(void)mlx_window;
	return (0);
}
