/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:15:06 by danielji          #+#    #+#             */
/*   Updated: 2025/08/13 09:15:10 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
XK_Home     
XK_Left       Move left, left arrow
XK_Up         Move up, up arrow
XK_Right      Move right, right arrow
XK_Down       Move down, down arrow
XK_Prior      Prior, previous
XK_Page_Up  
XK_Next       Next
XK_Page_Down
XK_End        EOL
XK_Begin      BOL

XK_KP_Add
XK_KP_Space
XK_KP_Subtract                   0xffad
 */
int	handle_input(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		free_and_exit(f, EXIT_SUCCESS);
	if (keysym == XK_Left)
		f->scale = f->scale * 2;
		// free_and_exit(f, EXIT_SUCCESS);
	ft_printf("Pressed key %d\n", keysym);
	return (0);
}

void	listen_events(t_fractol *f)
{
	mlx_key_hook(f->win_ptr, handle_input, &f->mlx_ptr);
}