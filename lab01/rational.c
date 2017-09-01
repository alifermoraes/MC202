#include "rational.h"
#include <stdio.h>
#include <stdlib.h>

static int gcd(int a, int b);

void get_val(int *val) {
	char *pointer, string[1000];

	do {
                fgets(string, sizeof(string), stdin);
                *val = strtol(string, &pointer, 10);
        } while ((pointer == string || *pointer != '\n'));
}

rational scan_rational() {
        rational r;

        get_val(&r.num);
	get_val(&r.den);
        while (r.den == 0) {
                printf("Please, enter a new value for the denominator\n");
                get_val(&r.den);
        }

        return r;
}

void print_rational(rational r) {
        printf("%d/%d\n", r.num, r.den);

        return;
}

rational add_rational(rational r1, rational r2) {
        rational r;

        r.num = (r1.num * r2.den) + (r2.num * r1.den);
        r.den = r1.den * r2.den;
        r = simp_rational(r);

        return r;
}

rational sub_rational(rational r1, rational r2) {
        rational r;

        r.num = (r1.num * r2.den) - (r2.num * r1.den);
        r.den = r1.den * r2.den;
        r = simp_rational(r);

        return r;
}

rational mult_rational(rational r1, rational r2) {
        rational r;

        r.num = r1.num * r2.num;
        r.den = r1.den * r2.den;
        r = simp_rational(r);

        return r;
}

rational div_rational(rational r1, rational r2) {
        rational r;

        r.num = r1.num * r2.den;
        r.den = r1.den * r2.num;
        r = simp_rational(r);

        return r;
}

rational simp_rational(rational r) {
        int f = gcd(r.num, r.den);

        if (r.num == r.den) {
                r.num = 1;
                r.den = 1;
        } else if (r.den < 0) {
                r.num /= -f;
                r.den /= -f;
        } else {
                r.num /= f;
                r.den /= f;
        }

        return r;
}

int cmp_rational(rational r1, rational r2) {
        rational r;

        r = sub_rational(r1, r2);

        if (r.num > 0)
                return 1;
        else if (r.num < 0)
                return -1;
        else
                return 0;
}

/* calculates the greatest common divisor */
static int gcd(int a, int b) {
        if (b == 0)
                return abs(a);
        else
                return gcd(b, a%b);
}
