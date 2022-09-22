/*
** EPITECH PROJECT, 2018
** find
** File description:
** room
*/

#include "my.h"
#include "lemin.h"

int     *meme_set(int *rooms, int i)
{
	i--;
	rooms[i] = -1;
	i--;
	while (i != 0) {
		rooms[i] = 0;
		i--;
	}
	return (rooms);
}

int     find_rooms(char **tab)
{
	int     i = 0;

	while (tab[i] != NULL) {
		i++;
	}
	return (i);
}

void disp_tab(char **tab)
{
	int i = 0;

	while (tab[i] != NULL) {
		my_putstr(tab[i]);
		i++;
	}
}

int *swap_rooms(int *rooms)
{
	int i = 0;

	while (rooms[i] != -1)
		i++;
	i = i - 2;
	while (i != -1) {
		if (rooms[i] != 0)
			rooms[i + 1] = rooms[i];
		i--;
	}
	return (rooms);
}

int *swap_rooms2(int *rooms)
{
	int i = 0;

	while (rooms[i] != -1)
		i++;
	i = i - 2;
	while (i != -1) {
		rooms[i + 1] = rooms[i];
		i--;
	}
	return (rooms);
}
