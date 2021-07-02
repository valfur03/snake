/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:14:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 23:14:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	init_snake(t_config *config)
{
	uint8_t	i;
	t_pixel	body;

	config->width = 800;
	config->height = 800;
	config->tile_size = 40;
	config->tile_nbr = ((config->width / config->tile_size) - 2)
			* ((config->width / config->tile_size) - 2);
	bzero(config->snake, (config->tile_nbr + 1) * sizeof (*config->snake));
	config->speed = 170000;
	config->score = 0;
	config->direction = RIGHT;
	config->last_direction = RIGHT;
	config->snake_size = 4;
	body.color = HEAD;
	if (config->width / config->tile_size > 7)
		body.x = 5;
	else
		body.x = 1;
	if (config->height / config->tile_size > 7)
		body.y = 5;
	else
		body.y = 1;
	i = 0;
	while (i < config->snake_size)
	{
		config->snake[i] = body;
		if (i == 0)
			body.color = BODY;
		body.x--;
		i++;
	}
	generate_new_collectible(config);
}

uint8_t	init_mlx(t_config *config)
{
	config->mlx = mlx_init();
	if (config->mlx == NULL)
		return (-1);
	config->img.ptr = mlx_new_image(config->mlx, config->width, config->height);
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
