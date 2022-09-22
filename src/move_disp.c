/*
** EPITECH PROJECT, 2018
** move
** File description:
** disp
*/

#include "my.h"
#include "lemin.h"

int *first_rooms(int *rooms, int i, int ants)
{
	i = ants - i;
	rooms[0] = i;
	return (rooms);
}

int *erase_first_rooms(int *rooms)
{
	rooms[0] = -42;
	return (rooms);
}

void my_algo(int i, char**tab, int *rooms)
{
	int ants = i;

	while (i != 0) {
		i--;
		rooms = swap_rooms(rooms);
		rooms = first_rooms(rooms, i, ants);
		disp(rooms, tab);
		my_putchar('\n');
	}
	while (rooms[i] != -1)
		i++;
	i--;
	while (rooms[i] != -42) {
		rooms = swap_rooms2(rooms);
		rooms = erase_first_rooms(rooms);
		disp(rooms, tab);
		if (rooms[i] != 0 && rooms[i] != -42)
			my_putchar('\n');
	}
}

void disp(int *rooms, char **tab)
{
	int i = 0;

	while (rooms[i] != -1)
		i++;
	i--;
	while (i != -1) {
		if (rooms[i] != 0 && rooms[i] != -42) {
			my_putchar('P');
			my_put_nbr(rooms[i]);
			my_putchar('-');
			my_putstr(tab[i]);
			my_putchar(' ');
		}
		i--;
	}
}

void move_disp(char **tab, int i)
{
	int *rooms = NULL;
	int nb = 0;

	tab = delete_line(tab, 0);
	nb = find_rooms(tab);
	rooms = malloc(sizeof(int) * (nb + 1));
	rooms = meme_set(rooms, (nb + 1));
	my_algo(i, tab, rooms);
}
