#include <stdio.h>

#include "list.h"

int detect_loop(LIST *head);

int main(int args, char *argv[])
{
	int num = atoi(argv[1]);
	int loop = atoi(argv[2]);
	LIST * ret = NULL;
	LIST *head = NULL;
	create_list(&head, num, loop);
	print_list(head);

	ret = create_loop(&head, num, loop);
	detect_loop(head);
	remove_loop(ret);
	destroy_list(&head);
	return 0;
}

int detect_loop(LIST *head)
{
	LIST *turtle = head;
	LIST *hare = head->next;
	int count = 0;
	printf("Tortoise\tHare\n");
	while(hare != turtle) {
		printf("%d-%p\t%d-%p\n", turtle->data, turtle, hare->data, hare);
		turtle = turtle->next;
		hare = hare->next->next;
		count++;
	}

	printf("Loop detected after %d\n", count);
	return 0;
}
