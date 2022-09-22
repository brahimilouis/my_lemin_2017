/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** ...
*/

#include "my.h"
#include "lemin.h"

int	my_strlen_line(char *buffer)
{
	int	i = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

void	my_ants(s_parse *st)
{
	char	*res;
	int	j = 0;

	while (st->buffer[st->i] == '#' && st->buffer[st->i + 1] != '#'\
&& st->buffer[st->i]) {
		while (st->buffer[st->i] && st->buffer[st->i] != '\n')
			st->i++;
		st->i += 1;
	}
	res = malloc(sizeof(char) * my_strlen_line(st->buffer) + 1);
	while (st->buffer[st->i] != '\n' && st->buffer[st->i]) {
		res[j] = st->buffer[st->i];
		st->i++;
		j++;
	}
	res[j] = '\0';
	if ((st->ants = my_getnb(res)) <= 0)
		for (st->i--; st->buffer[st->i] != '\n' && st->i > 0; st->i--);
}

int	next_is_tunnels(char *str, int i)
{
	while (str[i] && str[i] != '\n') {
		if (str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

char	*my_rooms(s_parse *st)
{
	int	j = 0;
	char	*res;

	res = malloc(sizeof(char) * my_strlen(st->buffer) + 1);
	while (st->buffer[st->i] != '\n')
		st->i++;
	while (next_is_tunnels(st->buffer, st->i + 1) == 1) {
		res[j] = st->buffer[st->i];
		st->i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*my_tunnels(s_parse *st)
{
	int	j = 0;
	char	*res;
	int	x = 0;
	int	pipe = 0;

	while (st->buffer[x]) {
		st->buffer[x] == '-' ? pipe++ : 0;
		x++;
	}
	if (pipe == 0)
		return (NULL);
	res = malloc(sizeof(char) * my_strlen(st->buffer) + 1);
	while (next_is_tunnels(st->buffer, st->i) == 1)
		st->i++;
	while (st->buffer[st->i] != '\0' && st->buffer[st->i]) {
		res[j] = st->buffer[st->i];
		st->i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
