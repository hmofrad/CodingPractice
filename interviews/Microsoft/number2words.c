/*
 *  Problem: https://www.geeksforgeeks.org/convert-number-to-words/
 *  Write code to convert a given number into words. 
 *  For example, if “1234” is given as input, output should be “one thousand two hundred thirty four”.
 *  Compile: gcc -o number2words number2words.c -g -Wall -fsanitize=address && ./number2words   
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char* one_digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char* two_digits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* tens_multiple[] = {"", "", "twenty", "thirty", "fourty", "fifity", "sixty", "seventy", "eighty", "ninety"};
const char* tens_power[] = {"hundred", "thousand", "million", "billion"};

struct Node {
    int data;
    int size;
    struct Node* prev;
};

struct Node* allocate(int data, int size) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->size = size;
    node->prev = NULL;
    return(node);
}

void deallocate(struct Node* top) {
    if(top) {
        free(top);
    }
}

void push(struct Node** top, int data, int size) {
    if(*top == NULL) {
        *top = allocate(data, size);
    }
    else {
        struct Node* node = allocate(data, size);
        node->prev = *top;
        *top = node;
    }
}

void pop(struct Node** top) {
    if(*top) {
        struct Node* prev = (*top)->prev;
        deallocate(*top);
        *top = prev;
    }
}

struct Node* peek(struct Node* top) {
    struct Node* node = NULL;
    if(top) {
        node = top;
    }
    return(node);
}

char* number2words(int num) {
    char* words = NULL;
    printf(">>> %d\n", num);
    struct Node* s = NULL;
    int i = 0;
    while(num) {
        push(&s, num%10, i);
        //printf("[%d %d]", num/10, num%10);
        num /= 10;
        i++;
    }
    //printf("\n");
    
    i /= 3;

    while(s) {
        struct Node* n = peek(s);
        if(n->size == 0) {
            printf("%d %s\n", n->data, one_digit[n->data]);    
        }
        else if(n->size == 1) {
            if(n->data == 1) {
                pop(&s);
                n = peek(s);
                printf("%d %s\n", n->data, two_digits[n->data]);    
            }
            else {
                printf("%d %s\n", n->data, tens_multiple[n->data]);    
                pop(&s);
                n = peek(s);
                if(n->data)
                    printf(" %d %s\n", n->data, one_digit[n->data]);    
            }
        }
        else if((n->size/3) == i) {
                i--;
            
            printf(" %d %s (%d %d %d)\n", n->data, tens_power[n->size/3], n->size, n->size%3, n->size/3);    
        }
        else {
            if(n->data == 1) {
                pop(&s);
                n = peek(s);
                printf("%d %s\n", n->data, two_digits[n->data]);    
            }
            else {
                printf("%d %s\n", n->data, tens_multiple[n->data]);    
                pop(&s);
                n = peek(s);
                if(n->data)
                    printf(" %d %s\n", n->data, one_digit[n->data]);    
            }
            
        }
        
        pop(&s);
    }
    printf("\n");
    
    
    return(words);
}

int main(int argc, char** argv){
    int num = 1100134334;
    //char words[] = "one thousand two hundred thirty four";
    char* words1 = number2words(num);
    if(words1)
        printf("<%s>\n", words1);
    return(0);
}
