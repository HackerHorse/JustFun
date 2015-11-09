#ifndef LINK_HEADER__
#define LINK_HEADER__

typedef struct list_linked {
	int data;
	struct list_linked *next;
} LIST;

int create_list(LIST **, int, int);
int print_list(LIST *);
int destroy_list(LIST **);

LIST * create_loop(LIST **head, int num, int loop);

#define remove_loop(x) x->next = NULL
#endif
