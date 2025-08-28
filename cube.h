#ifndef CUBE_H
#define CUBE_H
#include <X11/keysym.h>
#include "mlx.h"
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define TILE 40
#define ERROR -1
#define FREE 1
#define ALLOC 0
#define MOVE_SPEED 10
#define BUFFER_SIZE 10
#define M_PI 3.14159265358979323846

#define LOOKUP(angle) (angle < M_PI)
#define LOOKDOWN(angle) (angle > M_PI)
#define RIGHT(angle) ((angle < 0.5 * M_PI) || (angle > 1.5 * M_PI))
#define LEFT(angle) ((angle > 0.5 * M_PI) && (angle < 1.5 * M_PI))

#define RSPEED (2 * M_PI / 180)
#define MOVE 20

typedef struct s_alloc
{
    void *pointer;
    struct s_alloc *next;
} t_alloc;

typedef struct s_dis_tools
{
    double Ahx;
    double Ahy;
    double Avx;
    double Avy;
    double xhstep;
    double yhstep;
    double xvstep;
    double yvstep;
    double HwallHitX;
    double HwallHitY;
    double VwallHitX;
    double VwallHitY;
    double next_horz_touch_x;
    double next_horz_touch_y;
} t_dis_tools;

typedef struct s_cube
{
    char **map;
    t_dis_tools *dis;
    void *mlx;
    void *win;
    void *img;
    char *addr;
    double fov;
    double r_speed;
    double angle;
    double WallDis;
    double WallStripH;
    double px;
    double py;
    int width;
    int height;
    int pxt;
    int pyt;
    int bpp;
    int line_len;
    int endian;
} t_cube;

void *ft_malloc(size_t bytes, int action);
void my_pixel_put(t_cube *data, int x, int y, unsigned int color);
void render_all(t_cube *data);
void draw_fov(t_cube *data);
void find_distance(t_cube *data, double angle);
void wallStripHeight(t_cube *data, double angle);
void wall_hit_cords(t_cube *data);
t_cube *initialize();
double normalizeAngle(double angle);
double distance(t_cube *data);
int key_check(int key, void *ptr);
int render_2Dmap(t_cube *data);
int get_window_size(t_cube *data);
int check_colision(t_cube *data, int px, int py);
int render_2Dmap(t_cube *data);

// gnl functions!!

void ft_bzero(void *address, size_t len);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *get_next_line(int fd);
char *ft_strdup(char *string);
char *ft_substr(char *s, unsigned int start, size_t len);
unsigned int ft_strlen(char *str);
int ft_strchr(char *s, int c);

#endif