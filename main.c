#include "header.h"

int main()
{
    Student *head = NULL;
    char choice;
    char exit_choice;

    /* Load previously saved records */
    load_records(&head);

    while (1)
    {
        printf("\n");
        printf("******** STUDENT RECORD MENU ********\n");
        printf("\n");

        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("\nEnter your choice: ");

        scanf("%c", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
            case 'a':
            case 'A':
                add_record(&head);
                break;

            case 'd':
            case 'D':
                delete_record(&head);
                break;

            case 's':
            case 'S':
                show_records(head);
                break;

            case 'm':
            case 'M':
                modify_record(head);
                break;

            case 'v':
            case 'V':
                save_records(head);
                break;

            case 't':
            case 'T':
                sort_records(&head);
                break;

            case 'l':
            case 'L':
                delete_all(&head);
                break;

            case 'r':
            case 'R':
                reverse_list(&head);
                break;

            case 'e':
            case 'E':

                printf("\n");
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");

                scanf("%c", &exit_choice);
                while (getchar() != '\n');

                if (exit_choice == 'S' ||
                    exit_choice == 's')
                {
                    save_records(head);
                    delete_all(&head);

                    printf("Exiting program...\n");
                    return 0;
                }
                else if (exit_choice == 'E' ||
                         exit_choice == 'e')
                {
                    delete_all(&head);

                    printf("Exiting without saving...\n");
                    return 0;
                }
                else
                {
                    printf("Invalid choice. Returning to main menu\n");
                }

                break;

            default:
                printf("Invalid menu choice\n");
        }
    }

    return 0;
}