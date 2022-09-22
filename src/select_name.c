/*
** EPITECH PROJECT, 2018
** select_name
** File description:
** link
*/

#include "lemin.h"
#include "my.h"

char *select_name(char *str)
{
	int count = 0;
	char *select;

	for (int i = 0; str[i] != '\0' && str[i] != '-'; i++)
		count++;
	select = malloc(sizeof(char) * (count + 1));
	for (int i = 0; i < count; i++) {
		select[i] = str[i];
		if (i == count - 1)
			select[i + 1] = '\0';
	}
	return (select);
}
