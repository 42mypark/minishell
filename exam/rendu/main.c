#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef	struct	s_map
{
	int	width;
	int	height;
	char	back_char;
	char	*space;
}		t_map;

int	put_strerror(char *msg)
{
	while (*msg)
		write(1, msg++, 1);
	return (1);
}

int	gen_map(FILE *file, t_map *map)
{
	if (fscanf(file, "%d %d %c\n", &map->width, &map->height, &map->back_char) != 3)
		return (0);
	if (map->width <= 0 || map->width > 300 || map->height <= 0 || map->height > 300)
		return (0);
	map->space = malloc(sizeof(char) * map->width * map->height);
	if (map->space == NULL)
		return (0);
	memset(map->space, map->back_char, map->width * map->height);
	return (1);
}

int	clear_all(FILE *file, t_map *map, char *str)
{
	if (file)
		fclose(file);
	if (str)
		put_strerror(str);
	if (map->space)
		free(map->space);
	return (1);
}

typedef struct	s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	c;
}		t_circle;

int	in_circle(float x, float y, float cx, float cy, float cr, char type)
{
	float distance = sqrtf(powf(cx - x, 2.0) + powf(cy - y, 2.0));
	if (type == 'C' && distance < cr)
		return 1;
	if (type == 'c' && (cr - distance) < 1.000000 && cr - distance > 0)
	       return 1;
	return (0);
}

int	put_circle_on_map(FILE *file, t_map *map)
{
	t_circle cir;
	float	x;
	float	y;
	int	ret;

	while((ret = fscanf(file, "%c %f %f %f %c\n", &cir.type, &cir.x, &cir.y, &cir.r, &cir.c )) == 5)
	{
		for (int i = 0; i < map->width * map->height; i++)
		{
			x = (float)(i / map->width);
			y = (float)(i % map->width);
			if (in_circle(x,y,cir.x,cir.y,cir.r, cir.type))
				map->space[i] = cir.c;
		}
	}
	if (ret != EOF)
		return (0);
	return (1);
}

void	print_map(t_map *map)
{
	for(int i = 0; i < map->height * map->width ; i+=map->width)
	{
		write(1, map->space + i, map->width);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	FILE *file;
	t_map	map;

	map.space = NULL;
	if(argc != 2)
		return (put_strerror("Error: argument\n"));
        if(!(file = fopen(argv[1], "r")))
		return (put_strerror("Error: Operation file corrupted\n"));
	if (!gen_map(file, &map))
		return (clear_all(file, &map, "Error: Operation file corrupted\n"));
	if (!put_circle_on_map(file, &map))
		return (clear_all(file, &map, "Error: Operation file corrupted\n"));
	print_map(&map);
	return (0);
}

