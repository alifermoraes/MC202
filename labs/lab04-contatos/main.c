/**
 * MC202B - Estrutura de Dados
 * 
 * Nome: Alifer Willians de Moraes
 * RA: 165334
 * 
 * Trabalho: 04-contatos
 * 
 * Contatos
 * Este trabalho consiste em fazer um programa que manipule uma coleção de contatos. Seu programa
 * deve ser capaz de organizar até 1.000 contatos. O programa deve ser capaz de inserir registros
 * remover registros, recuperar registros e imprimir todos os registros da coleção. A entrada
 * consiste de um caractere que especifica a operação, seguido de linhas de acordo com cada
 * operação, que pode ser:
 * - i para inserção. As quatro linhas seguintes conterão nome, endereço, telefone e data de
 * aniversário. O nome tem até 50 caracteres, o endereço até 100, o telefone até 12 dígitos e a
 * data de aniversário tem o formato dd/mm/aa.
 * - r para remoção. A linha seguinte tem uma cadeia de caracteres representando um nome. Seu
 * programa deve remover todos os registros que tenham nome exatamente igual ao digitado. O
 * programa deve imprimir o número de registros removidos.
 * - b para busca. A linha seguinte tem uma cadeia de caracteres representando um nome. Seu
 * programa deve imprimir todos os registros que tenham nome contendo alguma parte que é igual ao
 * nome digitado, na ordem em que foram inseridos.
 * - p para impressão. Seu programa deve imprimir todos os registros na agenda, na ordem em que
 * foram inseridos.
 * - f para finalizar o programa.
 */

#include <stdio.h>
#include <string.h>

#define ADD_CONTACT     105 /* caractere i equivale a 105 em decimal */
#define REMOVE_CONTACT  114 /* caractere r equivale a 114 em decimal */
#define SEARCH_CONTACT   98 /* caractere b equivale a 98 em decimal */
#define PRINT_CONTACTS  112 /* caractere p equivale a 112 em decimal */
#define FINISH          102 /* caractere f equivale a 102 em decimal */

typedef struct {
    char name[51];
    char address[101];
    char phone[13];
    char birthday[9];
} Contact;

void add_contact(Contact *list);
int remove_contact(Contact *list, int elements);
void search_contact(Contact *list, int elements);
void print_contacts(Contact *list, int elements);

int main(void) {
    Contact contacts_list[1000];
    int contacts = 0;
    char option;

    do {
        scanf("%c ", &option);

        switch (option) {
        case ADD_CONTACT:
            if (contacts < 1000) {
                add_contact(&contacts_list[contacts]);
                contacts++;
            }
            break;
        case REMOVE_CONTACT:
            contacts -= remove_contact(contacts_list, contacts);
            break;
        case SEARCH_CONTACT:
            search_contact(contacts_list, contacts);
            break;
        case PRINT_CONTACTS:
            print_contacts(contacts_list, contacts);
            break;
        default:
            break;
        }

    } while (option != FINISH);

    return 0;
}

void add_contact(Contact *list) {
    scanf("%[^\n] %[^\n] %[^\n] %[^\n] ", list->name, list->address, list->phone, list->birthday);
    printf("Contato para %s inserido.\n\n", list->name);
}

int remove_contact(Contact *list, int elements) {
    int i, j;
    int removed = 0;
    char name[51];

    scanf("%s ", name);

    for (i = 0; i < elements - removed; i++) {
        if (!strcmp(list[i].name, name)) {
            removed++;
            for (j = i; j < elements - 1; j++) {
                list[j] = list[j + 1];
            }

            i--;
        }
    }

    printf("Contatos de %s removidos: %d.\n\n", name, removed);

    return removed;
}

void search_contact(Contact *list, int elements) {
    int i;
    char name[51];
    char *found = NULL;

    scanf("%s ", name);
    printf("Resultado da busca:\n");

    for (i = 0; i < elements; i++) {
        found = strstr(list[i].name, name);
        if (found) {
            printf("(%d) %s\t%s\t%s\t%s\n\n",
                    (i + 1), list[i].name, list[i].address, list[i].phone, list[i].birthday);
        }
    }

    if (!found) {
        printf("Nenhum contato.\n\n");
    }
}

void print_contacts(Contact *list, int elements) {
    int i;

    printf("Listagem:\n");

    if (!elements) {
        printf("Nenhum contato.\n");
    } else {
        for(i = 0; i < elements; i++) {
            printf("(%d) %s\t%s\t%s\t%s\n",
                    (i + 1), list[i].name, list[i].address, list[i].phone, list[i].birthday);
        }
    }

    printf("\n");
}
