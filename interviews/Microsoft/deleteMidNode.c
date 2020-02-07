/*
 *  Problem: https://www.geeksforgeeks.org/delete-middle-of-linked-list/
 *  Delete middle of linked list    
 *  Compile: gcc -o deleteMidNode deleteMidNode.c -g -Wall -fsanitize=address && ./deleteMidNode    
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* allocate(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return(node);
}

void deallocate(struct Node* node) {
    free(node);
}

void traverse(struct Node* head) {
    if(head) {
        printf("%d ", head->data);
        traverse(head->next);
    }
}

void traverse1(struct Node* head) {
   traverse(head);
   printf("\n");
}

void delete_mid(struct Node** head) {
    if(*head == NULL) return;
    if((*head)->next == NULL) {deallocate(*head); *head = NULL;};
    
    struct Node* prev = NULL;
    struct Node* slow = *head;
    struct Node* fast = *head;
    
    
    while(fast->next) {
        printf(">>>> %d %d\n" , slow->data, fast->data);
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL) break;
    }
    
    printf("%d\n", slow->data);
    
    if(prev) {
        struct Node* temp = slow->next;
        deallocate(slow);
        prev->next = temp;
    }
    
    
    
    
}

/*
Input:
1->2->3->4->5->6

Output:
1->2->3->5->6
*/


int main(int argc, char **argv){
   struct Node* head = allocate(1);
   head->next = allocate(2);
   head->next->next = allocate(3);
   head->next->next->next = allocate(4);
   head->next->next->next->next = allocate(5);
   head->next->next->next->next->next = allocate(6);
   
   traverse1(head);
   
   delete_mid(&head);
   
   traverse1(head);
   
   deallocate(head->next->next->next->next->next);
   deallocate(head->next->next->next->next);
   deallocate(head->next->next->next);
   deallocate(head->next->next);
   deallocate(head->next);
   deallocate(head);
    
    return(0);
}
