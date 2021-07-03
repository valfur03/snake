/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:53:03 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/03 03:25:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	interpolate_snake_colors(t_config *config)
{
	uint16_t	i;
	int32_t		red;
	int32_t		green;
	int32_t		blue;
	double		ratio;

	i = 0;
	while (i < config->snake_size)
	{
		ratio = 1.0 / config->snake_size * i;
		red = (HEAD & 0xFF0000) >> 16;
		green = (HEAD & 0x00FF00) >> 8;
		blue = HEAD & 0x0000FF;
		red += (((TAIL & 0xFF0000) >> 16) - red) * ratio;
		green += (((TAIL & 0x00FF00) >> 8) - green) * ratio;
		blue += ((TAIL & 0x0000FF) - blue) * ratio;
		config->snake[i].color = (red << 16) | (green << 8) | blue;
		i++;
	}
}
