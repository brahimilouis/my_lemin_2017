/*
** EPITECH PROJECT, 2018
** find
** File description:
** start_end
*/

#include "my.h"
#include "lemin.h"

void find_start(char **tab, s_parse *st)
{
	int x = 0;
	int y = 0;

	while (my_strcmp("##start", tab[y]) != 0)
		y++;
	y++;
	while (tab[y][x] != ' ')
		x++;
	st->start = malloc(sizeof(char) * x + 1);
	x = 0;
	while (tab[y][x] != ' ') {
		st->start[x] = tab[y][x];
		x++;
	}
	st->start[x] = '\0';
}
