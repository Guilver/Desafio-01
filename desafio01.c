// Vinicius Peixoto Chagas.
// Matricula 20212045050533
// Desafio 01 Labotatorio de programação
// Controle de ocupação de armarios com variavel binaria

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned char armario = 0b00000000; // controle dos armarios

int testeporta(int porta) { // identifica se está ocupado
  return (armario & (1 << porta));
}

int main(void) {
  unsigned char menu = '0'; // controle do menu
  int rng;                  // numero aleatorio
  int des;                  // armario para descoupar
  int quant;                // quantidade de armarios ocupados
  do {
    // Menu
    quant = 0; // Testa a quantidade de armarios ocupados
    for (int i = 0; i < 8; i++) {
      if (testeporta(i) == (1 << i)) {
        printf("[%d] [ OCUPADA ]\n", i + 1);
        quant++;
      } else
        printf("[%d] [ DESOCUPADA ]\n", i + 1);
    }
    printf("\nEscolha uma ação. (1) Ocupar armário. (2) Liberar armário. (3) "
           "Sair.\n");
    scanf(" %c", &menu);

    if (menu != '1' && menu != '2' && menu != '3') {
      printf("Opção invalida\n");
      menu = '0';
    }

    // Ocupar Armário
    if (menu == '1' && quant < 8) {
      srand(time(NULL));
      rng = (rand() % 8);
      do {
        if (testeporta(rng) != (1 << rng)) {
          printf("\n Ocupando armario %d\n\n", rng + 1);
          armario = armario + (1 << rng);
          rng = 8;
        } else if (rng == 7) {
          rng = 0;
        } else {
          rng++;
        }
      } while (rng < 8);
    }
    if (menu == '1' && quant == 8) {
      printf("\nTodos os armarios estão ocupados\n\n");
    }

    // Desocupar Armário
    if (menu == '2') {
      do {
        printf("\nEscolha o numero do armario para desocupar:\n");
        scanf("%d", &des);
        if (des <= 0 || des > 8)
          printf("\nArmario invalido\n\n");
      } while (des <= 0 || des > 8);
      if (testeporta(des - 1) == (1 << (des - 1))) {
        printf("\nDesocupando armario %d\n\n", des);
        armario = armario - (1 << (des - 1));
      } else
        printf("\nO armario já esta desocupado\n\n");
    }

    // Sair do programa
  } while (menu != '3');
  printf("\n\nPrograma finalizado\n");
  return 0;
}