#ifndef         _MATRIX_H_
#define         _MATRIX_H_

typedef struct {
    int **m;
    int row_index;
    int col_index;
    int row_len;
    int col_len;
} Matrix;

typedef Matrix * ptr_mat;

ptr_mat init_mat(void);
void mat_insertion(ptr_mat mat, unsigned short option);
void order(ptr_mat mat, ptr_reg reg);
int order_report(ptr_mat mat, ptr_reg reg, unsigned short option);
int total_books(ptr_mat mat);
void free_mat(ptr_mat mat);

#endif          /* _MATRIX_H_DEFINED_ */
