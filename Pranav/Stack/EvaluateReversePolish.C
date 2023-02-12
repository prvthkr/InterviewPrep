#include "stack.h"

int myatoi(char *str) {
    int res = 0;
    
    for(int i = 0; str[i]; i++)
        res = ((res * 10) + (str[i] - '0'));

    return res;
}

int calci(int num1, int num2, char *str) {
    switch(str[0]) {
        case '+':
            return (num1 + num2);
        case '-':
            return (num1 - num2);
        case '*':
            return (num1 * num2);
        case '/':
            return (num1 / num2);
    }
}
int reverse_polish(char **str, int size) {
    Stack *Head = NULL;

    for (int i = 0; i < size; i++) {
        if (!strcmp (str[i], "+") || !strcmp (str[i], "-") ||
            !strcmp (str[i], "*") || !strcmp (str[i], "/")) {
                int num1 = pop(&Head);
                int num2 = pop(&Head);
                push(&Head, calci(num2, num1, str[i]));
        } else {
            if (str[i][0] == '-') {
                push(&Head, -(myatoi(str[i]+1)));
            } else {
                push(&Head, myatoi(str[i]));
            }
        }
        display(Head);
    }

    return pop(&Head);
}

int main() {

    //char *arr[] = {"2", "1", "+", "3", "*"}; // o/p- 9
    //char *arr[] = {"4", "13", "5", "/", "+"}; // o/p- 6
    char *arr[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}; // o/p- 22
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Result: %d\n", reverse_polish(arr, size));
    

    return 0;
}
