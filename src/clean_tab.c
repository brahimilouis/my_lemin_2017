/*
** EPITECH PROJECT, 2018
** clean
** File description:
** ...
*/

#include "my.h"
#include "lemin.h"

char    **delete_line(char **tab, int y)
{
	while (tab[y + 1]) {
		free(tab[y]);
		tab[y] = my_strdup(tab[y + 1]);
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char    **modif_line(char **tab, int y)
{
	int     x = 0;

	while (tab[y][x])
		x++;
	while (tab[y][x] < 33 && x > 0) {
		tab[y][x] = '\0';
		x--;
	}
	return (tab);
}

char    **clean_tab_line(char **tab)
{
	int     y = 0;
	int     x = 0;

	while (tab[y]) {
		x = 2;
		while (tab[y][x]) {
			tab[y][x] == '#' ? tab[y][x] = '\0' : 0;
			x++;
		}
		tab = modif_line(tab, y);
		y++;
	}
	return (tab);
}

char    **tab_without_comment(char *str)
{
	int     y = 0;
	char    **tab = my_str_to_word_array(str, "\n");

	while (tab[y]) {
		if (tab[y][0] == '#' && tab[y][1] != '#') {
			tab = delete_line(tab, y);
		}
		y++;
	}
	tab = clean_tab_line(tab);
	tab[y] = NULL;
	return (tab);
}
