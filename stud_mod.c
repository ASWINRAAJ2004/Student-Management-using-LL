#include "header.h"

static void modify_student(Student *temp)
{
    char name[50];
    float percentage;

    printf("\nCurrent Details\n");
    printf("Roll No    : %d\n", temp->rollno);
    printf("Name       : %s\n", temp->name);
    printf("Percentage : %.2f\n", temp->percentage);

    do
    {
        printf("\nEnter new name: ");
        read_string(name, sizeof(name));

        if (strlen(name) == 0)
            printf("Name cannot be empty\n");

    } while (strlen(name) == 0);

    do
    {
        printf("Enter new percentage: ");
        percentage = read_float();

        if (percentage < 0 || percentage > 100)
            printf("Percentage must be between 0 and 100\n");

    } while (percentage < 0 || percentage > 100);

    strcpy(temp->name, name);
    temp->percentage = percentage;

    printf("Record modified successfully\n");
}

static Student *find_by_roll(Student *head, int roll)
{
    while (head)
    {
        if (head->rollno == roll)
            return head;

        head = head->next;
    }

    return NULL;
}

static void modify_by_name(Student *head)
{
    char name[50];
    Student *temp;
    int found = 0;
    int roll;

    printf("Enter name to search: ");
    read_string(name, sizeof(name));

    temp = head;

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
        printf("No record found\n");
        return;
    }

    printf("Enter roll number to modify: ");
    roll = read_int();

    temp = find_by_roll(head, roll);

    if (temp == NULL)
    {
        printf("Record not found\n");
        return;
    }

    if (strcmp(temp->name, name) != 0)
    {
        printf("Selected roll number does not belong to the searched name\n");
        return;
    }

    modify_student(temp);
}

static void modify_by_percentage(Student *head)
{
    float percentage;
    Student *temp;
    int found = 0;
    int roll;

    printf("Enter percentage to search: ");
    percentage = read_float();

    temp = head;

    while (temp)
    {
        if (temp->percentage == percentage)
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
        printf("No record found\n");
        return;
    }

    printf("Enter roll number to modify: ");
    roll = read_int();

    temp = find_by_roll(head, roll);

    if (temp == NULL)
    {
        printf("Record not found\n");
        return;
    }

    if (temp->percentage != percentage)
    {
        printf("Selected roll number does not match the searched percentage\n");
        return;
    }

    modify_student(temp);
}

void modify_record(Student *head)
{
    char choice;
    int roll;
    Student *temp;

    if (head == NULL)
    {
        printf("No student records available\n");
        return;
    }

    printf("\n");
    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter choice: ");

    scanf("%c", &choice);
    while (getchar() != '\n');

    switch (choice)
    {
        case 'R':
        case 'r':

            printf("Enter roll number: ");
            roll = read_int();

            temp = find_by_roll(head, roll);

            if (temp == NULL)
            {
                printf("Record not found\n");
                return;
            }

            modify_student(temp);
            break;

        case 'N':
        case 'n':
            modify_by_name(head);
            break;

        case 'P':
        case 'p':
            modify_by_percentage(head);
            break;

        default:
            printf("Invalid choice\n");
    }
}