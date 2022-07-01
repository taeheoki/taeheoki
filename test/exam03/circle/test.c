#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	str_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	char	*image;
	int		read;

	// 배경
	int		b_width;
	int		b_height;
	char	b_char;
	int		x;
	int		y;

	// 도형
	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	c_char;
	float	distance;

	if (argc != 2)
		return str_error("Error: argument\n");
	if (!(file = fopen(argv[1], "r")))
		return str_error("Error: Operation file corrupted\n");
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
		return str_error("Error: Operation file corrupted\n");
	if (!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300))
		return str_error("Error: Operation file corrupted\n");
	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(image, b_char, b_width * b_height);
}