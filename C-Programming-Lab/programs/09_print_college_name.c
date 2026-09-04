/*
    Program 09: Print the College Name 20 Times
    Topic: Loops
    Lab question: "Print collegename 20 times."

    EDIT THIS LINE with the name on your own lab record cover page.
    Keeping it in one #define means the name is written only once.
*/

#include <stdio.h>
#include "../projects.h"

#define COLLEGE_NAME "GOVERNMENT POLYTECHNIC"

void program09(void)
{
    int i;

    printf("\n--- Program 09: Print College Name 20 Times ---\n\n");

    for (i = 1; i <= 20; i++) {
        printf("%2d. %s\n", i, COLLEGE_NAME);
    }

    printf("\n\"%s\" was printed %d times using a for loop.\n",
           COLLEGE_NAME, i - 1);
}

/*
    ==================================================================
    EXPLANATION  -  Program 09: Print the College Name 20 Times
    ==================================================================
    One printf inside a for loop that runs 20 times does the work of 20 printf
    lines - that is the whole lesson of this program.
    The college name is kept in a single #define at the top, so it appears once in
    the source and only that one line needs editing. The counter is printed with
    %2d, which right-aligns it in two columns so 1 to 9 and 10 to 20 line up.

    ==================================================================
    SAMPLE OUTPUT  (a real terminal session; the text the user typed is shown
    after the prompt on the same line)
    ==================================================================
        --- Program 09: Print College Name 20 Times ---

         1. GOVERNMENT POLYTECHNIC
         2. GOVERNMENT POLYTECHNIC
         3. GOVERNMENT POLYTECHNIC
         4. GOVERNMENT POLYTECHNIC
         5. GOVERNMENT POLYTECHNIC
         6. GOVERNMENT POLYTECHNIC
         7. GOVERNMENT POLYTECHNIC
         8. GOVERNMENT POLYTECHNIC
         9. GOVERNMENT POLYTECHNIC
        10. GOVERNMENT POLYTECHNIC
        11. GOVERNMENT POLYTECHNIC
        12. GOVERNMENT POLYTECHNIC
        13. GOVERNMENT POLYTECHNIC
        14. GOVERNMENT POLYTECHNIC
        15. GOVERNMENT POLYTECHNIC
        16. GOVERNMENT POLYTECHNIC
        17. GOVERNMENT POLYTECHNIC
        18. GOVERNMENT POLYTECHNIC
        19. GOVERNMENT POLYTECHNIC
        20. GOVERNMENT POLYTECHNIC

        "GOVERNMENT POLYTECHNIC" was printed 20 times using a for loop.

    ==================================================================
    HOW TO BUILD THE WHOLE PROJECT (from the C-Programming-Lab folder)
    ==================================================================
        gcc -Wall -Wextra -std=c11 -o clab main.c "programs/"*.c -lm
        ./clab
        then pick the topic number, then the program number, 0 to go back.
*/
