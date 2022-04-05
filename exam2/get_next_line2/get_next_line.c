#include "get_next_line.h"
#include <stdio.h>

char	*ft_strndup(char *s, int n)
{
	int	i;
	char	*ptr;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	s1_len;
	int	s2_len;
	char	*ptr;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		ptr[i] = s2[i - s1_len];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if ((char)c == 0)
		return (s + i);
	else
		return (NULL);
}

int	get_next_line(char **line)
{
	static char	*backup;
	char		*buf;
	char		*temp;
	char		*n_ptr;
	int			read_size;

	if (!(buf = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	if (!backup)
	{
		backup = ft_strndup("", 0);
		while ((read_size = read(0, buf, 1)) > 0)
		{
			buf[read_size] = '\0';
			temp = backup;
			backup = ft_strjoin(backup, buf);
			free(temp);
		}
	}
	free(buf);
	n_ptr = ft_strchr(backup, '\n');
	if (n_ptr)
	{
		*line = ft_strndup(backup, n_ptr - backup);
		backup += n_ptr - backup + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(backup, ft_strchr(backup, '\0') - backup);
		return (0);
	}
}

int	main(void)
{
	char 	*line;
	int	ret;

	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d %s\n", ret, line);
	free(line);
	while (1)
	{
	}
}