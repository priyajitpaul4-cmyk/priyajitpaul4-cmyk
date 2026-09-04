/*
    Program 03: Print First / Second Division According to Marks Entered
    Topic: Conditional Statements (if - else if ladder)
    Lab question: "Write a program to display first, second according to
                   marks entered."

    The student enters marks (0 - 100) and the program prints which
    division the marks fall into.

    The cut-off marks below follow the usual polytechnic pattern
    (70 / 50 / 40). If your college uses different numbers, change only
    the four values in the if - else if ladder; nothing else has to move.
*/

#include <stdio.h>
#include "../projects.h"

void program03(void)
{
    float marks;

    printf("\n--- Program 03: Division According to Marks ---\n");

    printf("Enter marks (0 to 100): ");
    if (scanf("%f", &marks) != 1) {
        printf("Invalid input! Marks must be a number.\n");
        return;
    }

    if (marks < 0 || marks > 100) {
        printf("Invalid marks! Marks must be between 0 and 100.\n");
        return;
    }

    printf("\nMarks entered : %.2f\n", marks);

    if (marks >= 70.0) {
        printf("Result        : FIRST DIVISION\n");
    } else if (marks >= 50.0) {
        printf("Result        : SECOND DIVISION\n");
    } else if (marks >= 40.0) {
        printf("Result        : THIRD DIVISION\n");
    } else {
        printf("Result        : FAIL\n");
    }
}

/*
    ==================================================================
    EXPLANATION  -  Program 03: Print First / Second Division According to Marks Entered
    ==================================================================
    An if - else if ladder is tested from top to bottom and the FIRST true
    condition wins; every condition below it is skipped. That is why the cut-offs
    must be written from the highest marks downwards - if 'marks >= 40' came first,
    a student with 85 would be reported as THIRD DIVISION.
    marks is a float so 85.5 is accepted. The 0-100 range check is done before the
    ladder, so an impossible value is never labelled as a pass class.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 03: Division According to Marks ---
        Enter marks (0 to 100): 85

        Marks entered : 85.00
        Result        : FIRST DIVISION

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
