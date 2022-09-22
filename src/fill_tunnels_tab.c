/*
** EPITECH PROJECT, 2018
** fill_tunnel
** File description:
** tab
*/

#include "lemin.h"

char *add_room(char *str, char *tunnels, int i)
{
	int size = my_strlen(str);
	char *str_cpy = malloc(sizeof(char) * (size + 1));
	int nb = 0;
	
	while (tunnels[nb] != '\0')
		nb++;
	str_cpy = my_strcpy(str_cpy, str);
	free(str);
	str = malloc(sizeof(char) * (size + nb + 2));
	str = my_strcpy(str, str_cpy);
	for (int j = i; tunnels[j] != '\0'; j++) {
		str[size] = tunnels[j];
		size++;
	}
	str[size] = '\0';
	free(str_cpy);
	return (str);
}

char **fill_tunnels_tab(char **tunnels, char **tab)
{
	int j = 0;
	int i = 0;
	int x = 0;

	while (tab[j] != NULL) {
		while (tunnels[x][i] != '\0' && tunnels[x][i] != '-')
			i++;
		if (my_strncmp(tab[j], tunnels[x], i) == 0)
			tab[j] = add_room(tab[j], tunnels[x], i);
		x++;
		i = 0;
		if (tunnels[x] == NULL) {
			x = 0;
			j++;
		}
	}
	return (tab);
}
