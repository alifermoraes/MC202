#ifndef		_LIST_H_
#define		_LIST_H_

#define INSERT_NB               1
#define REMOVE_NB               2
#define PREFIX_INVERSION        3
#define SUFFIX_INVERSION        4
#define TRANSPOSE_DNA           5
#define PRINT_DNA               6
#define EXIT                    0

typedef struct Node {
        char data;
        struct Node *next;
} Node;

typedef Node * ptr_node;

ptr_node create_empty_list(void);
ptr_node insert_nucleobase(ptr_node list, char data, int pos);
ptr_node remove_nucleobase(ptr_node list, int pos);
ptr_node prefix_inversion(ptr_node list, int len);
ptr_node suffix_inversion(ptr_node list, int len);
ptr_node transpose_dna(ptr_node list, int p, int q, int r);
void print_sequence(ptr_node list);
void free_sequence(ptr_node list);

#endif		/* _LIST_H_DEFINED_ */
