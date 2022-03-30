/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:14:49 by seb               #+#    #+#             */
/*   Updated: 2022/03/30 22:26:14 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define NULL (void *)0

#define max(a,b) (((a) (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATION 42

enum e_mouse_button {
	LEFT_BUTTON = 1,
	RIGHT_BUTTON = 2,
	MIDDLE_BUTTON = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_complex {
	double	r;
	double	i;
}				t_complex;

typedef struct s_coord {
	int		x;
	int		y;
}				t_coord;

typedef struct s_state {
	void		*mlx;
	void		*win;
	t_img		*img;
	double		zoom;
	t_coord		center;
}				t_state;

void	mandelbrot_set_to_img(t_state *state, t_img *img);

void	agrand_diagram_to_img(t_state *state, t_img *img);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img	*generate_new_image(void *mlx);
void	update_frame(t_state *state, void (f)(t_state *, t_img *));

t_complex	coord_to_cplx(t_coord coord, t_state *state);
t_coord	cplx_to_coord(t_complex cplx, t_state *state);

int	mouse_button_hook(int button, int x, int y, void *param);

t_state	init_state(void);

#endif
