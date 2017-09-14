#include "array.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* initializes a new Register */
ptr_reg init_reg(void)
{
        ptr_reg reg;

        reg = malloc(sizeof(Register));
        reg->books = malloc(sizeof(char *));
        reg->books[0] = malloc(sizeof(char[MAXIMUM]));
        reg->b_index = 0;
        reg->b_len = 1;
        reg->universities = malloc(sizeof(char *));
        reg->universities[0] = malloc(sizeof(char[MAXIMUM]));
        reg->u_index = 0;
        reg->u_len = 1;

        if (!reg->books || !reg->books[0] || !reg->universities || !reg->universities[0]) {
                printf("Function init_array() has failed! Out of memory.\n");
                exit(EXIT_FAILURE);
        }

        return reg;
}

/* insert a new book or university in the Register, if allocated memory isn't enough, its size get doubled */
void reg_insertion(ptr_reg reg, unsigned short option)
{
        int i;
        char ** tmp;

        switch (option) {
        case BOOK:
                if (reg->b_index < reg->b_len) {
                        scanf("%s", reg->books[reg->b_index]);
                        reg->b_index++;
                } else {
                        tmp = reg->books;
                        reg->b_len *= 2;
                        reg->books = malloc(reg->b_len * sizeof(char *));

                        if (!reg->books) {
                                printf("Function reg_insertion has failed! Out of memory.\n");
                                exit(EXIT_FAILURE);
                        }

                        for (i = 0; i < reg->b_len; i++) {
                                reg->books[i] = malloc(sizeof(char[MAXIMUM]));

                                if (!reg->books[i]) {
                                        printf("Function reg_insertion has failed! Out of memory.\n");
                                        exit(EXIT_FAILURE);
                                }

                                if (i < reg->b_index)
                                        strcpy(reg->books[i], tmp[i]);
                        }

                        scanf("%s", reg->books[reg->b_index]);
                        reg->b_index++;

                        for (i = 0; i < (reg->b_len/2); i++)
                                free(tmp[i]);

                        free(tmp);
                }
                break;

        case UNIVERSITY:
                if (reg->u_index < reg->u_len) {
                        scanf("%s", reg->universities[reg->u_index]);
                        reg->u_index++;
                } else {
                        tmp = reg->universities;
                        reg->u_len *= 2;
                        reg->universities = malloc(reg->u_len * sizeof(char *));

                        if (!reg->universities) {
                                printf("Function reg_insertion has failed! Out of memory.\n");
                                exit(EXIT_FAILURE);
                        }

                        for (i = 0; i < reg->u_len; i++) {
                                reg->universities[i] = malloc(sizeof(char[MAXIMUM]));

                                if (i < reg->u_index)
                                        strcpy(reg->universities[i], tmp[i]);

                                if (!reg->universities[i]) {
                                        printf("Function reg_insertion has failed! Out of memory.\n");
                                        exit(EXIT_FAILURE);
                                }
                        }

                        scanf("%s", reg->universities[reg->u_index]);
                        reg->u_index++;

                        for (i = 0; i < (reg->u_len/2); i++)
                                free(tmp[i]);

                        free(tmp);
                }
                break;
        }

    return;
}

/* search a given name in the Register then return its index */
int reg_search(ptr_reg reg, unsigned short option, char name[])
{
        int i = 0;

        switch (option) {
        case BOOK:
                while(strcmp(reg->books[i], name))
                        i++;
                break;

        case UNIVERSITY:
                while (strcmp(reg->universities[i], name))
                        i++;
                break;
        }

        return i;
}

/* free the allocated memory in Register */
void free_reg(ptr_reg reg)
{
        int i;

        for (i = 0; i < reg->b_len; i++)
                free(reg->books[i]);

        for (i = 0; i < reg->u_len; i++)
                free (reg->universities[i]);

        free(reg->books);
        free(reg->universities);
        free(reg);

        return;
}
