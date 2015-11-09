#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int create_list(LIST **head, int num, int loop)
{
	LIST *temp = *head;
	int i = 0;
	for (i = 0; i < num; i++) {
		if (temp == NULL) {
			temp = malloc(sizeof(LIST));
			temp->next = NULL;
			temp->data = i;
			*head = temp;
		} else {
			while(temp->next != NULL)
				temp = temp->next;

			temp->next = malloc(sizeof(LIST));
			temp->next->next = NULL;
			temp->next->data = i;
		}
	}

	return 0;
}

int print_list(LIST *head)
{
	int i;
	for(i = 0; ; i++) {
		printf(" %d\t", head->data);
		head = head->next;
		if(head == NULL)
			break;
	}
	printf("\n");
	return 0;
}
int destroy_list(LIST **head)
{
	LIST *temp = *head;
	LIST *temp1 = temp;
	while(temp != NULL) {
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
	return 0;
}

LIST * create_loop(LIST **head, int num, int loop)
{
	LIST *temp = *head;
	LIST *temp2 = *head;
	int i = 0;
	for (i = 0; i < (num-loop); i++)
		temp = temp->next;
	
	while(temp2->next != NULL)
		temp2 = temp2->next;

	temp2->next = temp;
	printf("Created loop from %d to %d:temp2->next=%p, temp=%p\n", temp2->data, temp->data, temp2->next, temp);
	return temp2;
}
