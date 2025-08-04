/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/04 21:04:24 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>
#include "libft/libft.h"

#define WIDTH	1920
#define HEIGHT	1080

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		// Why not exit(0)?
		exit(1);
	}
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;
	
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		// handle error
		return (1);
	}
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "HD test");
	if (!data.mlx_win)
	{
		// handle error, free stuff
		return (1);
	}
	mlx_key_hook(data.mlx_win, handle_input, &data);
	// mlx_loop_hook(...); No events listening
	//mlx_hook(data.mlx_win, ButtonPress, ButtonPressMask, &button_press, &data);
	mlx_pixel_put(data.mlx, data.mlx_win, 960, 540, 0x00ff00);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
