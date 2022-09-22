/*
1;4803;0c** EPITECH PROJECT, 2018
** find
** File description:
** end
*/

#include "my.h"
#include "lemin.h"

void find_end(char **tab, s_parse *st)
{
	int x =	0;
	int y =	0;

	while (my_strcmp("##end", tab[y]) != 0)
		y++;
	y++;
	while (tab[y][x] != ' ')
		x++;
	st->end = malloc(sizeof(char) * x + 1);
	x = 0;
	while (tab[y][x] != ' ') {
		st->end[x] = tab[y][x];
		x++;
	}
	st->end[x] = '\0';
}
