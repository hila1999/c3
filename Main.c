#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    int choice;  
    char data[WORD_MAX_SIZE];
    int size;
    int index;

    // char *strings[] = {"Hello", "World", "This", "Is", "An", "World", "Of", "World"};

    // int i;
    
    // StrList* listPtr1 = StrList_alloc();
    
    // for (i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i) {
    //     StrList_insertLast(listPtr1, strings[i]);
    // }

    StrList* listPtr1 =StrList_alloc();
               if (listPtr1 == NULL) {
               fprintf(stderr, "Memory allocation failed\n");
               return EXIT_FAILURE;}
                

    do {
        // printf("WHICH FUNCTION do you want to do? Enter a number: ");
        if(scanf(" %d", &choice) !=1){
          printf("invalid input \n");
                break;
        } 
        switch (choice) {
            case 1:
              if(scanf("%d", &size) != 1){
                printf("invalid input \n");
                break;
              }
             for (int i = 0; i < size; ++i) {
             if(scanf("%s",data)!= 1){
              printf("invalid input \n");
              break;
             }
             StrList_insertLast(listPtr1, data);
             }                             
                break;
            case 2:
            if(scanf("%s %d", data,&index) != 2){
            printf("invalid input \n");
            break;}
            StrList_insertAt(listPtr1,data,index);
            break;
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
              if(scanf("%d",&index)!= 1){
              printf("invalid input \n");
              break;}
              StrList_printAt(listPtr1,index);
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
              if(scanf("%s",data)!= 1){
              printf("invalid input \n");
              break;
             }
              int how_much =StrList_count(listPtr1,data);
              printf("%d\n",how_much);
              break;
            }
             case 8 :
            {
                char* temp="World";
                 StrList_remove(listPtr1,temp);

              break;
            }
             case 9 :
            {
                if(scanf("%d",&index)!= 1){
              printf("invalid input \n");
              break;}
                 StrList_removeAt(listPtr1,index);

              break;
            }
            case 10:
            {
              StrList_reverse(listPtr1);
              break;
            }
            case 11 :
            {
              printf("inside 11\n");
              StrList_free(listPtr1);
              break;
            }
            case 12 :
            {
              printf("inside 12\n");
              StrList_sort(listPtr1);
              break;
            }
            case 13 :
            {
              int ans=StrList_isSorted(listPtr1);
              if(ans==1)  {printf("True");}
              else
              printf("False");
              break;
            }
        
        }  
       } while (choice != 0); // Corrected the loop condition and removed redundant braces

    StrList_free(listPtr1);
    return 0;
}

