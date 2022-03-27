#include "test.h"

void print_ep_range(t_ep_range *range)
{
	if (range == NULL)
	{
		printf("range is NULL\n");
		return ;
	}
	printf("\tstart : %3d, end : %3d \n", range->start, range->end);
}

void	print_ep_rec(t_ep_rec *rec)
{
	t_ep_rec	*curr;

	curr = rec;
	if (curr == NULL)
	{
		printf("curr_rec : %p\n", curr);
		return;
	}
	while(curr)
	{
		printf("curr_rec : %p\n", curr);
		print_ep_range(curr->content);
		curr = curr->next;
	}
}
