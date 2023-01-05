#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int check_validity(char **arg, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		j = -1;
		if (arg[i][0] == '\0')
			return (2);
		while (arg[i][++j] != '\0')
		{
			if ((arg[i][j] < '0' || arg[i][j] > '9') && arg[i][j] != ' ' && arg[i][j] != '+' && arg[i][j] != '-')
				return (2);
		}
	}
	return (0);
}

void error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	check_nums(char **av, int ac)
{

}

// int *create_arr(int ac, char **av)
// {
// 	int *arr;
// 	arr = (int *)malloc(sizeof(int) * (ac - 1));

// 	if (!arr)
// 		return (0);
// 	int i;

// 	i = -1;
// 	av++;
// 	while (++i < ac - 1)
// 	{
// 		if (ft_atoi(av[i]) > INT_MAX)
// 			return (0);
// 		arr[i] = ft_atoi(av[i]);
// 		// printf("%d\n", arr[i]);
// 	}

// 	i = -1;
// 	while (++i < ac - 1)
// 		printf("%d\n", arr[i]);
// 	return (arr);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s_len;
	int		ss_len;

	if (!s1)
		return (NULL);
	s_len = ft_strlen(s1);
	ss_len = ft_strlen(s2);
	ptr = malloc(sizeof(*s1) * (s_len + ss_len + 1));
	if (!ptr)
		return (NULL);
	s_len = 0;
	ss_len = 0;
	while (s1[s_len] != '\0')
	{
		ptr[s_len] = s1[s_len];
		s_len++;
	}
	while (s2[ss_len] != '\0')
		ptr[s_len++] = s2[ss_len++];
	ptr[s_len] = '\0';
	return (ptr);
}

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	int i = 1;
	char *tmp = 0;
	char *arr = "";
	if (check_validity(av, ac) == 2)
		error_msg("ERROR\n");
	check_nums(av, ac);
	printf("OK\n");
}
