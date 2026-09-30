#include "header.h"

void save_records(Student *head)
{
    FILE *fp;
    Student *temp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("Unable to open student.dat for writing\n");
        return;
    }

    temp = head;

    while (temp)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully to student.dat\n");
}

void load_records(Student **head)
{
    FILE *fp;
    Student *newnode;
    Student *temp;
    char line[150];

    fp = fopen("student.dat", "r");

    if (fp == NULL)
    {
        /* File doesn't exist */
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        newnode = malloc(sizeof(Student));

        if (newnode == NULL)
        {
            printf("Memory allocation failed while loading records\n");
            fclose(fp);
            return;
        }

        newnode->next = NULL;

        if (sscanf(line,
                   "%d|%49[^|]|%f",
                   &newnode->rollno,
                   newnode->name,
                   &newnode->percentage) != 3)
        {
            free(newnode);
            continue;
        }

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
    }

    fclose(fp);
}