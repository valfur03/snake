/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:07:42 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 17:56:08 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	generate_new_collectible(t_config *config)
{
	uint16_t	i;
	uint16_t	collectible_index;
	t_pixel		pixel;

	if (config->snake_size == 324)
		return ;
	collectible_index = rand() % (324 - config->snake_size);
	i = 0;
	while (i < 324 - config->snake_size)
	{
		pixel.x = i % 18 + 1;
		pixel.y = i / 18 + 1;
		if (pixel_is_snake(config, &pixel, NULL))
			collectible_index++;
		if (i == collectible_index)
			break ;
		i++;
	}
	config->collectible.x = i % 18 + 1;
	config->collectible.y = i / 18 + 1;
}
