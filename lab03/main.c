#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
        unsigned short option;
        int pos, len, p, q, r;
        char data;
        ptr_node list;

        list = create_empty_list();

        do {
                scanf("%hd", &option);

                switch (option) {
                case INSERT_NB:
                        scanf(" %c", &data);
                        scanf("%d", &pos);
                        list = insert_nucleobase(list, data, pos);
                        break;

                case REMOVE_NB:
                        scanf("%d", &pos);
                        list = remove_nucleobase(list, pos);
                        break;

                case PREFIX_INVERSION:
                        scanf("%d", &len);
                        list = prefix_inversion(list, len);
                        break;

                case SUFFIX_INVERSION:
                        scanf("%d", &len);
                        list = suffix_inversion(list, len);
                        break;

                case TRANSPOSE_DNA:
                        scanf("%d %d %d", &p, &q, &r);
                        list = transpose_dna(list, p, q, r);
                        break;

                case PRINT_DNA:
                        print_list(list);
                        break;

                case EXIT:
                        printf("System finished.\n");
                        free_list(list);
                        break;

                default:
                        break;
                }
        } while (option != EXIT);

        return EXIT_SUCCESS;
}
