/*
    Program 06: Display Numbers 1 to 10 on Entry
    Topic: Loops
    Lab question: "Write a program to display no. 1-10 on entry."

    "on entry" is read as: the user enters 1 to ask for the output, and a
    for loop then prints 1 to 10. If your teacher meant simply "print 1 to
    10", delete the 'choice' check and keep the loop.
*/

#include <stdio.h>
#include "../projects.h"

void program06(void)
{
    int choice;
    int i;

    printf("\n--- Program 06: Display Numbers 1 to 10 ---\n");

    printf("Enter 1 to display the numbers 1 to 10: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please type a number.\n");
        return;
    }

    if (choice != 1) {
        printf("You entered %d, not 1, so nothing is displayed.\n", choice);
        return;
    }

    printf("\nUsing a for loop : ");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* Same output with a while loop, shown for comparison. */
    printf("Using a while loop : ");
    i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    /* Same output with a do-while loop. */
    printf("Using a do-while   : ");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    printf("\n");
}

/*
    ==================================================================
    EXPLANATION  -  Program 06: Display Numbers 1 to 10 on Entry
    ==================================================================
    The same line of output is produced three times, so the program doubles as a
    comparison of the three loop types:
        for (i = 1; i <= 10; i++)   counter start, test and step sit in one header
        while (i <= 10)             test happens before the body
        do { } while (i <= 10)      test happens after the body, so it runs once even
                                    when the condition is false at the start
    The 'entry' value read at the beginning decides whether anything is printed.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 06: Display Numbers 1 to 10 ---
        Enter 1 to display the numbers 1 to 10: 1

        Using a for loop : 1 2 3 4 5 6 7 8 9 10 
        Using a while loop : 1 2 3 4 5 6 7 8 9 10 
        Using a do-while   : 1 2 3 4 5 6 7 8 9 10 

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
