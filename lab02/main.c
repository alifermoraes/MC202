#include "array.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
        unsigned short op;
        ptr_reg reg;
        ptr_mat mat;

        reg = init_reg();
        mat = init_mat();

        do {
                scanf("%hd", &op);

                switch (op) {
                case BOOK_INSERTION:
                        reg_insertion(reg, BOOK);
                        mat_insertion(mat, BOOK);
                        printf("The book has been successfully registered!\n");
                        break;

                case UNIVERSITY_INSERTION:
                        reg_insertion(reg, UNIVERSITY);
                        mat_insertion(mat, UNIVERSITY);
                        printf("The university has been successfully registered!\n");
                        break;

                case ORDER:
                        order(mat, reg);
                        printf("Your order has been successfully registered!\n");
                        break;

                case BOOK_PER_UNIVERSITY:
                        printf("%d\n", order_report(mat, reg, UNIVERSITY));
                        break;

                case UNIVERSITY_PER_BOOK:
                        printf("%d\n", order_report(mat, reg, BOOK));
                        break;

                case TOTAL_BOOKS:
                        printf("%d\n", total_books(mat));
                        break;

                case EXIT:
                        free_mat(mat);
                        free_reg(reg);
                        printf("System finished.\n");
                        break;

                default:
                        printf("Invalid operation.\n");
                        break;

                }

        } while (op != EXIT);

        return EXIT_SUCCESS;
}
