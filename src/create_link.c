/*
** EPITECH PROJECT, 2018
** create_link
** File description:
** link
*/

#include "lemin.h"

link_t *create_link(char *name, int nb_link)
{
	link_t *st;

	st = malloc(sizeof(*st));
	if (st != NULL) {
		st->name = malloc(sizeof(char) * (my_strlen(name) + 1));
		st->name = my_strcpy(st->name, name);
		st->nb_link = nb_link;
		st->next = malloc(sizeof(*st->next) * (nb_link));
		st->id = 0;
		st->check = 0;
	}
	return (st);
}
