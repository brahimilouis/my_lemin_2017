/*
** EPITECH PROJECT, 2018
** connects
** File description:
** link
*/

#include "lemin.h"

void connects_links(link_t *link1, link_t *link2, int i)
{
	if (link1 == NULL || link2 == NULL)
		return;
	link1->next[i] = link2;
}
