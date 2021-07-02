/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:14:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 12:17:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

uint8_t	init_mlx(t_config *config)
{
	config->mlx = mlx_init();
	if (config->mlx == NULL)
		return (-1);
	config->img.ptr = mlx_new_image(config->mlx, 800, 800);
	if (config->img.ptr == NULL)
	{
		mlx_destroy_display(config->mlx);
		free(config->mlx);
		return (-1);
	}
	config->img.addr = mlx_get_data_addr(config->img.ptr,
			&config->img.bits_per_pixel, &config->img.size_line,
			&config->img.endian);
	if (config->img.endian == 1)
	{
		printf("\033[33mWarning: Your system uses big endian, "
			"the colors may be inaccurate...\n");
		return (0);
	}
	return (1);
}
