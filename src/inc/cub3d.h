#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data
{
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    int floor_color[4];
    int ceiling_color[4];
} t_data;

