// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

typedef struct stack {
    char ch;
    struct stack *next;
} Stack;

bool isEmpty(Stack *Head) {
    if (Head == NULL) {
        printf("TRUE\n");
        return true;
    }
    printf("FALSE\n");
    return false;
}

void push (Stack **Head, char ch) {
    Stack *node = (Stack *) malloc(sizeof(sizeof(Stack)));
    
    node->ch = ch;
    node->next = (*Head);
    (*Head) = node;
}

char pop(Stack **Head) {
    
    if (isEmpty(*Head)) {
        return -1;
    }

    char tmp = (*Head)->ch;
    
    Stack *node = (*Head);
    (*Head) = (*Head)->next;
    
    free(node);
    return tmp;
} 

char top(Stack *Head) {
    if (isEmpty(Head)) {
        return -1;
    }
    return Head->ch;
}

void display(Stack *Head) {
    while(Head) {
        printf("%c, ", Head->ch);
        Head = Head->next;
    }
    printf("\n");
}

int main() {
    
    Stack *Head = NULL;
    
    push(&Head, 'p');
    push(&Head, 'r');
    push(&Head, 'a');
    push(&Head, 'n');
    push(&Head, 'a');
    push(&Head, 'v');
    display(Head);
    printf("%c, ", pop(&Head));
    printf("%c, ", pop(&Head));
    printf("%c, ", pop(&Head));
  printf("\n top: %c ", top(Head));  
  printf("%c, ", pop(&Head));
    printf("%c, ", pop(&Head));
    printf("%c, ", pop(&Head));
    
    //display(Head);


    return 0;
}
