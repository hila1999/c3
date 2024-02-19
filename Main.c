#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    int choice;  
    char *strings[] = {"Hello", "World", "This", "Is", "An", "World", "Of", "World"};

    int i;
    
    StrList* listPtr1 = StrList_alloc();
    
    for (i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i) {
        StrList_insertFirst(listPtr1, strings[i]);
    }

    
    do {
        printf("WHICH FUNCTION do you want to do? Enter a number: ");
        scanf(" %d", &choice); // Added space before %c to consume whitespace
        switch (choice) {
            case 1:
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
            case 3://is print and pass line to cheack
            {
              StrList_print(listPtr1);

              break;
            }
            case 4://is print and pass line to cheack
            {
              int size=StrList_size(listPtr1);
               printf("%d\n",size);
              break;
            }
            case 5:
            {
              StrList_printAt(listPtr1,5);
               printf("finish number 5");
              break;
            }
            case 6 ://is print and pass line to cheack
            {
              int total =StrList_printLen(listPtr1);
              printf("%d\n",total);

              break;
            }
            case 7 :
            {
                printf("inside 7\n");
                char* temp="World";
              int how_much =StrList_count(listPtr1,temp);
              printf("%d\n",how_much);
              break;
            }
             case 8 :
            {
                printf("inside 8\n");
                char* temp="World";
                 StrList_remove(listPtr1,temp);

              break;
            }
             case 9 :
            {
                printf("inside 9\n");
                 StrList_removeAt(listPtr1,0);

              break;
            }
            case 11 :
            {
              printf("inside 11\n");
              StrList_free(listPtr1);
            }
            case 12 :
            {
              printf("inside 12\n");
              StrList_sort(listPtr1);
              break;
            }
            case 13 :
            {
              printf("inside 13\n");
              int ans=StrList_isSorted(listPtr1);
              printf("%d\n",ans);
              break;
            }
        } 
            
        } while (choice != 0); // Corrected the loop condition and removed redundant braces

    StrList_free(listPtr1);
    return 0;
}
