/* Define to prevent recursive inclusion */
#ifndef __STACK_H
#define __STACK_H

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
#if CHAR
    char ch;
#else
    int ch;
#endif
    struct stack *next;
} Stack;

 #if CHAR
    void push (Stack **Head, char ch);
    char pop(Stack **Head);
    char top(Stack *Head);
#else
    void push (Stack **Head, int ch);
    int pop(Stack **Head);
    int top(Stack *Head);
#endif
void display(Stack *Head);
  
#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __STACK_H */
