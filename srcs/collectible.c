/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:07:42 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 21:02:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	generate_new_collectible(t_config *config)
{
	uint16_t	i;
	uint16_t	collectible_index;
	t_pixel		pixel;

	if (config->snake_size == config->tile_nbr)
		return ;
	collectible_index = rand() % (config->tile_nbr - config->snake_size);
	i = 0;
	while (i < config->tile_nbr)
	{
		pixel.x = i % ((config->width / config->tile_size) - 2) + 1;
		pixel.y = i / ((config->height / config->tile_size) - 2) + 1;
		if (pixel_is_snake(config, &pixel, 0, NULL))
			collectible_index++;
		if (i == collectible_index)
			break ;
		i++;
	}
	config->collectible.x = i % ((config->width / config->tile_size) - 2) + 1;
	config->collectible.y = i / ((config->height / config->tile_size) - 2) + 1;
}
