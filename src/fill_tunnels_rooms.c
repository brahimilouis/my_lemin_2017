/*
** EPITECH PROJECT, 2018
** fill
** File description:
** tunnels
*/

#include "lemin.h"

char **malloc_tab(char **tab, char **tab_rooms)
{
	int i = 0;
	int j =	0;

	while (tab_rooms[i] != NULL) {
		if (tab_rooms[i][0] == '#')
			j++;
		i++;
	}
	tab = malloc(sizeof(char *) * (i - j + 1));
	return (tab);
}

char **fill_tunnels_rooms(char **tab_rooms, char **tab)
{
	int i = 0;
	int j = 0;
	int x = 0;

	tab = malloc_tab(tab, tab_rooms);
	while (tab_rooms[j] != NULL) {
		while (tab_rooms[j][i] != '\0' && tab_rooms[j][i] != ' ')
			i++;
		if (tab_rooms[j][0] != '#') {
			tab[x] = malloc(sizeof(char) * \
(my_strlen(tab_rooms[j]) + 1));
			tab[x] = my_strncpy(tab[x], tab_rooms[j], i);
			x++;
		}
		i = 0;
		j++;
	}
	tab[x] = NULL;
	return (tab);
}
