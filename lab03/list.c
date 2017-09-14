#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static int sequence_len(ptr_node list);

ptr_node create_empty_list(void)
{
        return NULL;
}

/* Inserts a given nucleobase in a given position of a list */
ptr_node insert_nucleobase(ptr_node list, char data, int pos)
{
        int i;
        ptr_node new, prev = list;

        if (pos > sequence_len(list)) {
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

        printf("Nucleobase added in position %d of sequence.\n", pos);
        return list;
}

/* removes a nucleobase on a given position of a list */
ptr_node remove_nucleobase(ptr_node list, int pos)
{
        int i;
        ptr_node aux, prev = list;

        if (pos >= sequence_len(list)) {
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

        printf("Nucleobase removed from position %d of sequence.\n", pos);
        return list;
}

/* Inverts de n first nucleobases of a list */
ptr_node prefix_inversion(ptr_node list, int len)
{
        int i;
        ptr_node next, aux = list;

        if (len > sequence_len(list)) {
                printf("Error! given prefix length is greater than sequence length.\n");
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
        int llen = sequence_len(list);
        ptr_node curr, next, aux, prev = list;

        if (len > llen) {
                printf("Error! given suffix length is greater than sequence length.\n");
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
        ptr_node first, last, aux, prev = list;

        if (p > q) {
                printf("p must be greater than q.\n");
                return list;
        }

        if ((q - p) > sequence_len(list)) {
                printf("Error! given sequence range is greater than sequence length.\n");
                return list;
        }

        if (r && ((2*q - p + r - 1) > sequence_len(list) || (p + r) < 0)) {
                printf("Error! sequence shift is out of list range.\n");
                return list;
        }

        for (i = 0; i < p - 1; i++)
                prev = prev->next;

        i++;

        if (p)
                first = prev->next;
        else
                first = prev;

        for (aux = first; i < q; i++) {
                printf("%c ", aux->data);
                aux = aux->next;
        }

        printf("%c ", aux->data);
        last = aux;

        if (r > 0) {

                if (r) {
                        for (i = 0; i < r; i++)
                                aux = aux->next;

                        if (p)
                                prev->next = last->next;
                        else
                                list = last->next;

                        last->next = aux->next;
                        aux->next = first;
                }

		printf("> ");

        } else {
                aux = list;

                for (i = 1; i < p + r; i++)
                        aux = aux->next;

                if (p + r) {
                        prev->next = last->next;
                        last->next = aux->next;
                        aux->next = first;
                } else {
                        list = first;
                        prev->next = last->next;
                        last->next = aux;
                }

                printf("< ");
        }

        printf("%d \n", abs(r));
        return list;
}

/* prints every elements in the list */
void print_sequence(ptr_node list)
{
        ptr_node aux;

        if (!list) {
                printf("Empty sequence.\n");
                return;
        }

        for (aux = list; aux; aux = aux->next)
                printf("%c ", aux->data);

        printf("\n");
        return;
}

/* Free all allocated memory */
void free_sequence(ptr_node list)
{
        if (!list)
                return;

        if (list->next) {
                free_sequence(list->next);
        }

        free(list);
        return;
}

static int sequence_len(ptr_node list)
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
