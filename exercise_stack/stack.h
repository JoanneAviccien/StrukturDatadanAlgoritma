#ifndef stack_h
#define stack_h

typedef struct node {
  int binary;
  struct node *nextstack;
} stack;

struct node * createstacknode(int data);
struct node * push(stack **top, int pushed);
void pop(stack **top);
void peek(stack * print);

#endif // !DEBUG
