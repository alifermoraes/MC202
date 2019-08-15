#ifndef         _ARRAY_H_
#define         _ARRAY_H_

#define MAXIMUM                 41
#define BOOK_INSERTION          1
#define BOOK                    1
#define UNIVERSITY_INSERTION    2
#define UNIVERSITY              2
#define ORDER                   3
#define BOOK_PER_UNIVERSITY     4
#define UNIVERSITY_PER_BOOK     5
#define TOTAL_BOOKS             6
#define EXIT                    0

typedef struct {
        char **books;
        int b_index;
        int b_len;
        char **universities;
        int u_index;
        int u_len;
} Register;

typedef Register * ptr_reg;

ptr_reg init_reg(void);
void reg_insertion(ptr_reg reg, unsigned short option);
int reg_search(ptr_reg, unsigned short option, char name[]);
void free_reg(ptr_reg reg);

#endif          /* _ARRAY_H_DEFINED_ */
