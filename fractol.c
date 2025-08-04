/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/04 12:14:45 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/* Codam
#include "MLX42/MLX42.h"  */
#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "HD test");
	mlx_loop(mlx);
}
