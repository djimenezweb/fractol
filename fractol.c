/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:35:33 by danielji          #+#    #+#             */
/*   Updated: 2025/08/05 11:32:26 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fractol.h"

/* int	handle_input(int keysym, t_mlx_data *data)
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
} */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	int		i;
	void	*mlx;
	void	*mlx_win;	
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "HD test");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xff0000);
	i = 0;
	while (i <= WIDTH)
	{
		my_mlx_pixel_put(&img, i, i, 0x00ff00);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_pixel_put(mlx, mlx_win, 960 + i, 540 + i, 0x00ff00);
	//mlx_key_hook(mlx_win, handle_input, &data);
	// mlx_loop_hook(...); No events listening
	//mlx_hook(mlx_win, ButtonPress, ButtonPressMask, &button_press, &data);
/* 	i = -1;
	while (++i <= WIDTH)
		mlx_pixel_put(mlx, mlx_win, 960 + i, 540 + i, 0x00ff00); */
	mlx_loop(mlx);
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	//free(mlx);
	return (0);
}
