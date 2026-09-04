/*
    Program 07: Real Roots of a Quadratic Equation
    Topic: Conditional Statements
    Lab question: "Write a program to check whether there exist real roots
                   of a quadratic equation; if exist, find them."

    Equation : a*x*x + b*x + c = 0
    Discriminant (D) = b*b - 4*a*c
        D > 0  -> two real and different roots
        D = 0  -> two real and equal roots
        D < 0  -> real roots do NOT exist
*/

#include <stdio.h>
#include <math.h>
#include "../projects.h"

void program07(void)
{
    float a, b, c;
    float discriminant, root1, root2, realPart, imaginaryPart;

    printf("\n--- Program 07: Real Roots of a Quadratic Equation ---\n");

    printf("Enter the coefficients a, b and c of a*x*x + b*x + c = 0\n");
    printf("a b c : ");
    if (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("Invalid input! Three numbers are required.\n");
        return;
    }

    if (a == 0.0f) {
        printf("With a = 0 the equation is not quadratic (it becomes a\n");
        printf("linear equation b*x + c = 0), so the quadratic formula\n");
        printf("cannot be used here.\n");
        return;
    }

    discriminant = (b * b) - (4 * a * c);

    printf("\nEquation          : %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
    printf("Discriminant (D)  : %.2f\n", discriminant);

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Result            : Real roots EXIST (two different roots)\n");
        printf("Root 1            : %.2f\n", root1);
        printf("Root 2            : %.2f\n", root2);

    } else if (discriminant == 0) {
        root1 = -b / (2 * a);

        printf("Result            : Real roots EXIST (two equal roots)\n");
        printf("Root 1 = Root 2   : %.2f\n", root1);

    } else {
        realPart        = -b / (2 * a);
        imaginaryPart   = sqrt(-discriminant) / (2 * a);

        printf("Result            : Real roots DO NOT exist (roots are imaginary)\n");
        printf("Complex roots     : %.2f + %.2fi  and  %.2f - %.2fi\n",
               realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

/*
    ==================================================================
    EXPLANATION  -  Program 07: Real Roots of a Quadratic Equation
    ==================================================================
    For a*x^2 + b*x + c = 0 the roots come from  (-b +/- sqrt(D)) / (2a),
    where the discriminant D = b*b - 4*a*c.
    The program first decides whether real roots EXIST (that is what the question
    asks) and only then computes them:
        D > 0 -> two different real roots    D = 0 -> two equal real roots
        D < 0 -> no real roots (an imaginary pair is printed as extra information)
    a == 0 is checked first because it would make the divisor 2*a equal to zero.
    sqrt() is in math.h, which is why the link command needs -lm.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 07: Real Roots of a Quadratic Equation ---
        Enter the coefficients a, b and c of a*x*x + b*x + c = 0
        a b c : 1 -5 6

        Equation          : 1.00x^2 + -5.00x + 6.00 = 0
        Discriminant (D)  : 1.00
        Result            : Real roots EXIST (two different roots)
        Root 1            : 3.00
        Root 2            : 2.00

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
