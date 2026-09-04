/*
    main.c  --  C Programming Lab : Central Controller

    This file only:
        1. shows the main menu (grouped by the topics used in the lab notes)
        2. shows a sub-menu for the selected topic
        3. calls the matching programNN() function from programs/
        4. returns to the right menu after a program finishes
        5. exits / rejects invalid choices safely

    It contains the ONLY main() in the whole project.
    No program logic lives here.

    The programs are described in a table of { number, title, function }.
    Because the number, the printed title and the function all come from the
    same row, a menu option can never call the wrong program.
*/

#include <stdio.h>
#include "projects.h"

/* ------------------------------------------------------------------ */
/*  Data structures for the menu                                       */
/* ------------------------------------------------------------------ */

typedef struct {
    int       number;    /* program number = file number = function number */
    const char *title;   /* text shown in the sub-menu                     */
    void    (*run)(void);/* the programNN() function to execute          */
} Program;

typedef struct {
    const char    *name;  /* topic name taken from the lab notes */
    const Program *list;  /* programs that belong to this topic  */
    int            count; /* how many programs in this topic     */
} Category;

/* ---- Topic 1 : Basic Programs & Format Specifiers ---- */
static const Program basicPrograms[] = {
    {  1, "Display decimal, octal and hexadecimal of a number", program01 },
    {  4, "Check whether a number is even or odd",              program04 }
};

/* ---- Topic 2 : Operators & Expressions ---- */
static const Program operators[] = {
    { 11, "Swap two variables using a third variable",          program11 },
    { 12, "Swap two variables without using a third variable",  program12 }
};

/* ---- Topic 3 : Conditional Statements ---- */
static const Program conditional[] = {
    {  2, "Find the largest and smallest among three numbers",  program02 },
    {  3, "Print division (first/second) according to marks",   program03 },
    {  5, "Check whether a year is a leap year or not",         program05 },
    {  7, "Real roots of a quadratic equation, if they exist",  program07 }
};

/* ---- Topic 4 : Switch Case ---- */
static const Program switchCase[] = {
    { 10, "Menu driven addition, subtraction, multiplication",  program10 }
};

/* ---- Topic 5 : Loops ---- */
static const Program loops[] = {
    {  6, "Display numbers 1 to 10 on entry",                   program06 },
    {  8, "Print prime numbers in a given range",               program08 },
    {  9, "Print college name 20 times",                         program09 },
    { 16, "Check whether a given number is prime or not",       program16 },
    { 17, "Print all Armstrong numbers in the range 100 - 1000",program17 },
    { 18, "Check whether a given number is an Armstrong number",program18 },
    { 19, "Find the sum of digits of a number",                 program19 }
};

/* ---- Topic 6 : Functions & Recursion ---- */
static const Program functions[] = {
    { 13, "Factorial of a given number using a loop",           program13 },
    { 14, "Factorial of a given number using recursion",        program14 }
};

/* ---- Topic 7 : Arrays ---- */
static const Program arrays[] = {
    { 15, "Add numbers using an array",                         program15 },
    { 20, "Print the smallest element of an array",             program20 }
};

/* All topics in the order they appear in the menu.
   Adding a topic later = add its array above and one row here. */
static const Category categories[] = {
    { "Basic Programs & Format Specifiers", basicPrograms, 2 },
    { "Operators & Expressions",            operators,      2 },
    { "Conditional Statements",             conditional,   4 },
    { "Switch Case",                          switchCase,   1 },
    { "Loops",                                loops,        7 },
    { "Functions & Recursion",                functions,    2 },
    { "Arrays",                               arrays,       2 }
};

#define TOTAL_CATEGORIES ((int)(sizeof(categories) / sizeof(categories[0])))

/*
    The number of programs is counted from the tables themselves, so the
    menu can never claim a wrong total. When program 21, 22, ... are added
    later, nothing here has to be edited.
*/
static int total_programs(void)
{
    int i;
    int sum = 0;

    for (i = 0; i < TOTAL_CATEGORIES; i++) {
        sum += categories[i].count;
    }

    return sum;
}

/* ------------------------------------------------------------------ */
/*  Input helper                                                       */
/* ------------------------------------------------------------------ */

/*
    Reads one whole number from the keyboard.

    Returns -1 when there is no more input (Ctrl+Z / Ctrl+D or a pipe
    that finished), which lets the menus stop politely instead of
    repeating the prompt forever. Bad input such as "abc" is thrown
    away and the user is asked again.
*/
static int read_int(const char *prompt)
{
    int  value;
    int  ch;

    printf("%s", prompt);

    while (scanf("%d", &value) != 1) {
        if (feof(stdin) || ferror(stdin)) {
            return -1;                      /* nothing readable left */
        }
        while ((ch = getchar()) != '\n' && ch != EOF) {
            ;                               /* discard the bad text   */
        }
        printf("%s", prompt);
    }

    /* throw away the rest of the line so it cannot disturb the next read */
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }

    return value;
}

/* ------------------------------------------------------------------ */
/*  Menus                                                              */
/* ------------------------------------------------------------------ */

static void line(void)
{
    printf("----------------------------------------\n");
}

static void show_main_menu(void)
{
    int i;

    printf("\n========================================\n");
    printf("            C PROGRAMMING LAB\n");
    printf("   Class 3rd  |  CSE  |  2nd Year\n");
    printf("========================================\n");
    printf("   Total programs : %d\n", total_programs());
    printf("----------------------------------------\n");

    for (i = 0; i < TOTAL_CATEGORIES; i++) {
        printf("  %d. %-36s (%d)\n",
               i + 1, categories[i].name, categories[i].count);
    }

    line();
    printf("  0. Exit\n");
    line();
}

/*
    Shows the programs of one topic and keeps running them until the
    user presses 0.  After a program finishes we come back here, so the
    user never has to walk through the main menu again.
*/
static void show_category_menu(int index)
{
    const Category *cat = &categories[index];
    int choice;
    int i;

    for (;;) {
        printf("\n============ %s ============\n", cat->name);

        for (i = 0; i < cat->count; i++) {
            printf("  %d. Program %02d : %s\n",
                   i + 1, cat->list[i].number, cat->list[i].title);
        }

        line();
        printf("  0. Back to main menu\n");

        choice = read_int("Enter your choice: ");

        if (choice == -1) {                 /* end of input */
            return;
        }
        if (choice == 0) {                  /* back */
            return;
        }
        if (choice < 1 || choice > cat->count) {
            printf("  ! Invalid choice. Pick 1 to %d, or 0 to go back.\n",
                   cat->count);
            continue;
        }

        /* the row we picked already knows which function to run */
        cat->list[choice - 1].run();

        printf("\n>> Program %02d finished.\n", cat->list[choice - 1].number);
    }
}

/* ------------------------------------------------------------------ */
/*  main                                                               */
/* ------------------------------------------------------------------ */

int main(void)
{
    int choice;

    for (;;) {
        show_main_menu();

        choice = read_int("Enter your choice: ");

        if (choice == -1) {                 /* no more input: quit cleanly */
            printf("\nNo more input. Thank you for using the C Lab.\n");
            return 0;
        }

        switch (choice) {
        case 0:
            printf("\nThank you! Exiting the C Programming Lab.\n");
            return 0;

        default:
            /*
                The range is checked against TOTAL_CATEGORIES instead of
                listing "case 1: case 2: ... case 7:", so adding an eighth
                topic later cannot leave this switch out of date.
            */
            if (choice >= 1 && choice <= TOTAL_CATEGORIES) {
                show_category_menu(choice - 1);
            } else {
                printf("  ! Invalid choice. Please enter a number from 1 to %d,"
                       " or 0 to Exit.\n", TOTAL_CATEGORIES);
            }
            break;
        }
    }
}
