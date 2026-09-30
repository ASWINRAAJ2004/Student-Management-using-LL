#include "header.h"

void reverse_list(Student **head)
{
    Student *prev;
    Student *current;
    Student *next;

    if (*head == NULL)
    {
        printf("No student records available\n");
        return;
    }

    prev = NULL;
    current = *head;

    while (current)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    *head = prev;

    printf("List reversed successfully\n");
}