#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} Student;

void add_record(Student **head);

void delete_record(Student **head);
void delete_all(Student **head);

void show_records(Student *head);

void modify_record(Student *head);


void save_records(Student *head);
void load_records(Student **head);


void sort_records(Student **head);


void reverse_list(Student **head);

/* Utility functions */
void read_string(char *str, int size);
int read_int(void);
float read_float(void);

#endif