/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:15:13 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 10:34:56 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE 60
# define TRUE 1
# define FALSE 0
# define WIN_WIDTH 1000
# define WIN_HEIGHT 600
# define TEXTURE_TILE 256
# define HORZ 1
# define VERT 0
# define ERROR -1
# define FREE 1
# define ALLOC 0
# define BUFFER_SIZE 10
# define M_PI 3.14159265358979323846
# define MOVE 4

typedef struct s_alloc
{
	void			*pointer;
	struct s_alloc	*next;
}					t_alloc;

typedef struct s_game
{
	char			**map;
	char			orientation_character;
	char			**map_informations;
	char			*map_file_name;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				number_lines;
	int				ceiling_color;
	int				floor_color;
	int				player_x;
	int				player_y;
	int				line_map;
	int				fd;

}					t_game;

typedef struct s_dis_tools
{
	double			hwallhitx;
	double			hwallhity;
	double			vwallhitx;
	double			vwallhity;
	double			xhstep;
	double			yhstep;
	double			xvstep;
	double			yvstep;
	double			ahx;
	double			ahy;
	double			avx;
	double			avy;
}					t_dis_tools;

typedef struct s_texture
{
	void			*textures[5];
	char			*addr[4];
	int				width[4];
	int				height[4];
	int				endian[4];
	int				len[4];
	int				bpp[4];
	int				tex_x;
	int				index;
}					t_texture;

typedef struct s_keys
{
	int				rotate_right;
	int				rotate_left;
	int				right;
	int				left;
	int				down;
	int				up;
}					t_keys;

typedef struct s_cube
{
	t_dis_tools		*dis;
	t_game			*game;
	t_texture		t_text;
	t_keys			key;
	double			wallstriph;
	double			r_speed;
	double			walldis;
	double			angle;
	double			fov;
	double			px;
	double			py;
	int				hit_check;
	int 			line_len;
	int				endian;
	int				height;
	int				bpp;
	char			*addr;
	char			**map;
	void			*mlx;
	void			*win;
	void			*img;
}					t_cube;

void				initialize(t_cube *data);
void				*ft_malloc(size_t bytes, int action);
void				wall_hit_cords(t_cube *data);
void				my_pixel_put(t_cube *data, int x, int y,
						unsigned int color);
void				render_all(t_cube *data);
void				draw_fov(t_cube *data);
void				wallstripheight(t_cube *data, double angle);
void				find_distance(t_cube *data, double angle);
void				get_texture_info(t_cube *data, double angle);
double				normalizeangle(double angle);
double				distance(t_cube *data);
unsigned int		get_color(t_cube *data, int index, int tex_x, int tex_y);
int					key_check(void *ptr);
int					colision(t_cube *data, int px, int py);
int					render_ddmap(t_cube *data);
int					index_tex(t_cube *data, double angle);
int					ft_exit(t_cube *data);
int					lookup(double angle);
int					lookdown(double angle);
int					right(double angle);
int					left(double angle);
int					key_press(int key, void *data);
int					key_release(int key, void *data);
// gnl functions!!

void				ft_bzero(void *address, size_t len);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
char				*get_next_line(int fd);
char				*ft_strdup(char *string);
char				*ft_substr(char *s, unsigned int start, size_t len);
unsigned int		ft_strlen(char *str);
int					ft_strchr(char *s, int c);

//	parsing functions
char				**ft_split(char const *s, char c);
void				free_double_ptr(char **split);
void				free_split(char **array, size_t j);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
// void		ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_atoi(char *str);
int					check_empty_lines_map(t_game *game);
int					check_holes(t_game *game, int i, int j);
int					fill_informations(t_game *game);
int					check_characters(t_game *game);
char				*ft_strtrim(char *str);
void				number_of_lines(t_game *game);
int					open_file(t_game *game);
void				read_map(t_game *game);
int					player_or_zero(char c);
int					check_surrounded_walls(t_game *game);
int					parse_color(char *str);
int					is_valid_map_line(char *line);
int					parse_color(char *str);
int					pars_map(t_game *game);
int					check_file_name(char *filename);
void				initialize_struct(t_game *game, char *filename);

//minimap

// void    draw_rectangle(t_cube *data, int width, int height, int color);
void    mini_map(t_cube *data);

#endif