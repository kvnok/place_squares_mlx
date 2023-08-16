#include "stuff.h"

int	int_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ok_calloc(int count, int size)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = count * size;
	ptr = (char *) malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	cleanup(char **line, char **buffer)
{
	free(*line);
	free(*buffer);
}

void	print_arr(char **arr)
{
	int i;

	i = 0;
	while(arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
