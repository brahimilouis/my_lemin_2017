/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** ...
*/

#include "my.h"
#include "lemin.h"

char    *read_file(void)
{
	char    *res = "\0";
	char    *buffer;
	int	i = 0;

	while ((buffer = get_next_line(0)) != NULL) {
		res = my_strcat(res, buffer);
		res = my_strcat(res, "\n");
	}
	if (my_strlen(res) < 1)
		return (NULL);
	i = my_strlen(res);
	res[i - 1] = '\0';
	return (res);
}
