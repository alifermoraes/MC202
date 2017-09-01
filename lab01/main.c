#include "rational.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
        unsigned short op;
        int res_cmp;
        rational r1, r2, res;

        do {
                op = (unsigned short)get_val();

                switch (op) {
                        case ADDICTION:
                                r1 = scan_rational();
                                r2 = scan_rational();
                                res = add_rational(r1, r2);
                                print_rational(res);
                                break;

                        case SUBTRACTION:
                                r1 = scan_rational();
                                r2 = scan_rational();
                                res = sub_rational(r1, r2);
                                print_rational(res);
                                break;

                        case MULTIPLICATION:
                                r1 = scan_rational();
                                r2 = scan_rational();
                                res = mult_rational(r1, r2);
                                print_rational(res);
                                break;

                        case DIVISION:
                                r1 = scan_rational();
                                r2 = scan_rational();
                                res = div_rational(r1, r2);
                                print_rational(res);
                                break;

                        case SIMPLIFY:
                                r1 = scan_rational();
                                res = simp_rational(r1);
                                print_rational(res);
                                break;

                        case COMPARE:
                                r1 = scan_rational();
                                r2 = scan_rational();
                                res_cmp = cmp_rational(r1, r2);
                                printf("%d\n", res_cmp);
                                break;

                        case FINISH:
                                break;

                        default:
                                printf("Invalid operation\n");
                }
        } while (op != FINISH);

        printf("Finished\n");
        return EXIT_SUCCESS;
}
