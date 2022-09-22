/*
** EPITECH PROJECT, 2018
** fill
** File description:
** struct
*/

#include "lemin.h"
#include "my.h"

void fill_struct(char **tab, s_parse *parse)
{
	int j = 0;

	parse->link = create_all_struct(tab, parse->link);
	while (tab[j] != NULL) {
		parse->link[j] = create_all_links(parse->link, \
tab[j], j, parse->nb_rooms);
		j++;
	}
}
