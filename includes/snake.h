/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 13:16:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

typedef enum e_colors
{
	BORDER = 0x578A34,
	FLOOR = 0xAAD751,
	BODY = 0x426FE3,
	HEAD = 0x4E7CF6
}				t_colors;

typedef struct s_mlx_img
{
	void		*ptr;
	void		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx_img;

typedef struct s_pixel
{
	uint16_t	x;
	uint16_t	y;
	uint32_t	color;
	uint16_t	size;
}				t_pixel;

typedef struct s_config
{
	void		*mlx;
	void		*win;
	t_mlx_img	img;
	t_pixel		snake[325];
}				t_config;

void	init_snake(t_config *config);
uint8_t	init_mlx(t_config *config);

void	my_mlx_events(t_config *config);

void	my_mlx_put_pixel(t_mlx_img *img, t_pixel *pixel);

#endif
