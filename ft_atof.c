/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:11:32 by danielji          #+#    #+#             */
/*   Updated: 2025/08/12 10:59:02 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

//#include "fractol.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	int		decimal;
	double	result;

	i = 0;
	sign = 1;
	decimal = 0;
	result = 0.0;
	if (!str || !str[i])
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.' && !decimal)
			decimal = i;
		if (str[i] != '.')
			result = (result) * 10 + str[i] - '0';
		i++;
	}
	decimal = i - decimal - 1;
	while (decimal > 0)
	{
		result = result / 10.0;
		decimal--;
	}
	return ((double)(sign * result));
}

/* int	main(int argc, char *argv[])
{
	printf("%s, %s, %s\n", argv[1], argv[2], argv[3]);
	printf("%f, %f, %f\n", ft_atof(argv[1]), ft_atof(argv[2]), ft_atof(argv[3]));
} */