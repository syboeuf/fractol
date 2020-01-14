/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinskicarpet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:11:26 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 13:58:39 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_color(t_fractol *f, int px, int py, float w)
{
	int index;
	int index2;
	int i;
	int k;

	index = (px + py * WIDTH) * 4;
	k = -1;
	while (++k < (int)w)
	{
		i = -1;
		while (++i < (int)w)
		{
			index2 = (i + k * WIDTH) * 4;
			f->data[index + index2 + 0] = (unsigned char)255;
			f->data[index + index2 + 1] = (unsigned char)255;
			f->data[index + index2 + 2] = (unsigned char)255;
			f->data[index + index2 + 3] = 0;
		}
	}
}

void	draw_carpet(t_fractol *f, float *tab, int height, int iteration)
{
	float		w;
	float		x0;
	float		y0;
	int			i;
	int			j;

	w = height / 3;
	x0 = tab[0];
	y0 = tab[1];
	if (iteration == 0)
		return ;
	put_color(f, x0 + w, y0 + w, w);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (j == 1 && i == 1)
				continue;
			tab[0] = x0 + j * w;
			tab[1] = y0 + i * w;
			draw_carpet(f, tab, w, iteration - 1);
		}
	}
}

void	change_iteration(t_fractol *f, int num)
{
	float carpet_left;
	float tab[2];

	if (num == -1)
	{
		if (f->max_iteration > 0)
			f->max_iteration += num;
	}
	else
	{
		if (f->max_iteration < 8)
			f->max_iteration += num;
	}
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	carpet_left = (WIDTH - HEIGHT) / 2;
	tab[0] = carpet_left;
	tab[1] = 0;
	draw_carpet(f, tab, HEIGHT, f->max_iteration);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	draw_sierpinski_carpet(t_fractol *f)
{
	float carpet_left;
	float tab[2];

	carpet_left = (WIDTH - HEIGHT) / 2;
	f->max_iteration = 2;
	tab[0] = carpet_left;
	tab[1] = 0;
	draw_carpet(f, tab, HEIGHT, f->max_iteration);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
