/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 17:58:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

typedef enum e_colors
{
	BORDER = 0x578A34,
	FLOOR = 0xAAD751,
	BODY = 0x426FE3,
	HEAD = 0x4E7CF6,
	COLLECTIBLE = 0xE7471D
}				t_colors;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_direction;

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
	uint16_t	score;
	t_pixel		snake[325];
	uint16_t	snake_size;
	t_pixel		collectible;
	t_direction	direction;
	t_direction	last_direction;
	uint8_t		playing;
}				t_config;

void	generate_new_collectible(t_config *config);

void	init_snake(t_config *config);
uint8_t	init_mlx(t_config *config);

void	my_mlx_events(t_config *config);

void	my_mlx_put_pixel_size(t_mlx_img *img, t_pixel *pixel);

uint8_t	pixel_is_snake(t_config *config, t_pixel *pixel, uint16_t start, uint32_t *color);
void	render_map(t_config *config);

#endif
