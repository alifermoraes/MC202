#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#define ADDICTION       1
#define SUBTRACTION     2
#define MULTIPLICATION  3
#define DIVISION        4
#define SIMPLIFY        5
#define COMPARE         6
#define FINISH          0

typedef struct {
        int num;
        int den;
} rational;

void get_val(int *val);
rational scan_rational(void);
void print_rational(rational r);
rational add_rational(rational r1, rational r2);
rational sub_rational(rational r1, rational r2);
rational mult_rational(rational r1, rational r2);
rational div_rational(rational r1, rational r2);
rational simp_rational(rational r);
int cmp_rational(rational r1, rational r2);

#endif  /* _RATIONAL_H_DEFINED_ */
