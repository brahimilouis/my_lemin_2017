/*
** EPITECH PROJECT, 2017
** len
** File description:
** get
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemin.h"
#include "my.h"

Test(count_link, test_return_count_link)
{
	int     r_value = 0;

	r_value = count_link("a-a-a-a");
	cr_assert(r_value == 3);
	r_value = count_link("aezfuihzeofuze(-zeoifnzeof,");
	cr_assert(r_value == 1);
	r_value = count_link("a-efzefzefzefzefzefzeifzenze-fzefzefa-a");
	cr_assert(r_value == 3);
}

Test(select_link, test_return_select_name)
{
	char     *r_value = NULL;

	r_value = select_name("ab-a-a-a");
	cr_assert(my_strcmp(r_value, "ab") == 0);
	r_value = select_name("aezfuihzeofuze(-zeoifnzeof,");
	cr_assert(my_strcmp(r_value, "aezfuihzeofuze(") == 0);
	r_value = select_name("ab-efzefzefzefzefzefzeifzenze-fzefzefa-a");
	cr_assert(my_strcmp(r_value, "ab") == 0);
}

Test(strlen_line, test_return_strlen_backn)
{
	int     r_value = 0;

	r_value = my_strlen_line("a-a-a\n-a");
	cr_assert(r_value == 5);
	r_value = my_strlen_line("aezfuihz\neofuze(-zeoifnzeof,");
	cr_assert(r_value == 8);
	r_value = my_strlen_line("a-efzefzef\nzefzefzefzeifzenze-fzefzefa-a");
	cr_assert(r_value == 10);
}
