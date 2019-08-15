#ifndef _DERIVATIVE_H_
#define _DERIVATIVE_H_

typedef struct Node {
        int constant;
        int coefficient;
        struct Node * next;
} Node;

typedef struct Node * ptr_node;

ptr_node create_polynomial(int argc, char *argv[]);
ptr_node derivative(ptr_node polynomial);
void print_polynomial(ptr_node polynomial);

#endif /* _DERIVATIVE_H_DEFINED_ */
