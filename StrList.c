#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Node & List Data Structures
typedef struct _node{
    char *data;
    struct _node* _next;
}  Node;

typedef struct _StrList{
     Node* _head;
    size_t _size;
} StrList;

void Node_free(Node* node){
    free(node);
}

Node* Node_alloc(const char* data,
				 Node* next) {
	Node* p= (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        // Memory allocation failed
        return NULL;}

	p->data= strdup(data);
	// p->_next= next;
    if(p->data==NULL){
        free(p);
        return NULL;}
	return p;
}
void StrList_free(StrList* StrList){
if (StrList==NULL) return;
Node* p1 = StrList-> _head;
Node* p2;
while(p1)
{
    p2=p1;
    p1=p1 ->_next;
    Node_free(p2);
}
}
void StrList_insertFirst(StrList* list,
					  char* data) {
	Node* newNode = Node_alloc(data,list->_head);
     if (newNode == NULL) {
        // Memory allocation failed
        return;
    }
    list->_head=newNode;
	++(list->_size);
}
void StrList_insertLast(StrList* StrList,
					  const char* data){
   Node* newNode=Node_alloc(data,NULL);
   if(StrList->_head==NULL){
     StrList->_head=newNode;
     ++(StrList->_size);
   }
  else{
  Node* current = StrList->_head;
  while ((current->_next!= NULL)){
    current =current->_next;
  }
current->_next=newNode;  
++(StrList->_size);
}
  }

void StrList_insertAt(StrList* StrList,
	const char* data,int index){
         if (index < 0 || index > StrList->_size) {
        printf("Invalid index\n");
        return;
    }
    Node* newNode=Node_alloc(data,NULL);
    if (index == 0) {
        newNode->_next = StrList->_head;
        StrList->_head = newNode;
    } else {
        // Find the node at index-1
        Node *current = StrList->_head;
        for (int i = 0; i < index - 1; i++) {
            current = current->_next;
        }
        // Insert the new node after the node at index-1
        newNode->_next = current->_next;
        current->_next = newNode;
    }

    // Increment the size of the list
    StrList->_size++;
}
    
char* StrList_firstData(const StrList* StrList){
    return StrList-> _head-> data;
}
//Allocate memory for the list structure.
//Initialize the list structure with appropriate values.
//Return a pointer to the newly allocated list.
StrList* StrList_alloc(){
    StrList* q = (StrList*)malloc(sizeof(StrList));
    q->_head =NULL;
    q->_size =0;
    return q;
}
size_t StrList_size(const StrList* StrList){
    if(StrList==NULL){
        return 0;
    }
    else return StrList->_size;
}
void StrList_print(const StrList* StrList){
    if(StrList==NULL) {
    printf("\n");
    return;}
    const Node* p=StrList-> _head;
    while (p){
        printf("%s ",p->data);
        p=p->_next;
        printf("\n");
    }
}

void StrList_printAt(const StrList* Strlist,int index){
     if (Strlist == NULL || Strlist->_head == NULL) {
        printf("List is empty.\n");
        return;
    }
    const Node* p=Strlist-> _head;
    while(index>0){
    p=p->_next;
    index--;}
    printf("%s\n",p->data);
}
int StrList_printLen(const StrList* Strlist){
   int totalLen = 0;
   const Node* current =Strlist ->_head;
   int temp;

    while(current!=NULL){
    temp = strlen(current->data);
    totalLen =totalLen +temp;
    current=current->_next;
    }
    return totalLen;
}
// int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
//     const int eq= 0;
// 	const int neq= 1;
	
// 	const Node* p1= strList1->_head;
// 	const Node* p2= strList2->_head;
// 	while(p1) {
// 		if (p2==NULL||p1->data!=p2->_data) return neq;
// 		p1= p1->_next;
// 		p2= p2->_next;
// 	}
// 	if (p2!=NULL) return neq;
// 	return eq;
// }

int StrList_count(StrList* StrList, const char* data){
   const Node* current=StrList-> _head;
    int howMuchDada= 0;
    while(current){
        if(strcmp(current->data,data)==0)
           howMuchDada++;
        current =current->_next;
    }
    return howMuchDada;
}
void StrList_remove(StrList* StrList, const char* data)
{
      if (StrList == NULL || StrList->_head == NULL) {
        return; // No operation if the list is empty
    }
      Node* current = StrList->_head;
      Node* prev = NULL;
     while (current)
     {
        if(strcmp(current->data, data)==0){

            if(prev==NULL){
                StrList->_head =current->_next;
            }
            else{
            prev->_next=current->_next;
            }
            free(current);
            StrList->_size--;
             
        }
        else{
            prev=current;}
            current=current->_next;
     }
}
void StrList_removeAt(StrList* StrList, int index){
    if(StrList==NULL)
    return;
     Node* current = StrList->_head;
     Node* prev = NULL;

    while(current!=NULL&&index>0){
    prev=current;
    current=current->_next;
    index--;
    }
    if(current!=NULL){
        if(prev==NULL){
            StrList->_head=current->_next;
        }
        else{
          prev->_next=current->_next;
        }
            free(current);
            StrList->_size--;
        }
    }

// StrList* StrList_clone(const StrList* StrList){
//     StrList* ret =StrList_alloc();
//     const Node* old =StrList->_head;
//     Node* * copy =&(ret->_head);
//     ret->_size=StrList->_size;
//     while(old){
//         *copy=Node_alloc(old->data,NULL);
//         old=old->_next;
//         copy=&((*copy)->_next);
//     }
//     return ret;
// }
// void StrList_reverse(StrList* list) {
//     Node *prev = NULL, *current = list->head, *next = NULL;
//     while (current != NULL) {
//         next = current->_next; // Store next node
//         current->_next = prev; // Reverse current node's pointer
//         prev = current; // Move pointers one position ahead
//         current = next;
//     }
//     list->_head = prev; // Update head to point to the new first node
// }
// void swap(StrList* a, StrList* b) {
//     char* temp = a->str;
//     a->str = b->str;
//     b->str = temp;
// }
 void StrList_sort(StrList* StrList) {
    if (StrList == NULL || StrList->_head == NULL) {
        return; // No operation if the list is empty
    }
    
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = StrList->_head;

        while (ptr1->_next != lptr) {
            if (strcmp(ptr1->data, ptr1->_next->data) > 0) {
                char *temp = ptr1->data;
                ptr1->data = ptr1->_next->data;
                ptr1->_next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}

int StrList_isSorted(StrList* StrList){
if (StrList == NULL || StrList->_head == NULL) {
        return 1; // An empty list is considered sorted
    }

    Node* current = StrList->_head;

    while (current->_next != NULL) {
        // Compare the current string with the next one
        if (strcmp(current->data, current->_next->data) > 0) {
            return 0; // Not sorted
        }
        current = current->_next;
    }

    return 1; // Sorted
}

void StrList_reverse( StrList* StrList){
    Node *prev = NULL, *current = StrList->_head, *next;
    while (current != NULL) {
        next = current->_next; // Store the next node
        current->_next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    StrList->_head = prev; // Update the head of the list
}           


