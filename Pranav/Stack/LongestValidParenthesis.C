#define CHAR 1
#include "stack.h"

int valid_par(char *str) {
    Stack *Head = NULL;
    
    int small = 0;
    int mid = 0;
    int big = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ')' && top(Head) == '(') {
            small++;
            pop(&Head);
        } else if (str[i] == ']' && top(Head) == '[') {
            mid++;
            pop(&Head);
        } else if (str[i] == '}' && top(Head) == '{') {
            big++;
            pop(&Head);
        } else {
            push(&Head, str[i]);
        }
    }
    
    if (small > mid && small > big) {
        return small * 2;
    } else if (mid > small && mid > big) {
        return mid * 2;
    } else if (big > small && big > mid) {
        return big * 2;
    }
    
    return 0;
}

int main() {
    // Write C code here
    
    printf("Longest Valid Parenthesis is: %d\n",valid_par("(())"));
    printf("Longest Valid Parenthesis is: %d\n",valid_par(")"));
    return 0;
}
