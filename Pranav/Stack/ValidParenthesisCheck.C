#define CHAR 1
#include "stack.h"

bool valid_par(char *str) {
    Stack *Head = NULL;

    for (int i = 0; str[i]; i++) {
        if ((str[i] == ')' && top(Head) == '(') || 
            (str[i] == ']' && top(Head) == '[') ||
            (str[i] == '}' && top(Head) == '{') ) {
            pop(&Head);
        } else {
            push(&Head, str[i]);
        }
    }
    
    if (isEmpty(Head)) {
        return true;
    }
    return false;
}

int main() {
    if (valid_par("(())")) {
        printf("true");    
    } else {
        printf("false");
    }

    return 0;
}
