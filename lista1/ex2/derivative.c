#include <stdio.h>
#include <stdlib.h>
#include "derivative.h"

ptr_node create_polynomial(int argc, char *argv[])
{
        int i;
        int n_const = 0;
        int *v1, *v2;
        ptr_node polynomial = NULL;

        v1 = malloc(argc * sizeof(int));
        v2 = malloc(argc * sizeof(int));
        
        if (!v1 || !v2) {
                printf("function create_polynomial has failed! Out of memory.\n");
                exit(EXIT_FAILURE);
        }

        for (i = 1; i < argc; i++)
                if (atoi(argv[i])) {
                        v1[n_const] = atoi(argv[i]);
                        v2[n_const++] = argc - i - 1;
                }

        if (n_const) {
                polynomial = malloc(n_const * sizeof(Node));
                
                if (!polynomial) {               
                        printf("function create_polynomial has failed! Out of memory.\n");
                        exit(EXIT_FAILURE);
                }

                for (i = 0; i < n_const - 1; i++) {
                        polynomial[i].constant = v1[i];
                        polynomial[i].coefficient = v2[i];
                        polynomial[i].next = &polynomial[i + 1];
                }

                polynomial[i].constant = v1[i];
                polynomial[i].coefficient = v2[i];
                polynomial[i].next = NULL;
        }

        free(v1);
        free(v2);

        return polynomial;
}

ptr_node derivative(ptr_node polynomial)
{
        if (!polynomial)
                return polynomial;

        if (!polynomial->coefficient) {
                return polynomial->next;
        }

        polynomial->next = derivative(polynomial->next);
        polynomial->constant *= polynomial->coefficient--;

        return polynomial;
}

void print_polynomial(ptr_node polynomial)
{
        ptr_node aux = polynomial;

        if (aux) {
                while(aux->next) {
                        if (aux->coefficient > 1)
                                printf("%dx^%d + ", aux->constant, aux->coefficient);
                        else if (aux->coefficient == 1)
                                printf("%dx + ", aux->constant);

                        aux = aux->next;
                }

                if (aux->coefficient > 1)
                        printf("%dx^%d\n", aux->constant, aux->coefficient);
                else if (aux->coefficient == 1)
                        printf("%dx\n", aux->constant);
                else
                        printf("%d\n", aux->constant);

        } else {
                printf("\n");
        }

        return;
}
