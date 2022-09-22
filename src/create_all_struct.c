/*
** EPITECH PROJECT, 2018
** create_all_struct
** File description:
** link
*/

#include "lemin.h"
#include "my.h"

link_t **create_all_struct(char **tab, link_t **link)
{
	int count_room = 0;

	for (int j = 0; tab[j] != NULL; j++)
		if (tab[j][0] != '#')
			count_room++;
	link = malloc(sizeof(link) * (count_room));
	for (int j = 0; tab[j] != NULL; j++)
		link[j] = create_link(select_name(tab[j]), count_link(tab[j]));
	return (link);
}
