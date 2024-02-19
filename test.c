#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    char choice;  
    double array[] = {2.15, 4, 6, 12, 77, 99};
    int i;
    
    printf("ffaa\n"); // Added a newline character to separate output
    StrList* listPtr1 = StrList_alloc();
    
    for (i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        StrList_insertFirst(listPtr1, array[i]);
    }

    printf("ff\n"); // Added a newline character to separate output
    
    do {
        printf("WHICH FUNCTION do you want to do? Enter a number: ");
        scanf(" %c", &choice); // Added space before %c to consume whitespace
        switch (choice) {
            case '1':
            {
                char mmm;
                scanf(" %c", &mmm); // Added space before %c to consume whitespace
                if (mmm == 'A') {
                    int size;
                    printf("HOW MANY WORDS do you want? ");
                    scanf("%d", &size);
                }
                break;
            }

            case '2': // Converted case 2 from int to char '2'
                // Implement functionality for case 2 here
                break;

            case '3': // print a list
                break;

            case '4': // Converted case 4 from int to char '4'
                // Implement functionality for case 4 here
                break;

            case '5': // Converted case 5 from int to char '5'
                // Implement functionality for case 5 here
                break;

            case '6': // Converted case 6 from int to char '6'
                // Implement functionality for case 6 here
                break;

            case '7': // Converted case 7 from int to char '7'
                // Implement functionality for case 7 here
                break;
        }
    } while (choice != '0'); // Corrected the loop condition and removed redundant braces

    StrList_free(listPtr1);
    return 0;
}

