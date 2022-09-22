/*
** EPITECH PROJECT, 2018
** find
** File description:
** way
*/

#include "lemin.h"

void return_back(s_parse *parse, int nb)
{
	int i = 0;

	if (parse->way[0] == NULL)
		return;
	while (my_strcmp(parse->way[nb], parse->link[i]->name) != 0)
		i++;
	if (parse->link[i]->check < parse->link[i]->nb_link - 1) {
		parse->link[i]->id = 0;
		parse->link[i]->check++;
		free(parse->way[nb]);
		found_way(parse->link[i], parse, nb, 1);
		return;
	} else {
		free(parse->way[nb]);
		parse->way[nb] = NULL;
		parse->link[i]->id = 0;
		parse->link[i]->check = 0;
		return_back(parse, nb - 1);
	}
}

void found_way(link_t *link, s_parse *parse, int nb, int verif)
{
	if (parse->way[0] == NULL && verif == 1)
		return;
	if (my_strcmp(link->name, parse->end) != 0) {
		if (link->id == 0)
			link->id = 1;
		else {
			return_back(parse, nb - 1);
			return;
		}
		parse->way[nb] = malloc(sizeof(char) * (my_strlen(link->name) + 1));
		parse->way[nb] = my_strcpy(parse->way[nb], link->name);
		nb++;
		found_way(link->next[link->check], parse, nb, 0);
		return;
	} else {
		parse->way[nb] = malloc(sizeof(char) * (my_strlen(link->name) + 1));
		parse->way[nb] = my_strcpy(parse->way[nb], link->name);
		return;
	}
}

void search_way(s_parse *parse)
{
	int i = 0;

	parse->way = malloc(sizeof(char *) * (parse->nb_rooms + 1));
	for (int j = 0; j < parse->nb_rooms + 1; j++)
		parse->way[j] = NULL;
	while (my_strcmp(parse->start, parse->link[i]->name) != 0)
		i++;
	found_way(parse->link[i], parse, 0, 0);
}
