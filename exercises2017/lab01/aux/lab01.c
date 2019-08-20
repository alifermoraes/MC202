#include "racionais.h"
#include <stdio.h>

int main (int argc, char* argv[]) {
  int escolha, res_cmp;
  racional r1,r2,res;
  do {
    scanf("%d",&escolha);
    switch (escolha) {
      case 1: {
                r1 = racional_le();
                r2 = racional_le();
                res = racional_adiciona(r1,r2);
                racional_imprime(res);
                break;
              }
      case 2: {
                r1 = racional_le();
                r2 = racional_le();
                res = racional_subtrai(r1,r2);
                racional_imprime(res);
                break;
              }
      case 3: {
                r1 = racional_le();
                r2 = racional_le();
                res = racional_multiplica(r1,r2);
                racional_imprime(res);
                break;
              }
      case 4: {
                r1 = racional_le();
                r2 = racional_le();
                res = racional_divide(r1,r2);
                racional_imprime(res);
                break;
              }
      case 5: {
                r1 = racional_le();
                res = racional_simplifica(r1);
                racional_imprime(res);
                break;
              }
      case 6: {
                r1 = racional_le();
                r2 = racional_le();
                res_cmp = racional_compara(r1,r2);
                printf("%d\n", res_cmp);
                break;
              }
    }
  } while (escolha != 0);
  printf("Sistema encerrado.\n");
  return 0;
}
