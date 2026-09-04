/*
    Program 19: Find the Sum of Digits of a Number
    Topic: Loops (while loop)
    Lab question: "Write a program to find the sum of digits of a number."

    1234  ->  4 + 3 + 2 + 1 = 10
    % 10 takes the last digit, / 10 removes it.
*/

#include <stdio.h>
#include "../projects.h"

void program19(void)
{
    int number, temp, digit;
    int sum = 0;

    printf("\n--- Program 19: Sum of Digits of a Number ---\n");

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please type a whole number.\n");
        return;
    }

    temp = number;

    if (temp < 0) {
        temp = -temp;      /* the sign is not a digit, so ignore it */
    }

    while (temp > 0) {
        digit = temp % 10;        /* last digit */
        sum   = sum + digit;      /* add it     */
        temp  = temp / 10;        /* cut it off */
    }

    printf("\nDigits of %d added : sum = %d\n", number, sum);
}

/*
    ==================================================================
    EXPLANATION  -  Program 19: Find the Sum of Digits of a Number
    ==================================================================
    % and / do all the work:
        temp % 10   take the last digit   (1234 -> 4)
        sum += digit                        add it to the total
        temp / 10   drop the last digit     (1234 -> 123)
    The loop repeats until temp becomes 0. The sign is removed before the loop,
    because for -1234 the digits are still 1, 2, 3 and 4 - the minus is not a digit.
    The same digit-peeling pair of operators appears in Programs 17 and 18.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 19: Sum of Digits of a Number ---
        Enter an integer: 1234

        Digits of 1234 added : sum = 10

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
