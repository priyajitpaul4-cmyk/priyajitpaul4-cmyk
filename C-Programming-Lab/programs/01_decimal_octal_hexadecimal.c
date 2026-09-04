/*
    Program 01: Display Decimal, Octal and Hexadecimal of a Given Number
    Topic: Basic Programs & Format Specifiers
    Lab question: "Write a program to display hexadecimal, decimal and
                   octal of a given number."

    C format specifiers used:
        %d  -> decimal (base 10)
        %o  -> octal    (base 8)
        %x  -> hexadecimal (base 16, letters a-f;  %X  would give A-F)
*/

#include <stdio.h>
#include "../projects.h"

void program01(void)
{
    int number;

    printf("\n--- Program 01: Decimal, Octal and Hexadecimal ---\n");

    printf("Enter an integer number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please run the program again and type a number.\n");
        return;
    }

    /*
        The same value is printed three times; only the format specifier
        changes, so the computer just shows its internal binary pattern in
        three different bases.
    */
    printf("\nIn decimal (base 10)      : %d\n", number);
    printf("In octal    (base 8)      : %o\n", number);
    printf("In hexadecimal (base 16)  : %x\n", number);

    /* A negative number is shown as its 2's complement pattern (e.g. -1 = ffffffff). */
    if (number < 0) {
        printf("\nNote: the number is negative, so octal/hexadecimal are shown\n"
               "      using the internal 2's complement bit pattern.\n");
    }
}

/*
    ==================================================================
    EXPLANATION  -  Program 01: Display Decimal, Octal and Hexadecimal of a Given Number
    ==================================================================
    Reads one integer and prints the same stored value three times with three
    different format specifiers. C does the base conversion for you while printing,
    so nothing has to be calculated:
        %d  decimal (base 10)   %o  octal (base 8)   %x  hexadecimal (base 16)
    Why 25 becomes 31 and 19:  25 = 3*8 + 1  ->  octal 31
                               25 = 1*16 + 9 ->  hexadecimal 19
    The value inside the variable never changes; only the way it is shown changes.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 01: Decimal, Octal and Hexadecimal ---
        Enter an integer number: 25

        In decimal (base 10)      : 25
        In octal    (base 8)      : 31
        In hexadecimal (base 16)  : 19

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
