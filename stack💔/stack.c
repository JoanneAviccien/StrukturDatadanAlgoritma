#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int binary;
  struct node *nextstack;
} stack;

struct node * createstacknode(int data){
  struct node *temp = (struct node*)malloc(sizeof(stack));
  if (temp == NULL){
    perror("Stack Overflow :\(");
    exit(1);
  }
  temp->binary = data;
  temp->nextstack = NULL;
  return temp;
}

void push(stack **top, int pushed){
  struct node *pushit = createstacknode(pushed);
  struct node *temp = *top;

  if(*top == NULL){
    pushit->nextstack = *top;
    *top = pushit;
    return;
  }

  while (temp->nextstack != NULL){
    temp = temp->nextstack;
  }

  pushit->nextstack = temp->nextstack;
  temp->nextstack = pushit;
}

void rmtop(stack **top){
  stack* temp = *top;
  *top = (*top)->nextstack;
  free(temp);
}

void pop(stack **top){

  if(*top == NULL){
    perror("There is nothing to popped in the stack...");
  }
    printf("Popping node with data: %d\n", (*top)->binary);
    rmtop(top);
}

void peek(stack * print){
  if (print == NULL){
    perror("Stack is empty...");
  }

  stack * temp = NULL;
  temp = print;

  printf("Peeking your stack...\n");
  while(temp != NULL){
    printf("%d",temp->binary);
    temp = temp->nextstack;
  }
}

#endif // !DEBUG
