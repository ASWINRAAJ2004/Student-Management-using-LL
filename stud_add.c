#include "header.h"

static int generate_rollno(Student *head)
{
    int roll = 1;
    Student *temp;

    while (1)
    {
        temp = head;

        while (temp)
        {
            if (temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if (temp == NULL)
            return roll;

        roll++;
    }
}

void add_record(Student **head)
{
    Student *newnode;
    Student *temp;
    int roll;

    newnode = malloc(sizeof(Student));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    roll = generate_rollno(*head);

    newnode->rollno = roll;

    do
    {
        printf("Enter student name: ");
        read_string(newnode->name, sizeof(newnode->name));

        if (strlen(newnode->name) == 0)
            printf("Name cannot be empty\n");

    } while (strlen(newnode->name) == 0);

    do
    {
        printf("Enter percentage: ");
        newnode->percentage = read_float();

        if (newnode->percentage < 0.0 ||
            newnode->percentage > 100.0)
        {
            printf("Percentage must be between 0 and 100\n");
        }

    } while (newnode->percentage < 0.0 ||
             newnode->percentage > 100.0);

    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("\nRecord added successfully\n");
}