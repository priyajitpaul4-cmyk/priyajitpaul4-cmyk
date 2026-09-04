/*
    Program 05: Check Whether a Year is a Leap Year or Not
    Topic: Conditional Statements (logical operators)
    Lab question: "Write a program to check whether a year is leap or not."

    Rule:
        divisible by 400              -> leap year
        divisible by 100 but not 400  -> NOT a leap year
        divisible by 4 (and not 100)  -> leap year
        otherwise                     -> NOT a leap year
*/

#include <stdio.h>
#include "../projects.h"

void program05(void)
{
    int year;

    printf("\n--- Program 05: Leap Year or Not ---\n");

    printf("Enter a year (for example 2024): ");
    if (scanf("%d", &year) != 1) {
        printf("Invalid input! A year must be a whole number.\n");
        return;
    }

    if (year <= 0) {
        printf("Invalid input! Please enter a positive year.\n");
        return;
    }

    if (year % 400 == 0) {
        printf("%d IS a leap year (divisible by 400).\n", year);
    } else if (year % 100 == 0) {
        printf("%d is NOT a leap year (divisible by 100).\n", year);
    } else if (year % 4 == 0) {
        printf("%d IS a leap year (divisible by 4).\n", year);
    } else {
        printf("%d is NOT a leap year.\n", year);
    }

    /*
        One-line version using logical operators, if you prefer to write it
        that way in the lab:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                leap year
    */
}

/*
    ==================================================================
    EXPLANATION  -  Program 05: Check Whether a Year is a Leap Year or Not
    ==================================================================
    Leap year rule, written as a ladder:
        divisible by 400            -> leap
        divisible by 100 (not 400)  -> NOT leap     (1900 is not a leap year)
        divisible by 4              -> leap         (2024 is)
        otherwise                   -> NOT leap     (2023 is not)
    The order matters because 400 and 100 overlap: a year like 2000 is divisible by
    both, and only the 400 test coming first gives the right answer. Years <= 0 are
    rejected before any test.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 05: Leap Year or Not ---
        Enter a year (for example 2024): 2024
        2024 IS a leap year (divisible by 4).

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
