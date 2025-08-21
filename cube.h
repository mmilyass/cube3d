#ifndef CUBE_H
#define CUBE_H

#define WH 32
#define ERROR -1
#define MOVE_SPEED 10
#define FREE 1
#define ALLOC 0
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10

#endif
#include <X11/keysym.h>
#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

typedef struct s_map
{
    char *row;
    struct s_map *next;
} t_map;

typedef struct s_alloc
{
    void *pointer;
    struct s_alloc *next;
} t_alloc;

typedef struct s_cube
{
    void *mlx;
    void *win;
    int width;
    int height;
    double angle;
    // double angle_direction;
    int px;
    int py;
    int pxt;
    int pyt;
    double fov;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    double r_speed;
    t_map *map;
} t_cube;

int check_colision(t_cube *data);
int rotate_line(int keycode, void *data);
int render_map(t_cube *data);
void lstaddback(t_map **head, char *content);
void *ft_malloc(size_t bytes, int action);
t_cube *initialize();
int get_window_size(t_cube *data);
void my_pixel_put(t_cube *data, int x, int y, int color);
void render_all(t_cube *data);
// gnl functions!!

unsigned int ft_strlen(char *str);
char *get_next_line(int fd);
int ft_strchr(char *s, int c);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strdup(char *string);
char *ft_substr(char *s, unsigned int start, size_t len);
void ft_bzero(void *address, size_t len);

#endif