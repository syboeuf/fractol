/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 09:47:03 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 13:52:38 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_mandelbrot(t_fractol *f, int x, int y, int zoomin)
{
	int offsetx;
	int offsety;

	offsetx = -WIDTH / 2;
	offsety = -HEIGHT / 2;
	if (zoomin == 1)
	{
		f->zoom *= 2;
		f->panx = 2 * (x + offsetx + (int)f->panx);
		f->pany = 2 * (y + offsety + (int)f->pany);
	}
	else if (zoomin == -1)
	{
		f->zoom /= 2;
		f->panx = (x + offsetx + (int)f->panx) / 2;
		f->pany = (y + offsety + (int)f->pany) / 2;
	}
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	draw_mandelbrot(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	calculette_palette_mandelbrot(t_fractol *f)
{
	int roffset;
	int goffset;
	int boffset;
	int i;

	roffset = 24;
	goffset = 16;
	boffset = 0;
	i = -1;
	while (++i < 256)
	{
		f->red_array[i] = roffset;
		f->green_array[i] = goffset;
		f->blue_array[i] = boffset;
		if (i < 64)
			roffset += 3;
		else if (i < 128)
			goffset += 3;
		else if (i < 192)
			boffset += 3;
	}
}

void	init_values(t_fractol *f, int x, int y)
{
	int offsetx;
	int offsety;

	offsetx = -WIDTH / 2;
	offsety = -HEIGHT / 2;
	f->x0 = (float)(x + offsetx + (int)f->panx) / f->zoom;
	f->y0 = (float)(y + offsety + (int)f->pany) / f->zoom;
	f->xmin = 0.0;
	f->ymin = 0.0;
	f->xdelta = 0.0;
	f->ydelta = 0.0;
}

void	calcul_mandelbrot(t_fractol *f, int *iterations)
{
	*iterations = 0;
	while (*iterations < f->max_iteration
		&& (f->xdelta * f->xdelta + f->ydelta * f->ydelta <= 4.0))
	{
		f->xdelta = f->xmin * f->xmin - f->ymin * f->ymin + f->x0;
		f->ydelta = 2 * f->xmin * f->ymin + f->y0;
		f->xmin = f->xdelta;
		f->ymin = f->ydelta;
		(*iterations)++;
	}
}

void	draw_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	int		iterations;
	float	index;

	calculette_palette_mandelbrot(f);
	f->max_iteration = 250;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			init_values(f, x, y);
			calcul_mandelbrot(f, &iterations);
			index = floor(((float)iterations / (float)(f->max_iteration - 1))
				* 255);
			put_color_in_image(f, x, y,
				(iterations == f->max_iteration) ? 0 : (int)index);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
