#define CHAR  1
#include "stack.h"

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
    
    display(Head);
    
    return 0;
}
