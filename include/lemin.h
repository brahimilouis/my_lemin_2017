/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** ...
*/

#ifndef _LEMIN_H_

#define _LEMIN_H_
# define _LEMIN_H_

#include "my.h"
#include "get_next_line.h"

typedef  struct  link
{
	char *name;
	int id;
	struct  link **next;
	int nb_link;
	int check;
} link_t;

typedef struct parse
{
	int verif;
	char *start;
	char *end;
	char *buffer;
	char *rooms;
	char *tunnels;
	char **tab_rooms;
	char **tab_tunnels;
	int ants;
	int i;
	char **tab;
	link_t **link;
	int nb_rooms;
	char **way;
} s_parse;

void connects_links(link_t *link1, link_t *link2, int i);
link_t *create_all_links(link_t **link, char *line, int j, int nb_rooms);
int count_link(char *str);
link_t **create_all_struct(char **tab, link_t **link);
void fill_struct(char **tab, s_parse *parse);
char *select_name(char *str);
void found_way(link_t *link, s_parse *parse, int nb, int verif);
link_t *create_link(char *name, int nb_link);
char **fill_tunnels_tab(char **tunnels, char **tab);
void fill_tab(s_parse *st);
char **fill_tunnels_rooms(char **tab_rooms, char **tab);
void my_ants(s_parse *st);
int my_strlen_line(char	*buffer);
char *my_tunnels(s_parse *st);
char *my_rooms(s_parse *st);
void search_way(s_parse *parse);
char *read_file(void);
void find_start(char **tab, s_parse *st);
void find_end(char **tab, s_parse *st);
void move_disp(char **tab, int i);
void disp(int *rooms, char **tab);
void my_algo(int i, char**tab, int *rooms);
int *erase_first_rooms(int *rooms);
int *first_rooms(int *rooms, int i, int ants);
int *swap_rooms2(int *rooms);
int *swap_rooms(int *rooms);
void disp_tab(char **tab);
int find_rooms(char **tab);
int *meme_set(int *rooms, int i);
char    **delete_line(char **tab, int y);
char    **modif_line(char **tab, int y);
char    **clean_tab_line(char **tab);
char    **tab_without_comment(char *str);

#endif /* _LEMIN_H_ */
