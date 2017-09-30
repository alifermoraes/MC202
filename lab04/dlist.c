#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

static int proc_list_len(ptr_node process);

ptr_node create_proc_list(void)
{
        return NULL;
}

ptr_node insert_proc(ptr_node proc_list)
{
        int i;
        int id, cycles, pos;
        ptr_node new, aux = proc_list;

        scanf("%d %d %d", &id, &cycles, &pos);

        if (pos > proc_list_len(proc_list)) {
                printf("Error! Invalid position.\n");
                return proc_list;
        }

        new = malloc(sizeof(Node));

        if (!new) {
                printf("insert_proc() function has failed! Out of memory.\n")
                exit(EXIT_FAILURE);
        }

        new->id = id;
        new->cycles = cycles;

        if (!pos) {
                if (!aux) { /* empty list */
                        proc_list = new;
                        new->next = new;
                        new->prev = new;
                } else { /* list has at least 1 process */
                        new->next = aux;
                        new->prev = aux->prev;
                        aux->prev = new;
                        new->prev->next = new;
                        proc_list = new;
                }
        } else {
                for (i = 1; i < pos; i++)
                        aux = aux->next;

                new->next = aux->next;
                new->next->prev = new;
                aux->next = new;
                new->prev = aux;
        }

        printf("Process %d requested with %d cycle(s) in position %d!\n", id, cycles, pos);

        return proc_list;
}

ptr_node remove_proc(ptr_node proc_list)
{
                int id, len = proc_list_len(proc_list);
                ptr_node aux = proc_list;

                scanf("%d", &id);

                switch (len) {
                case 0:
                        printf("There is no process in the list.\n");
                        break;

                case 1:
                        if (proc_list->id == id) {
                                free(proc_list);
                                proc_list = NULL;
                                printf("Process ID: %d has been successfully removed.\n", id);
                        } else {
                                printf("There is no process with ID: %d.\n", id);
                        }
                        break;

                default:
                        do {
                                if (aux->id == id) {
                                        if (aux == proc_list)
                                                proc_list = aux->next;

                                        aux->next->prev = aux->prev;
                                        aux->prev->next = aux->next;
                                        free(aux);
                                        printf("Process ID: %d has been successfully removed.\n", id);
                                        return proc_list;
                                }

                                aux = aux->next;
                        } while (aux != proc_list);

                        printf("There is no process with ID: %d.\n", id);
                        break;
                }

                return proc_list;
}

ptr_node prioritize_proc(ptr_node proc_list)
{
        int id;
        ptr_node aux = proc_list;

        scanf("%d", &id);

        do {
                if (aux->id == id) {
                        if (aux == proc_list) {
                                printf("Process ID: %d is already prioritized.\n", id);
                                return proc_list;
                        }

                        aux->next->prev = aux->prev;
                        aux->prev->next = aux->next;
                        aux->next = proc_list;
                        aux->prev = proc_list->prev;
                        proc_list->prev->next = aux;
                        proc_list->prev = aux;
                        proc_list = aux;
                        printf("Process ID: %d successfully priotized.\n", id);
                        return proc_list;
                } else {
                        aux = aux->next;
                }

        } while (aux != proc_list);

        printf("There is no process with ID: %d.\n", id);
        return proc_list;
}

ptr_node execute_proc(ptr_node proc_list)
{
        int cycles;
        ptr_node temp, aux = proc_list;

        scanf("%d", &cycles);

        while (cycles) {

                if (!aux) {
                        printf("There is no processes to be executed.\n");
                        return proc_list;
                }

                aux->cycles--;

                if (!aux->cycles) {
                        aux->next->prev = aux->prev;
                        aux->prev->next = aux->next;

                        if (aux == proc_list) {
                                if (aux->next == aux) {
                                        free(aux);
                                        return NULL;
                                }

                                proc_list = aux->next;
                        }

                        temp = aux;
                        aux = aux->next;
                        free(temp);
                } else {
                        aux = aux->next;
                }

                cycles--;
        }

        return aux;
}

void print_proc_list(ptr_node proc_list)
{
        ptr_node aux = proc_list;

        if(!aux) {
                printf("proc_list is empty.\n");
        } else {
                do {
                        printf("(%d,%d) ", aux->id, aux->cycles);
                        aux = aux->next;

                } while (aux != proc_list);

                printf ("\n");
        }

        return;
}

void free_proc_list(ptr_node proc_list)
{
        ptr_node aux = proc_list, next;

        if (!aux)
                return;

        while(aux->next != proc_list) {
                next = aux->next;
                free(aux);
                aux = next;
        }

        free(aux);
        return;
}

static int proc_list_len(ptr_node proc_list)
{
        int len = 0;
        ptr_node aux = proc_list;

        if (aux)
                do {
                        len++;
                        aux = aux->next;
                } while (aux != proc_list);

        return len;
}
