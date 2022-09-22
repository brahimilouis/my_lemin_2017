/*
** EPITECH PROJECT, 2018
** create
** File description:
** all_links
*/

#include "lemin.h"
#include "my.h"

int check_name(char *str, link_t **link, int nb_rooms)
{
	int j = 0;
	int count = 0;

	for (int k = 0; str[k] != '\0' && str[k] != '-'; k++)
		count++;
	while (j != nb_rooms){
		if (my_strncmp(str, link[j]->name, \
my_strlen(link[j]->name)) == 0)
			return (j);
		j++;
	}
	return (0);
}

link_t *create_all_links(link_t **link, char *line, int j, int nb_rooms)
{
	int i = 0;
	int x = 0;

	while (line[i] != '\0') {
		while (line[i] != '\0' && line[i] != '-')
			i++;
		if (line[i] == '\0')
			return (link[j]);
		i++;
		connects_links(link[j], link[check_name(&line[i], \
link, nb_rooms)], x);
		x++;
	}
	return (link[j]);
}
