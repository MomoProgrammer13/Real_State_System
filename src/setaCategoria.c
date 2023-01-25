/*
 *Esta função garante que seja digitado o valor zero (a imobiliaria não tem esta categoria de carro) ou o valor 1 (a imobiliaria tem esta categoria de carro). Esta função é utilizada no cadastramento e alteração de imobiliarias.
 */
#include<stdio.h>
#include "libImobiliarias.h"
int setaCategoria(char categoria[]){
  int set;
  do{
      printf("\n %s (0/1): ", categoria);
      scanf("%d", &set);
   }while (set != 0 && set != 1);

   return set;
}
