/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsleyfern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:32:27 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 15:20:00 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"

void	put_color_barnsleyfern(t_fractol *f, int px, int py)
{
	int index;

	index = (px + py * WIDTH) * 4;
	f->data[index + 0] = (unsigned char)9;
	f->data[index + 1] = (unsigned char)106;
	f->data[index + 2] = (unsigned char)9;
	f->data[index + 3] = 0;
}

void	zoom_barnsleyfern(t_fractol *f, int x, int y, int zoom)
{
	f->x0 = (double)x;
	f->y0 = (double)y;
	if (zoom == 1)
		f->zoom += 1;
	else if (zoom == -1)
		f->zoom -= 1;
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	barnsleyfern(f);
}

void	calcul_coordinate(t_fractol *f)
{
	int dicethrow;

	dicethrow = rand() % 100;
	if (dicethrow == 0)
	{
		f->xmax = 0;
		f->ymax = 0.16 * f->ymin;
	}
	else if (dicethrow >= 1 && dicethrow <= 7)
	{
		f->xmax = -0.15 * f->xmin + 0.28 * f->ymin;
		f->ymax = 0.26 * f->xmin + 0.24 * f->ymin + 0.44;
	}
	else if (dicethrow >= 8 && dicethrow <= 15)
	{
		f->xmax = 0.2 * f->xmin - 0.26 * f->ymin;
		f->ymax = 0.23 * f->xmin + 0.22 * f->ymin + 1.6;
	}
	else
	{
		f->xmax = 0.85 * f->xmin + 0.04 * f->ymin;
		f->ymax = -0.04 * f->xmin + 0.85 * f->ymin + 1.6;
	}
}

void	barnsleyfern(t_fractol *f)
{
	double				real_x;
	double				real_y;
	unsigned long		iter;

	iter = 500000;
	f->xmin = 0;
	f->ymin = 0;
	calculette_palette_mandelbrot(f);
	while (iter-- > 0)
	{
		calcul_coordinate(f);
		real_x = f->zoom * f->xmax + HEIGHT / 2.0;
		real_y = f->zoom * f->ymax;
		if (real_x > 0 && real_y > 0 && real_x < WIDTH && real_y < HEIGHT)
			put_color_barnsleyfern(f, real_x, real_y);
		f->xmin = f->xmax;
		f->ymin = f->ymax;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
