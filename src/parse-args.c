/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:01:21 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 20:04:00 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bad_arguments(void)
{
	ft_printf("TO DO: Bad arguments\n");
	exit(EXIT_FAILURE);
}

void	parse_args(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		bad_arguments();
	if (argv[1][0] != 'M' && argv[1][0] != 'J')
		bad_arguments();
}
