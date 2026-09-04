/*
    Program 10: Menu Driven Calculator using switch
    Topic: Switch Case
    Lab question: "Menu driven program to execute 1. Addition,
                   2. Subtraction, Multiplication, Division using switch."

    This program has its own small menu (it is the lab exercise about
    switch), so choose 0 here to come back to the C Lab main menu.
*/

#include <stdio.h>
#include "../projects.h"

/*
    Reads one menu number.
    Returns the number, or -1 when the typed text is not a number,
    so that the caller can ask again instead of looping forever.
*/
static int read_menu_choice(void)
{
    int value;
    int ch;

    if (scanf("%d", &value) != 1) {
        while ((ch = getchar()) != '\n' && ch != EOF) {
            ;
        }
        return -1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }

    return value;
}

void program10(void)
{
    float a, b;
    int choice;
    int again = 1;

    printf("\n--- Program 10: Menu Driven Calculator (switch) ---\n");

    printf("Enter two numbers (a and b) : ");
    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input! Two numbers are required.\n");
        return;
    }

    printf("\nYou will calculate with a = %.2f and b = %.2f\n", a, b);

    while (again) {
        printf("\n============ CALCULATOR MENU ============\n");
        printf("  1. Addition\n");
        printf("  2. Subtraction\n");
        printf("  3. Multiplication\n");
        printf("  4. Division\n");
        printf("  5. Enter new numbers\n");
        printf("  0. Back to the C Lab main menu\n");
        printf("Enter your choice: ");

        choice = read_menu_choice();

        switch (choice) {
        case 1:
            printf("%.2f + %.2f = %.2f\n", a, b, a + b);
            break;

        case 2:
            printf("%.2f - %.2f = %.2f\n", a, b, a - b);
            break;

        case 3:
            printf("%.2f * %.2f = %.2f\n", a, b, a * b);
            break;

        case 4:
            if (b == 0.0f) {
                printf("Division is not possible: b is 0.\n");
            } else {
                printf("%.2f / %.2f = %.2f\n", a, b, a / b);
            }
            break;

        case 5:
            printf("Enter two new numbers (a and b) : ");
            if (scanf("%f %f", &a, &b) != 2) {
                printf("Invalid input! Keeping the old numbers.\n");
            } else {
                printf("Now calculating with a = %.2f and b = %.2f\n", a, b);
            }
            break;

        case 0:
            again = 0;
            printf("Returning to the C Lab main menu.\n");
            break;

        default:
            printf("Invalid choice! Enter 0, 1, 2, 3, 4 or 5.\n");
            break;
        }
    }
}

/*
    ==================================================================
    EXPLANATION  -  Program 10: Menu Driven Calculator using switch
    ==================================================================
    switch picks one of the four formulas from the menu number typed by the user.
        break  at the end of each case is essential: without it the program 'falls
        through' and also runs the next case's statements.
        default  catches 6, 99, letters - it prints a message and the loop asks
        again, so a wrong key never ends the program or hangs it.
    Case 4 checks b == 0 first, because dividing by zero would print inf or nan.
    Case 0 clears the 'again' flag, the while loop stops, and control returns to
    the C Lab menu. The read is done by read_menu_choice(), which throws away bad
    text instead of reading it forever.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 10: Menu Driven Calculator (switch) ---
        Enter two numbers (a and b) : 8 2

        You will calculate with a = 8.00 and b = 2.00

        ============ CALCULATOR MENU ============
          1. Addition
          2. Subtraction
          3. Multiplication
          4. Division
          5. Enter new numbers
          0. Back to the C Lab main menu
        Enter your choice: 1
        8.00 + 2.00 = 10.00

        ============ CALCULATOR MENU ============
          1. Addition
          2. Subtraction
          3. Multiplication
          4. Division
          5. Enter new numbers
          0. Back to the C Lab main menu
        Enter your choice: 0
        Returning to the C Lab main menu.

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
