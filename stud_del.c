#include "header.h"

static void delete_by_roll(Student **head, int roll)
{
    Student *temp;
    Student *prev;

    temp = *head;
    prev = NULL;

    while (temp)
    {
        if (temp->rollno == roll)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Record deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Roll number %d not found\n", roll);
}

static void delete_by_name(Student **head)
{
    char name[50];
    Student *temp;
    int found = 0;
    int roll;

    printf("Enter name to search: ");
    read_string(name, sizeof(name));

    temp = *head;

    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                   temp->rollno,
                   temp->name,
                   temp->percentage);

            found = 1;
        }

        temp = temp->next;
    }

    if (!found)
    {
        printf("No record found with name \"%s\"\n", name);
        return;
    }

    printf("Enter roll number of record to delete: ");
    roll = read_int();

    delete_by_roll(head, roll);
}

void delete_record(Student **head)
{
    char choice;
    int roll;

    if (*head == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("\n");
    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter choice: ");

    scanf("%c", &choice);
    while (getchar() != '\n');

    switch (choice)
    {
        case 'R':
        case 'r':
            printf("Enter roll number to delete: ");
            roll = read_int();

            if (roll <= 0)
            {
                printf("Roll number must be positive\n");
                return;
            }

            delete_by_roll(head, roll);
            break;

        case 'N':
        case 'n':
            delete_by_name(head);
            break;

        default:
            printf("Invalid choice\n");
    }
}

void delete_all(Student **head)
{
    Student *temp;

    if (*head == NULL)
    {
        printf("No records to delete\n");
        return;
    }

    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;

    printf("All records deleted successfully\n");
}