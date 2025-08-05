/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:51:40 by danielji          #+#    #+#             */
/*   Updated: 2025/08/05 11:34:39 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include "libft/libft.h"

# define WIDTH	1920
# define HEIGHT	1080

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif