#ifndef _DLIST_H_
#define _DLIST_H_

#define INSERT_PROCESS          1
#define REMOVE_PROCESS          2
#define PRINT_PROCESS           3
#define PRIORITIZE_PROCESS      4
#define EXECUTE_PROCESS         5
#define EXIT                    0

typedef struct Node {

        int id;
        int cycles;
        struct Node * next;
        struct Node * prev;

} Node;

typedef Node * ptr_node;

ptr_node create_proc_list(void);
ptr_node insert_proc(ptr_node proc_list);
ptr_node remove_proc(ptr_node proc_list);
ptr_node prioritize_proc(ptr_node proc_list);
ptr_node execute_proc(ptr_node proc_list);
void free_proc_list(ptr_node proc_list);
void print_proc_list(ptr_node proc_list);

#endif /* _DLIST_H_DEFINED_ */
