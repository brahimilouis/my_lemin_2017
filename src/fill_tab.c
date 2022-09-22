/*
** EPITECH PROJECT, 2018
** fill_tab
** File description:
** tab
*/

#include "lemin.h"

char *invert_str(char *str)
{
	int size = 0;
	char *cpy;

	while (str[size] != '\0' && str[size] != '-')
		size++;
	if (str[size] == '\0')
		return (str);
	cpy = malloc(sizeof(char) * (size + 1));
	cpy = my_strncpy(cpy, str, size);
	str = my_strcpy(str, &str[size + 1]);
	str[size] = '-';
	str[size + 1] = '\0';
	str = my_strcat(str, cpy);
	free(cpy);
	return (str);
}

char **change_tab_rooms(char **tab)
{
	int size_tab = 0;
	char **tab2;
	int i = 0;

	while (tab[size_tab] != NULL)
		size_tab++;
	tab2 = malloc(sizeof(char *) * (size_tab + size_tab + 1));
	for (;tab[i] != NULL; i++) {
		tab2[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
		tab2[i] = my_strcpy(tab2[i], tab[i]);
	}
	for (int j = 0; tab[j] != NULL; j++) {
		tab2[i] = malloc(sizeof(char) * (my_strlen(tab[j]) + 1));
		tab2[i] = my_strcpy(tab2[i], invert_str(tab[j]));
		i++;
	}
	for (int j = 0; tab[j] != NULL; j++)
		free(tab[j]);
	tab2[i] = NULL;	
	return (tab2);
}

void fill_tab(s_parse *st)
{
	int i = 0;
	int count = 0;

	st->tab_tunnels = change_tab_rooms(st->tab_tunnels);
	st->tab = fill_tunnels_rooms(st->tab_rooms, st->tab);
	st->tab = fill_tunnels_tab(st->tab_tunnels, st->tab);
	while (st->tab[i] != NULL) {
		if (st->tab[i][0] != '#')
			count++;
		i++;
	}
	st->nb_rooms = count;
}
