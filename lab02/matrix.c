#include "array.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* initializes a new Matrix */
ptr_mat init_mat(void)
{
        ptr_mat mat;

        mat = malloc(sizeof(Matrix));
        mat->m = malloc(sizeof(int*));
        mat->m[0] = malloc(sizeof(int));
        mat->row_index = 0;
        mat->row_len = 1;
        mat->col_index = 0;
        mat->col_len = 1;

        if (!mat || !mat->m || !mat->m[0]) {
                printf("init_mat() function has failed! Out of memory\n");
                exit(EXIT_FAILURE);
        }

        return mat;
}

/* insert a new row or column, if allocated memory isn't enough its size gets doubled */
void mat_insertion(ptr_mat mat, unsigned short option)
{
        int i, j;
        int old_len;
        int **tmp_row;
        int *tmp_col;

        switch (option) {

        case BOOK:
                if (mat->row_index < mat->row_len) {
                        for (i = 0; i < mat->col_len; i++)
                                mat->m[mat->row_index][i] = 0;

                        mat->row_index++;
                } else {
                        tmp_row = mat->m;
                        old_len = mat->row_len;
                        mat->row_len *= 2;
                        mat->m = malloc(mat->row_len * (sizeof(int*)));

                        if (!mat->m) {
                                printf("mat_insertion() function has failed! Out of memory\n");
                                exit(EXIT_FAILURE);
                        }

                        for (i = 0; i < mat->row_len; i++) {
                                mat->m[i] = malloc(mat->col_len * sizeof(int));

                                if (!mat->m[i]) {
                                        printf("mat_insertion() function has failed! Out of memory\n");
                                        exit(EXIT_FAILURE);
                                }

                                if (i < mat->row_index) {
                                        for (j = 0; j < mat->col_index; j++)
                                                mat->m[i][j] = tmp_row[i][j];
                                }

                                if (i < old_len)
                                        free(tmp_row[i]);
                        }

                        free(tmp_row);

                        for (i = 0; i < mat->col_len; i++)
                            mat->m[mat->row_index][i] = 0;

                        mat->row_index++;
                }
                break;

        case UNIVERSITY:
                if (mat->col_index < mat->col_len) {
                        for (i = 0; i < mat->row_index; i++)
                                mat->m[i][mat->col_index] = 0;

                        mat->col_index++;
                } else {
                        old_len = mat->col_len;
                        mat->col_len *= 2;

                        for (i = 0; i < mat->row_len; i++) {
                                tmp_col = mat->m[i];
                                mat->m[i] = malloc(mat->col_len * (sizeof(int)));

                                if (!mat->m[i]) {
                                        printf("mat_insertion() function has failed! Out of memory\n");
                                        exit(EXIT_FAILURE);
                                }

                                for (j = 0; j < old_len; j++)
                                        mat->m[i][j] = tmp_col[j];

                                free(tmp_col);
                        }

                        for (i = 0; i < mat->row_index; i++)
                                mat->m[i][mat->col_index] = 0;

                        mat->col_index++;
                }
                break;
        }

        return;
}

/* adds a given number of books in a given university */
void order(ptr_mat mat, ptr_reg reg)
{
        int i;
        int b_id, u_id;
        int orders, b_amount;
        char b_name[MAXIMUM], u_name[MAXIMUM];

        scanf("%s %d", u_name, &orders);
        u_id = reg_search(reg, UNIVERSITY, u_name);

        for (i = 0; i < orders; i++) {
                scanf("%s %d", b_name, &b_amount);
                b_id = reg_search(reg, BOOK, b_name);
                mat->m[b_id][u_id] += b_amount;
        }

        return;
}

/* calculates how many books were ordered by a given university
   or how many universities has ordered a given book */
int order_report(ptr_mat mat, ptr_reg reg, unsigned short option)
{
        int i;
        int id, res = 0;
        char name[MAXIMUM];

        scanf("%s", name);
        id = reg_search(reg, option, name);

        switch (option) {
        case BOOK:
                for (i = 0; i < mat->col_index; i++)
                res += mat->m[id][i];
                break;

        case UNIVERSITY:
                for (i = 0; i < mat->row_index; i++)
                        res += mat->m[i][id];
                break;
        }

        return res;
}

/* calculates the amount of books ordered by universities */
int total_books(ptr_mat mat)
{
        int i, j;
        int res = 0;

        for (i = 0; i < mat->row_index; i++)
                for (j = 0; j < mat->col_index; j++)
                        res += mat->m[i][j];

        return res;
}

/* free allocated memory in Matrix */
void free_mat(ptr_mat mat)
{
        int i;

        for (i = 0; i < mat->row_len; i++)
                free(mat->m[i]);

        free(mat->m);
        free(mat);

        return;
}
