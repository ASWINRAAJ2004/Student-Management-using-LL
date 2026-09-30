#include "header.h"

static void sort_by_name(Student *head)
{
    Student *i;
    Student *j;

    int roll;
    float percentage;
    char name[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(i->name, j->name) > 0)
            {
                roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = percentage;
            }
        }
    }
}

static void sort_by_percentage(Student *head)
{
    Student *i;
    Student *j;

    int roll;
    float percentage;
    char name[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->percentage < j->percentage)
            {
                roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = percentage;
            }
        }
    }
}

void sort_records(Student **head)
{
    char choice;

    if (*head == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("\n");
    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter choice: ");

    scanf("%c", &choice);
    while (getchar() != '\n');

    switch (choice)
    {
        case 'N':
        case 'n':
            sort_by_name(*head);
            printf("Records sorted alphabetically by name\n");
            break;

        case 'P':
        case 'p':
            sort_by_percentage(*head);
            printf("Records sorted by percentage in descending order\n");
            break;

        default:
            printf("Invalid choice\n");
    }
}