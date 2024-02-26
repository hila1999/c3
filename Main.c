#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    int choice;  
    char data[WORD_MAX_SIZE];
    int size;
    int index;

    


    StrList* listPtr1 =StrList_alloc();
              //  if (listPtr1 == NULL) {
              //  fprintf(stderr, "Memory allocation failed\n");
              //  return EXIT_FAILURE;}
                

    do {
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
            if(scanf("%d %s", &index, data) != 2){
            printf("invalid input \n");
            break;}
            // scanf("%d %s", &index,data);
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
              // char* temp="World";
              if(scanf("%s",data)!= 1){
                printf("invalid input \n");
              break;
              }
              StrList_remove(listPtr1,data);
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
              StrList_free(listPtr1);
              break;
            }
            case 12 :
            {
              StrList_sort(listPtr1);
              break;
            }
            case 13 :
            {
              int ans=StrList_isSorted(listPtr1);
              if(ans==1)  {printf("true\n");}
              else
              printf("false\n");
              break;
            }
        
        }  
       } while (choice != 0); // Corrected the loop condition and removed redundant braces

    StrList_free1(listPtr1);
    // free(listPtr1);
    return 0;
}

