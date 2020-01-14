/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:47:52 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 14:00:25 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

# define WIDTH 640
# define HEIGHT 480

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	unsigned long	img_color;
	int				red_array[256];
	int				blue_array[256];
	int				green_array[256];
	float			x0;
	float			y0;
	float			xmin;
	float			xmax;
	float			ymin;
	float			ymax;
	float			zoom;
	float			xdelta;
	float			ydelta;
	int				bpp;
	int				sizeline;
	int				endian;
	int				max_iteration;
	float			panx;
	float			pany;
	float			xtemp;
	char			*name_fractol;
}					t_fractol;

void				julia(t_fractol *f);
void				draw_mandelbrot(t_fractol *f);
void				put_color_in_image(t_fractol *f, int px, int py, int i);
int					deal_mouse(int button, int x, int y, void *params);
void				zoom_mandelbrot(t_fractol *f, int x, int y, int zoomin);
void				zoom_julia(t_fractol *f, int zoomin);
void				draw_burning_ship(t_fractol *f);
void				disp(t_fractol *f);
void				zoom_burningship(t_fractol *f, int x, int y, int zoomin);
void				barnsleyfern(t_fractol *f);
void				calculette_palette_mandelbrot(t_fractol *f);
void				draw_sierpinski_carpet(t_fractol *f);
void				change_iteration(t_fractol *f, int num);
void				zoom_barnsleyfern(t_fractol *f, int x, int y, int zoom);
int					deal_move(int x, int y, void *params);
void				draw_julia(t_fractol *f);

#endif
