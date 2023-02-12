#include "stack.h"

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
