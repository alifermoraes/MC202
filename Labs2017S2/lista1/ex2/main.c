#include <stdio.h>
#include <stdlib.h>
#include "derivative.h"

int main(int argc, char *argv[])
{
        int i;
        ptr_node aux, polynomial;

        polynomial = create_polynomial(argc, argv);
        aux = polynomial;

        printf("f(x) = ");
        print_polynomial(polynomial);

        for (i = 1; i < argc - 1; i++) {
                polynomial = derivative(polynomial);
                printf("%d derivative of f(x) = ", i);
                print_polynomial(polynomial);
        }

        free(aux);

        return EXIT_SUCCESS;
}
