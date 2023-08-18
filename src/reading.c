#include "stuff.h"

char	*strjoin_free(char **s1, char **s2)
{
	int		s1len;
	int		s2len;
	int		i;
	char	*s3;

	s1len = int_strlen(*s1);
	s2len = int_strlen(*s2);
	i = 0;
	s3 = ok_calloc((s1len + s2len + 1), 1);
	if (s3 == NULL)
		return (NULL);
	while (i < s1len + s2len)
	{
		if (i < s1len)
			s3[i] = (*s1)[i];
		else
			s3[i] = (*s2)[i - s1len];
		i++;
	}
	s3[i] = '\0';
	free(*s1);
	return (s3);
}

int		reading(int fd, char **buffer, char **line)
{
	int			amount;

	amount = 1;
	while (amount != 0)
	{
		// printf("1\n");
		amount = read(fd, *buffer, BUFFER_SIZE);
		// printf("2\n");
		if (amount <= -1)
		{
			printf("DEBUG : amount <= -1\n");
			return -1;
		}
		// printf("3\n");
		if (amount == 0)
			break ;
		// printf("4\n");
		*line = strjoin_free(line, buffer);
		// printf("5\n");
		if (*line == NULL)
		{
			printf("DEBUG : line == NULL\n");
			return -1;
		}
		// printf("6\n");
	}
	return 0;
}

int player_check(t_data *data, char *line)
{
	int i;
	int flag;

	i = 0;
	flag = -1;
	while(line[i] != '\0')
	{
		if (line[i] == 'P')
		{
			if (flag != -1)
			{
				return -1;
			}
			flag = i;
		}
		i++;
	}
	return flag;
}

int map_parser(char *str, t_data *data)
{
	int			fd;
	char		*buffer;
	char		*line;

	buffer = NULL;
	line = NULL;
	buffer = ok_calloc((BUFFER_SIZE + 1), 1);
	line = ok_calloc((BUFFER_SIZE + 1), 1);
	fd = open(str, O_RDWR, O_CREAT);
	if (reading(fd, &buffer, &line) == -1)
	{
		cleanup(&line, &buffer);
		return 1;
	}
	// printf("total : \n%s\n", line);
	data->map = ft_split(line, '\n');
	data->player_i = player_check(data, line);
	if (data->player_i == -1)
	{
		cleanup(&line, &buffer);
		return 1;
	}
	cleanup(&line, &buffer);
	if (data->map == NULL)
	{
		return 1;
	}
	print_arr(data->map);
	// free_strings(data->map);
	return 0;
}
