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
                case INSERT_NB: /* #1 */
                        scanf(" %c", &data);
                        scanf("%d", &pos);
                        list = insert_nucleobase(list, data, pos);
                        break;

                case REMOVE_NB: /* #2 */
                        scanf("%d", &pos);
                        list = remove_nucleobase(list, pos);
                        break;

                case PREFIX_INVERSION: /* #3 */
                        scanf("%d", &len);
                        list = prefix_inversion(list, len);
                        break;

                case SUFFIX_INVERSION: /* #4 */
                        scanf("%d", &len);
                        list = suffix_inversion(list, len);
                        break;

                case TRANSPOSE_DNA: /* #5 */
                        scanf("%d %d %d", &p, &q, &r);
                        list = transpose_dna(list, p, q, r);
                        break;

                case PRINT_DNA: /* #6 */
                        print_sequence(list);
                        break;

                case EXIT: /* #0 */
                        printf("System finished.\n");
                        free_sequence(list);
                        break;

                default:
                        printf("Invalid option.\n");
                        break;
                }

        } while (option != EXIT);

        return EXIT_SUCCESS;
}
