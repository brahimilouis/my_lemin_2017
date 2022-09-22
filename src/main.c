/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** ...
*/

#include "my.h"
#include "lemin.h"

void	display_lemin(s_parse *st)
{
	my_printf("#number_of_ants\n%d\n", st->ants);
	if (st->verif == 1)
		return;
	my_putstr("#rooms\n");
	if (st->tunnels) {
		my_show_word_array(st->tab_rooms);
		my_putstr("\n#tunnels\n");
	} else
		my_putstr("#tunnels\n");
	if (st->tunnels) {
		my_show_word_array(st->tab_tunnels);
		my_putstr("\n#moves\n");
	} else
		my_putstr("#moves\n");
}

void	init_struct(s_parse *st)
{
	st->buffer = read_file();
	if (st->buffer == NULL)
		return;
	if (my_strstr(st->buffer, "##start") == 0 || \
my_strstr(st->buffer, "##end") == 0)
		st->verif = 1;
	else
		st->verif = 0;
	st->rooms = NULL;
	st->tunnels = NULL;
	st->ants = 0;
	st->i = 0;
}

void	lemin_main(s_parse *st)
{
	st->tab_tunnels = tab_without_comment(st->tunnels);
	display_lemin(st);
	if (st->verif == 1)
		return;
	find_start(st->tab_rooms, st);
	find_end(st->tab_rooms, st);
	fill_tab(st);
	fill_struct(st->tab, st);
	if (st->nb_rooms > 80)
		return;
	search_way(st);
	if (st->way[0] == NULL)
		return;
	move_disp(st->way, st->ants);
}

int	main(void)
{
	s_parse st;	

	init_struct(&st);
	if (st.buffer == NULL)
		return (84);
	my_ants(&st);
	st.rooms = my_rooms(&st);
	st.tunnels = my_tunnels(&st);
	if (st.rooms) {		
		st.tab_rooms = tab_without_comment(st.rooms);
		if (st.tunnels)
			lemin_main(&st);
		else
			display_lemin(&st);
	} else
		display_lemin(&st);
	return (0);
}
