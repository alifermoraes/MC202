#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static int list_len(ptr_node list);

ptr_node create_empty_list(void)
{
        return NULL;
}

/* Inserts a given nucleobase in a given position of a list */
ptr_node insert_nucleobase(ptr_node list, char data, int pos)
{
        int i;
        ptr_node new, prev = list;

        if (pos > list_len(list)) {
                printf("Error! Invalid position.\n");
                return list;
        }

        new = malloc(sizeof(Node));
        new->data = data;

        if (!pos) {
                new->next = list;
                list = new;
        } else {
                for (i = 1; i < pos; i++)
                        prev = prev->next;

                new->next = prev->next;
                prev->next = new;
        }

        printf("Nucleobase added in position %d of stretch.\n", pos);
        return list;
}

/* removes a nucleobase on a given position of a list */
ptr_node remove_nucleobase(ptr_node list, int pos)
{
        int i;
        ptr_node aux, prev = list;

        if (pos >= list_len(list)) {
                printf("Error! invalid position.\n");
                return list;
        }

        if (!pos) {
                aux = list;
                list = list->next;
                free(aux);
        } else {

                for (i = 1; i < pos; i++)
                        prev = prev->next;

                if (prev->next) {
                        aux = prev->next->next;
                        free(prev->next);
                        prev->next = aux;
                }
        }

        printf("Nucleobase removed from position %d of stretch.\n", pos);
        return list;
}

/* Inverts de n first nucleobases of a list */
ptr_node prefix_inversion(ptr_node list, int len)
{
        int i;
        ptr_node next, aux = list;

        if (len > list_len(list)) {
                printf("Error! given prefix length > list length.\n");
                return list;
        }

        for (i = 0; i < len; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }

        printf("- ");

        if (len > 1) {
                next = list->next;
                list->next = aux;

                for (i = 0; i < len - 1; i++) {
                        aux = next->next;
                        next->next = list;
                        list = next;
                        next = aux;
                }
        }

        aux = list;

        for (i = 0; i < len; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }

        printf("\n");
        return list;
}

/* Inverts de n last nucleobases of a list */
ptr_node suffix_inversion(ptr_node list, int len)
{
        int i;
        int llen = list_len(list);
        ptr_node curr, next, aux, prev = list;

        if (len > llen) {
                printf("Error! given suffix length > list length.\n");
                return list;
        }

        if (llen - len) {
                for (i = 0; i < llen - len - 1; i++)
                        prev = prev->next;

                aux = prev->next;
        } else {
                aux = list;
        }

        for (i = 0; i < len; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }

        printf("- ");
        aux = prev->next;

        if (len > 1) {

                if (llen == len)
                        curr = list;
                else
                        curr = aux;

                next = curr->next;
                curr->next = NULL;

                for (i = 0; i < len - 1; i++) {
                        aux = next->next;
                        next->next = curr;
                        curr = next;
                        next = aux;
                }

                if (llen == len)
                        list = curr;
                else
                        prev->next = curr;

                aux = curr;
        }

        for (i = 0; i < len; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }

        printf("\n");
        return list;
}

ptr_node transpose_dna(ptr_node list, int p, int q, int r)
{
        int i;
        ptr_node first, last, prev, next, aux = list;

        if (p > q) {
                printf("p must be greater than q.\n");
                return list;
        }

        if ((q - p) > list_len(list)) {
                printf("Error! stretch > list leng.\n");
                return list;
        }

        if ((2*q - p + r) > list_len(list) || (p + r) < 0) {
                printf("Error! stretch shift is out of list.\n");
                return list;
        }

        for (i = 0; i < p - 1; i++)
                aux = aux->next;

        i++;
        prev = aux;
        aux = aux->next;
        first = aux;

        for (;i < q; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }
        printf("%c ", aux->data);

        last = aux;

        if (r >= 0) {
                printf("> ");

                for (i = 0; i < r; i++)
                        aux = aux->next;

                next = aux;
                prev->next = last->next;
                last->next = next->next;
                next->next = first;

        } else {
                printf("< ");
        }

        printf("%d \n", abs(r));
        return list;
}

void print_list(ptr_node list)
{
        ptr_node aux;

        if (!list) {
                printf("Empty list.\n");
                return;
        }

        for (aux = list; aux; aux = aux->next)
                printf("%c ", aux->data);

        printf("\n");
        return;
}

/* Free all allocated memory */
void free_list(ptr_node list)
{
        if (!list)
                return;

        if (list->next) {
                free_list(list->next);
        }

        free(list);
        return;
}

static int list_len(ptr_node list)
{
        int len = 0;
        ptr_node aux = list;

        /* while aux != NULL keep accessing the next list and increases len counter */
        while (aux) {
                len += 1;
                aux = aux->next;
        }

        return len;
}
