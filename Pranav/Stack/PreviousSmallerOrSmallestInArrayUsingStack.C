// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

typedef struct stack {
    int num;
    struct stack *next;
} Stack;

bool isEmpty(Stack *Head) {
    if (Head == NULL) {
        return true;
    }
    return false;
}

void push (Stack **Head, int num) {
    Stack *node = (Stack *) malloc(sizeof(sizeof(Stack)));
    
    node->num = num;
    node->next = (*Head);
    (*Head) = node;
}

int pop(Stack **Head) {
    
    if (isEmpty(*Head)) {
        return -1;
    }

    int tmp = (*Head)->num;
    
    Stack *node = (*Head);
    (*Head) = (*Head)->next;
    
    free(node);
    return tmp;
} 

int top(Stack *Head) {
    if (isEmpty(Head)) {
        return -1;
    }
    return Head->num;
}

void display(Stack *Head) {
    while(Head) {
        printf("%d ", Head->num);
        Head = Head->next;
    }
    printf("\n");
}

void previous_smaller(int arr[], int size) {
    Stack *Head = NULL;

    for (int i = 0; i < size; i++) {
        int tmp = arr[i];
        while (!isEmpty(Head) && top(Head) >= arr[i]) {
            pop(&Head);
        }

        if(isEmpty(Head)) {
            arr[i] = -1;
        } else {
            arr[i] = top(Head);
        }
        push(&Head, tmp);
    }
}

void previous_smallest(int arr[], int size) {
    Stack *Head = NULL;

    for (int i = 0; i < size; i++) {
        while (!isEmpty(Head) && top(Head) >= arr[i]) {
            pop(&Head);
        }

        if(isEmpty(Head)) {
            push(&Head, arr[i]);
            arr[i] = -1;
        } else {
            arr[i] = top(Head);
            push(&Head, top(Head));
        }
    }
}

int main() {
    int arr[] = {2, 3, 7, 1, 6, 2, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Arrary: ");
    for (int i = 0 ; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    previous_smallest(arr, size);
    //previous_smaller(arr, size);
    printf("Arrary: ");
    for (int i = 0 ; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
