#define CHAR 1
#include "stack.h"

void add_in_last(Stack **Head, char ch) {
    if (isEmpty(*Head)) {
        push(Head, ch);
    } else {
        char tmp = pop(Head);
        add_in_last(Head, ch);
        push(Head, tmp);
    }
}

void reverse_recursion(Stack **Head) {
    if (!isEmpty(*Head)) {
        char tmp = pop(Head);
        reverse_recursion(Head);
        add_in_last(Head, tmp);
    }
}

int main() {
    
    Stack *Head = NULL;
    
    push(&Head, 'p');
    push(&Head, 'r');
    push(&Head, 'a');
    push(&Head, 'n');
    push(&Head, 'a');
    push(&Head, 'v');
    printf("Before: ");
    display(Head);
    reverse_recursion(&Head);
    printf("After: ");
    display(Head);
    
    return 0;
}
