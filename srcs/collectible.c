/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:07:42 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 17:09:56 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void	generate_new_collectible(t_pixel *collectible)
{
	collectible->x = rand() % 18 + 1;
	collectible->y = rand() % 18 + 1;
}
