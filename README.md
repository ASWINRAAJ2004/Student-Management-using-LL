STUDENT RECORD MANAGEMENT SYSTEM
================================

Mini Project - II
C Programming

DESCRIPTION
-----------

This project implements a Student Record Management System
using a singly linked list and dynamic memory allocation.

Each student record contains:

1. Roll Number
2. Name
3. Percentage

FEATURES
--------

1. Add new record
2. Delete record by roll number
3. Delete record by name
4. Display all records
5. Modify record by roll number
6. Modify record by name
7. Modify record by percentage
8. Save records
9. Load records
10. Sort by name
11. Sort by percentage
12. Delete all records
13. Reverse the list
14. Save and exit
15. Exit without saving

FILE
----

Student records are saved in:

student.dat

SOURCE FILES
------------

student.h
stud_main.c
stud_add.c
stud_del.c
stud_show.c
stud_mod.c
stud_save.c
stud_sort.c
stud_reverse.c
stud_utils.c

COMPILATION
-----------

Using GCC:

gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c stud_reverse.c stud_utils.c -o student

EXECUTION
---------

Linux:

./student

Windows:

student.exe

MEMORY MANAGEMENT
-----------------

Each new student node is dynamically allocated using malloc().

Deleted nodes are released using free().

All remaining nodes are released before program termination.
