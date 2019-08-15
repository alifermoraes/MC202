#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main(void)
{
        unsigned short option;
        ptr_node proc_list;

        proc_list = create_proc_list();

        do {
                scanf("%hd", &option);

                switch (option) {
                case INSERT_PROCESS:
                        proc_list = insert_proc(proc_list);
                        break;

                case REMOVE_PROCESS:
                        proc_list = remove_proc(proc_list);
                        break;

                case PRINT_PROCESS:
                        print_proc_list(proc_list);
                        break;

                case PRIORITIZE_PROCESS:
                        proc_list = prioritize_proc(proc_list);
                        break;

                case EXECUTE_PROCESS:
                        proc_list = execute_proc(proc_list);
                        if (proc_list)
                                print_proc_list(proc_list);
                        else
                                printf("All processes has been finished.\n");
                        break;

                case EXIT:
                        free_proc_list(proc_list);
                        printf("System finished.\n");
                        break;

                default:
                        printf("Invalid option.\n");
                        break;
                }

        } while (option != EXIT);

        return EXIT_SUCCESS;
}
