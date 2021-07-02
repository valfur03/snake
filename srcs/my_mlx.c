/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:53:23 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 11:53:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	my_mlx_put_pixel(t_mlx_img *img, t_pixel *pixel)
{
	uint32_t		i;
	uint32_t		j;
	char			*dest;

	i = 0;
	while (i < pixel->size)
	{
		j = 0;
		while (j < pixel->size)
		{
			dest = img->addr + (img->size_line * (int)(pixel->y + j)
					+ (img->bits_per_pixel / 8) * (int)(pixel->x + i));
			*(unsigned int *)dest = pixel->color;
			j++;
		}
		i++;
	}
}
