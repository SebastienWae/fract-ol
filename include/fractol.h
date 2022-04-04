/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:14:49 by seb               #+#    #+#             */
/*   Updated: 2022/04/04 14:33:18 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define SCALE 2.
# define MAX_ITERATION 100
# define MAX_STEPS 1000

enum e_zoom_dir {
	ZOOM_IN,
	ZOOM_OUT,
	ZOOM_RESET
};
enum e_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum e_mouse_buttons {
	LEFT_BUTTON = 1,
	RIGHT_BUTTON = 2,
	MIDDLE_BUTTON = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};
enum e_keys {
	KEY_MINUS = 27,
	KEY_PLUS = 24,
	KEY_RETURN = 36,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
};

typedef struct s_img		t_img;
typedef struct s_complex	t_complex;
typedef struct s_coord		t_coord;
typedef struct s_fractal	t_fractal;
typedef struct s_args		t_args;
typedef struct s_state		t_state;
typedef struct s_pixel		t_pixel;
typedef t_pixel				(*t_fractal_func)(t_complex, t_state *);

struct s_img {
	char	*addr;
	int		bpp;
	int		endian;
	int		line_length;
	void	*img;
};
struct s_complex {
	double	r;
	double	i;
};
struct s_coord {
	int		x;
	int		y;
};
struct s_pixel {
	unsigned int	iter;
	double			sqr;
};
struct s_fractal {
	t_pixel			pixels[WIDTH][HEIGHT];
	t_fractal_func	f;
};
struct s_args {
	t_fractal_func	f;
	t_complex		c;
};
struct s_state {
	int				zoom;
	double			scale;
	t_complex		offset;
	t_complex		factor;
	t_complex		c;
	unsigned int	color_scale;
	int				loops;
	int				redraw;
	int				render;
	void			*mlx;
	void			*win;
	t_img			*img;
	t_fractal		*fractal;
};

int				quit(t_state *state);

t_pixel			mandelbrot(t_complex c, t_state *s);
t_pixel			julia(t_complex c, t_state *s);
t_pixel			newton(t_complex c, t_state *s);

void			put_pixel(t_img *data, t_coord coord, unsigned int color);
t_img			*new_image(void *mlx);

double			squared_cplx(t_complex c);
t_complex		coord_to_cplx(t_coord coord, t_state *state);

t_args			parse_args(int argv, char **argc);
void			display_params(void);

int				mouse_handler(int button, int x, int y, void *param);
int				key_handler(int keycode, void *param);
int				loop_handler(void *param);

t_state			init_state(t_args *args);
void			destroy_state(t_state *state);

void			zoom(enum e_zoom_dir dir, t_state *state);

t_fractal		*new_fractal(t_fractal_func f);
unsigned int	i_to_color(int iter, double n, t_state *s);
void			render_fractal(t_state *s);
void			build_fractal(t_state *s);

#endif
