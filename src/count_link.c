/*
** EPITECH PROJECT, 2018
** count_link
** File description:
** link
*/

#include "lemin.h"
#include "my.h"

int count_link(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}
